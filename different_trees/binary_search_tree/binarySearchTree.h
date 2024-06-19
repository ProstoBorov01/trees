#pragma once
#include <iostream>


template<typename T>
concept Numeric = std::is_integral_v<T> or std::is_floating_point_v<T>;

//true => правая ветвь, false => левая ветвь;
template<typename Value>
bool compareValues(const Value &newOperand, const Value currentOperand) {
    return newOperand > currentOperand;
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

    ~TreeNode() = default;

    Value &getValue() const;
    Key &getKey() const;
    TreeNode<Key, Value> *updateValue(const Value &newValue) const;
    TreeNode<Key, Value> *setLeftNode(TreeNode<Key, Value> *node);
    TreeNode<Key, Value> *setRightNode(TreeNode<Key, Value> *node);
    TreeNode<Key, Value> *getLeftNode() const;
    TreeNode<Key, Value> *getRightNode() const;
    void deleteTreeNode(TreeNode<Key, Value> object);
    TreeNode<Key, Value> *createTreeNode(const Key &newKey, const Value &newValue,
                                         TreeNode<Key, Value> *newLeft , TreeNode<Key, Value> *newRight);
};

template<Numeric Key, typename Value>
Value &TreeNode<Key, Value>::getValue() const {
    return this -> value;
}

template<Numeric Key, typename Value>
Key &TreeNode<Key, Value>::getKey() const {
    return this -> key;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::updateValue(const Value &newValue) const {
    this -> value = newValue;

    return this;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::setLeftNode(TreeNode<Key, Value> *node) {
    return nullptr;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::setRightNode(TreeNode<Key, Value> *node) {
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
void TreeNode<Key, Value>::deleteTreeNode(TreeNode<Key, Value> object) {
    delete object;
}

template<Numeric Key, typename Value>
TreeNode<Key, Value> *TreeNode<Key, Value>::createTreeNode(const Key &newKey, const Value &newValue,
                                                           TreeNode<Key, Value> *newLeft,
                                                           TreeNode<Key, Value> *newRight) {
    auto *newTreeNode = new TreeNode(newKey, newValue, newLeft, newRight);

    if (newTreeNode == nullptr) {
        throw std::invalid_argument("Memory allocation error!");
    }

    return newTreeNode;
}

template<Numeric Key, typename Value>
class BinarySearchTree {
private:
    TreeNode<Key, Value> *root;
    TreeNode<Key, Value> *getRoot() const {
        return  this -> root;
    };

    void inOrderHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item)) {
        if (node) {
            inOrderHelper(node -> getLeftNode(), visit);
            visit(node -> getValue());
            inOrderHelper(node -> getLeftNode(), visit);
        }
    } // как бы с помощью обхода посчитать сумму

    void postOrderHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item)) {
        if (node) {
            postOrderHelper(node -> getLeftNode(), visit);
            postOrderHelper(node -> getRightNode(), visit);
            visit(node -> getValue());
        }
    }

    void preOrderHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item)) {
        if (node) {
            visit(node -> getValue());
            preOrderHelper(node -> getLeftNode(), visit);
            preOrderHelper(node -> getRightNode(), visit);
        }
    }

    void inOrderRightHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item)) {
        preOrderHelper(node -> getRightNode(), visit);
        visit(node -> getValue());
        preOrderHelper(node -> getLeftNode(), visit);
    }

    void postOrderRightHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item)) {
        if (node) {
            postOrderHelper(node->getRightNode(), visit);
            postOrderHelper(node->getLeftNode);
            visit(node->getValue());
        }
    }

    void preOrderRightHelper(TreeNode<Key, Value> *node, void (*visit)(Value &item)) {
        if (node) {
            visit(node->getValue());
            preOrderHelper(node->getRightNode(), visit);
            preOrderHelper(node->getLeftNode(), visit);
        }
    }

    BinarySearchTree<Key, Value> *mapHelper(TreeNode<Key, Value> *startRoot, Value (*func)(Value &item)) {
        if (startRoot == nullptr) {
            return new BinarySearchTree<Key, Value>();
        }

        auto *newNode = new TreeNode<Key, Value>::createTreeNode(startRoot -> getKey(), func(startRoot -> getValue()));
        auto *newTree = new BinarySearchTree<Key, Value>(newNode);
        newTree -> root -> setLeftNode(mapHelper(startRoot -> getLeftNode(), func) -> getRoot());
        newTree -> root -> setRightNode(mapHelper(startRoot -> getRightNode(), func) -> getRoot());

        return newTree;
    }

    BinarySearchTree<Key, Value> whereHelper(TreeNode<Key, Value> *node, bool (*func)(const Value &item)) const {
        if (node == nullptr) {
            return BinarySearchTree<Key, Value>();
        }

        BinarySearchTree<Key, Value> newTree(node);

        if (func(node -> getValue())) {
            newTree.insert(node -> getKey(), node -> getValue());
        }

        newTree.whereHelper(node -> getLeftNode(), func);
        newTree.whereHelper(node -> getRightNode(), func);

        return newTree;
    }

    void insertHelper(TreeNode<Key, Value> *startRoot, const Key &key, const Value &value) {
        if (startRoot == nullptr) {
            startRoot = TreeNode<Key, Value>::createTreeNode(key, value);
        }
        else if (key == startRoot -> getKey()) {
            std::cout << "Such key is already exist in Tree" << std::endl;
        }

        else if (compareValues(key, startRoot -> getKey()) == true) {
            insertHelper(startRoot -> leftNode, key, value);
        }
        else {
            insertHelper(startRoot -> rightNode, key, value);
        }
    }

    bool findHelper(const TreeNode<Key, Value> *startNode, const Key &key) const {
        if (startNode == nullptr) {
            return false;
        }
        else if (startNode -> getKey() == key) {
            return true;
        }
        else if (compareValues(key, startNode -> getKey())) {
            findHelper(startNode -> getLeftNode(), key);
        }
        else {
            findHelper(startNode -> getRightNode(), key);
        }

        return false;
    }

    BinarySearchTree<Key, Value> *merge(const TreeNode<Key, Value> *otherRoot) {


    }

public:
    explicit BinarySearchTree(const TreeNode<Key, Value> *root): root(root) {}
//    BinarySearchTree(const BinarySearchTree<Key, Value> &copyTree)  {
//
//    }
    BinarySearchTree() = default;

    BinarySearchTree<Key, Value> *insert(const Key &key, const Value &value);
    BinarySearchTree<Key, Value> *map(Value (*func)(Value &item));
    BinarySearchTree<Key, Value> *where(TreeNode<Key, Value> *startRoot, bool (*func)(const Value &item)) const ;
//    BinarySearchTree<Key, Value> *merge(const BinarySearchTree<Key, Value> *other) const;
    bool find(const Key &key) const;
    void inOrder(void (*visit)(Value &item));
    void preOrder(void (*visit)(Value &item));
    void postOrder(void (*visit)(Value &item));
    void inOrderRight(void (*visit)(Value &item));
    void preOrderRight(void (*visit)(Value &item));
    void postOrderRight(void (*visit)(Value &item));
};

template<Numeric Key, typename Value>
bool BinarySearchTree<Key, Value>::find(const Key &key) const {
    return findHelper(this -> getRoot(), key);;
}

template<Numeric Key, typename Value>
BinarySearchTree<Key, Value> *BinarySearchTree<Key, Value>::insert(const Key &key, const Value &value) {
    insertHelper(this -> getRoot(), key, value);

    return this;
}

template<Numeric Key, typename Value>
BinarySearchTree<Key, Value> *BinarySearchTree<Key, Value>::map(Value (*func)(Value &item)) {
    return this -> mapHelper(this -> getRoot(), func);
}


template<Numeric Key, typename Value>
BinarySearchTree<Key, Value> *BinarySearchTree<Key, Value>::where(TreeNode<Key, Value> *startRoot, bool (*func)(const Value &item)) const {

    return this -> whereHelper(this -> getRoot(), func);
}

template<Numeric Key, typename Value>
void BinarySearchTree<Key, Value>::inOrder(void (*visit)(Value &)) {
    this -> inOrderHelper(this -> getRoot(), visit);
}

template<Numeric Key, typename Value>
void BinarySearchTree<Key, Value>::preOrder(void (*visit)(Value &item)) {
    this -> preOrderHelper(this -> getRoot(), visit);
}

template<Numeric Key, typename Value>
void BinarySearchTree<Key, Value>::postOrder(void (*visit)(Value &item)) {
    this -> postOrderHelper(this -> getRoot(), visit);
}

template<Numeric Key, typename Value>
void BinarySearchTree<Key, Value>::inOrderRight(void (*visit)(Value &item)) {
    this -> inOrderRightHelper(this -> getRoot(), visit);
}

template<Numeric Key, typename Value>
void BinarySearchTree<Key, Value>::preOrderRight(void (*visit)(Value &item)) {
    this -> preOrderRightHelper(this -> getRoot(), visit);
}

template<Numeric Key, typename Value>
void BinarySearchTree<Key, Value>::postOrderRight(void (*visit)(Value &item)) {
    this -> postOrderRightHelper(this -> getRoot(), visit);
}





