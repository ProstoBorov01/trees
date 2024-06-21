#pragma once
#include <iomanip>
#include <sstream>
#include <valarray>

template<typename T>
concept Numeric = std::is_integral_v<T> or std::is_floating_point_v<T>;

template<typename Value>
bool compareValues(const Value &newOperand, const Value currentOperand) {
    return newOperand < currentOperand;
}

template<Numeric Key, typename Value>
class TreeNode final {
private:
    TreeNode<Key, Value> *left{};
    TreeNode<Key, Value> *right{};
    Key key{};
    Value value{};
public:

    explicit TreeNode(const Key &key, const Value &value,
                      TreeNode<Key, Value> *left = nullptr, TreeNode<Key, Value> *right = nullptr) {
        this -> key = key;
        this -> value = value;
        this -> left = left;
        this -> right = right;
    }

    ~TreeNode() {
        destroy(left);
        destroy(right);
    };

    void destroy(TreeNode<Key, Value> *node) {
        if (node) {
            destroy(node -> getLeftNode());
            destroy(node -> getRightNode());
            delete node;
        }
    }

    Value &getValue();
    Key &getKey();
    TreeNode<Key, Value> *setLeftNode(TreeNode<Key, Value> *node);
    TreeNode<Key, Value> *setRightNode(TreeNode<Key, Value> *node);
    TreeNode<Key, Value> *getLeftNode() const;
    TreeNode<Key, Value> *getRightNode() const;
    void deleteTreeNode(TreeNode<Key, Value> *object);
    bool findKey(const TreeNode<Key, Value> *currentNode, const Key &searchingKey) const;
};

template<Numeric Key, typename Value>
Value &TreeNode<Key, Value>::getValue() {
    return this -> value;
}

template<Numeric Key, typename Value>
Key &TreeNode<Key, Value>::getKey() {
    return this -> key;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::setLeftNode(TreeNode<Key, Value> *node) {
    left = node;
    return this ;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::setRightNode(TreeNode<Key, Value> *node) {
    right = node;
    return nullptr;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::getLeftNode() const {
    return this -> left;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::getRightNode() const {
    return this -> right;
}

template<Numeric Key, typename Value>
void TreeNode<Key, Value>::deleteTreeNode(TreeNode<Key, Value> *object) {
    delete object;
}

template<Numeric Key, typename Value>
bool TreeNode<Key, Value>::findKey(const TreeNode<Key, Value> *currentNode, const Key &searchingKey) const {
    return currentNode -> getKey() == searchingKey;
}

// ==================================================================================================== //

template<Numeric Key, typename Value>
class BinarySearchTree {
private:
    TreeNode<Key, Value> *root;



    TreeNode<Key, Value> *getRoot() const {
        return this -> root;
    };


    void addToSum(Value &item, int &sum) {
        sum += item;
    }

    template<typename ... Types>
    void inOrderHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
        if (node) {
            inOrderHelper(node -> getLeftNode(), visit, contextArgs ...);
            visit(node -> getValue(), contextArgs ...);
            inOrderHelper(node -> getRightNode(), visit, contextArgs ...);
        }
    } // как бы с помощью обхода посчитать сумму

    template<typename ... Types>
    void postOrderHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
        if (node) {
            postOrderHelper(node -> getLeftNode(), visit, contextArgs ...);
            postOrderHelper(node -> getRightNode(), visit, contextArgs ...);
            visit(node -> getValue(), contextArgs ...);
        }
    }

    template<typename ... Types>
    void preOrderHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
        if (node) {
            visit(node -> getValue(), contextArgs ...);
            preOrderHelper(node -> getLeftNode(), visit, contextArgs ...);
            preOrderHelper(node -> getRightNode(), visit, contextArgs ...);
        }
    }

    template<typename ... Types>
    void inOrderRightHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
        if (node) {
            preOrderHelper(node -> getRightNode(), visit, contextArgs ...);
            visit(node -> getValue(), contextArgs ...);
            preOrderHelper(node -> getLeftNode(), visit, contextArgs ...);
        }
    }

    template<typename ... Types>
    void postOrderRightHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
        if (node) {
            postOrderHelper(node -> getRightNode(), visit, contextArgs ...);
            postOrderHelper(node -> getLeftNode, visit, contextArgs ...);
            visit(node -> getValue(), contextArgs ...);
        }
    }

    template<typename ... Types>
    void preOrderRightHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
        if (node) {
            visit(node -> getValue(), contextArgs ...);
            preOrderHelper(node -> getRightNode(), visit, contextArgs ...);
            preOrderHelper(node -> getLeftNode(), visit, contextArgs ...);
        }
    }

    TreeNode<Key, Value> *getPairHelper(TreeNode<Key, Value> *node, const Key &key) const {
        if (node == nullptr or node -> getKey() == key) {
            return node;
        } else if (compareValues(key, node -> getKey())) {
            return getPairHelper(node -> getLeftNode(), key);
        } else {
            return getPairHelper(node -> getRightNode(), key);
        }
    }


    BinarySearchTree<Key, Value> *mapHelper(TreeNode<Key, Value> *startRoot, Value (*func)(Value &item)) {
        if (startRoot == nullptr) {
            return new BinarySearchTree<Key, Value>();
        }

        auto *newNode = new TreeNode<Key, Value>(startRoot -> getKey(), func(startRoot -> getValue()));
        auto *newTree = new BinarySearchTree<Key, Value>(newNode);
        newTree -> root -> setLeftNode(mapHelper(startRoot -> getLeftNode(), func) -> getRoot());
        newTree -> root -> setRightNode(mapHelper(startRoot -> getRightNode(), func) -> getRoot());

        return newTree;
    }

    void reduceHelper(TreeNode<Key, Value>* startRoot, Value(*func)(Value operand1, Value operand2), Value &base) {
        if (startRoot) {
            reduceHelper(startRoot -> getLeftNode(), func, base);
            reduceHelper(startRoot -> getRightNode(), func, base);
            base = func(startRoot -> getValue(), base);
        }
    }

    BinarySearchTree<Key, Value> *whereHelper(TreeNode<Key, Value> *node, bool (*func)(Value &item)) const {
        if (node == nullptr) {
            return new BinarySearchTree<Key, Value>();
        }

        auto *newTree = new BinarySearchTree<Key,Value>(node);

        if (func(node -> getValue())) {
            newTree -> insert(node -> getKey(), node -> getValue());
        }

        newTree -> whereHelper(node -> getLeftNode(), func);
        newTree -> whereHelper(node -> getRightNode(), func);

        return newTree;
    }

    void insertHelper(TreeNode<Key, Value> *startRoot, const Key &key, const Value &value) {
        if (key == startRoot -> getKey()) {
            return;
        }

        if (compareValues(key, startRoot -> getKey())) {
            if (startRoot -> getLeftNode() == nullptr) {
                startRoot -> setLeftNode(new TreeNode<Key, Value>(key, value));
                return;
            }

            insertHelper(startRoot -> getLeftNode(), key, value);
        }
        else {
            if (startRoot -> getRightNode() == nullptr) {
                startRoot -> setRightNode(new TreeNode<Key, Value>(key, value));
                return;
            }

            insertHelper(startRoot -> getRightNode(), key, value);
        }
    }

    int getHeight(TreeNode<Key, Value> *node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(getHeight(node -> getLeftNode()), getHeight(node -> getRightNode()));
    }

    void printLevel(TreeNode<Key, Value> *node, int level, int indentSpace) const {
        if (node == nullptr) {
            std::cout<< std::setw(indentSpace) << " ";
            return;
        }
        if (level == 1) {
            std::cout << std::setw(indentSpace) << node -> getKey();
        } else if (level > 1) {
            printLevel(node -> getLeftNode(), level - 1, indentSpace / 2);
            printLevel(node -> getRightNode(), level - 1, indentSpace / 2);
        }
    }
public:
    explicit BinarySearchTree(TreeNode<Key, Value> *root): root(root) {}

    BinarySearchTree() {
        this -> root = nullptr;
    };

    ~BinarySearchTree() = default;

    TreeNode<Key, Value> *getPair(const Key &key) const;
    BinarySearchTree<Key, Value> *insert(const Key &key, const Value &value);
    BinarySearchTree<Key, Value> *map(Value (*func)(Value &item));
    BinarySearchTree<Key, Value> *where(bool (*func)(Value &item)) const;
    bool find(const Key &key) const;
    template<typename ... Types>
    void inOrder(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs);
    template<typename ... Types>
    void preOrder(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs);
    template<typename ... Types>
    void postOrder(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs);
    template<typename ... Types>
    void inOrderRight(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs);
    template<typename ... Types>
    void preOrderRight(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs);
    template<typename ... Types>
    void postOrderRight(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs);
    template<typename ... Types>
    void printTree() const;

};

template<Numeric Key, typename Value>
TreeNode<Key, Value> *BinarySearchTree<Key, Value>::getPair(const Key &key) const {
    return getPairHelper(this -> getRoot(), key);
}

template<Numeric Key, typename Value>
bool BinarySearchTree<Key, Value>::find(const Key &key) const {
    return getPairHelper(this -> getRoot(), key) -> getKey() == key;
}

template<Numeric Key, typename Value>
BinarySearchTree<Key, Value> *BinarySearchTree<Key, Value>::insert(const Key &key, const Value &value) {
    if (this -> getRoot() == nullptr) {
        root = new TreeNode<Key, Value>(key, value);

        return this;
    }

    insertHelper(this -> getRoot(), key, value);
    return this;
}

template<Numeric Key, typename Value>
BinarySearchTree<Key, Value> *BinarySearchTree<Key, Value>::map(Value (*func)(Value &item)) {
    return this -> mapHelper(this -> getRoot(), func);
}

template<Numeric Key, typename Value>
BinarySearchTree<Key, Value> *BinarySearchTree<Key, Value>::where(bool (*func)(Value &item)) const {
    return this -> whereHelper(this -> getRoot(), func);
}

template<Numeric Key, typename Value>
template<typename ... Types>
void BinarySearchTree<Key, Value>::inOrder(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
    this -> inOrderHelper(this -> getRoot(), visit, contextArgs ...);
}

template<Numeric Key, typename Value>
template<typename ... Types>
void BinarySearchTree<Key, Value>::preOrder(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
    this -> preOrderHelper(this -> getRoot(), visit, contextArgs ...);
}

template<Numeric Key, typename Value>
template<typename ... Types>
void BinarySearchTree<Key, Value>::postOrder(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
    this -> postOrderHelper(this -> getRoot(), visit, contextArgs ...);
}

template<Numeric Key, typename Value>
template<typename ... Types>
void BinarySearchTree<Key, Value>::inOrderRight(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
    this -> inOrderRightHelper(this -> getRoot(), visit, contextArgs ...);
}

template<Numeric Key, typename Value>
template<typename ... Types>
void BinarySearchTree<Key, Value>::preOrderRight(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
    this -> preOrderRightHelper(this -> getRoot(), visit, contextArgs ...);
}

template<Numeric Key, typename Value>
template<typename ... Types>
void BinarySearchTree<Key, Value>::postOrderRight(void (*visit)(Value &item, Types& ... contextArgs), Types& ... contextArgs) {
    this -> postOrderRightHelper(this -> getRoot(), visit, contextArgs ...);
}

template<Numeric Key, typename Value>
template<typename ... Types>
void BinarySearchTree<Key, Value>::printTree() const {
    int height = getHeight(this -> getRoot());
    int indentSpace = (int)std::pow(2, height + 1);

    for (int i = 1; i <= height; i++) {
        printLevel(this -> getRoot(), i, indentSpace);
        std::cout << std::endl;
    }
}