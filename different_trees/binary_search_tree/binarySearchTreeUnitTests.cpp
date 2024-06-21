#include <iostream>
#include "binarySearchTree.h"
#include <cassert>

int squareItem(int &item) {
    return item * item;
}

bool isEval(int &item) {
    return item % 2 == 0;
}

void visitFuncSum(int &item, int &counter) {
    counter += item;
}

void visitFuncPrint(int &item) {
    std::cout << " " << item << " ";
}

void testInsertAndFind() {
    BinarySearchTree<int, int> tree;

    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);

    assert(tree.find(10) && "Insert test failed: Key 10 not found");
    assert(tree.find(5) && "Insert test failed: Key 5 not found");
    assert(tree.find(15) && "Insert test failed: Key 15 not found");

    std::cout << "[testInsert passed" << std::endl;
}

void testGetPair() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);

    assert(tree.getPair(10) -> getValue() == 100 && "Find test failed: Key 10 not found");
    assert(tree.getPair(5) -> getValue() == 50 && "Find test failed: Key 5 not found");
    assert(tree.getPair(15) -> getValue() == 150 && "Find test failed: Key 15 not found");
    assert(tree.getPair(11111) == nullptr && "Find test failed: non-exist is exist");
    std::cout << "[testFind passed" << std::endl;
}

void testMap() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);
    BinarySearchTree<int, int> *newTree = tree.map(squareItem);

    assert(newTree -> getPair(10) -> getValue() == 100 * 100 && "Find test failed: Key 100 * 100 not found");
    assert(newTree -> getPair(5) -> getValue() == 50 * 50 && "Find test failed: Key 50 * 50 not found");
    assert(newTree -> getPair(15) -> getValue() == 150 * 150 && "Find test failed: Key 150 * 150 not found");
    assert(newTree -> getPair(11111) == nullptr && "Find test failed: non-exist is exist");
    std::cout << "[testMap passed" << std::endl;

}

void testWhere() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);
    BinarySearchTree<int, int> *newTree = tree.where(isEval);

    assert(newTree -> getPair(10) -> getValue() % 2 == 0 && "Find test failed: Key 100 * 100 not found");
    assert(newTree -> getPair(5) -> getValue() % 2 == 0 && "Find test failed: Key 50 * 50 not found");
    assert(newTree -> getPair(15) -> getValue() % 2 == 0 && "Find test failed: Key 150 * 150 not found");
    assert(newTree -> getPair(11111) == nullptr && "Find test failed: non-exist is exist");
    std::cout << "[testWhere passed" << std::endl;

}

void testTraversals() {
    BinarySearchTree<int, int> bst;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    bst.insert(10, 100);
    bst.insert(5, 50);
    bst.insert(15, 150);
    bst.insert(2, 20);
    bst.insert(7, 70);
    std::cout << "\n";
    std::cout << "Tree: " << std::endl;
    bst.printTree();
    std::cout << "\n";
    std::string rightPathInOrder = " 20 50 70 100 150";
    std::string rightPathPreOrder = " 100 50 20 70 150";
    std::string rightPathPostOrder = " 20 70 50 150 100";
    std::cout << "[Right Path In order:" << rightPathInOrder << std::endl;
    std::cout << "[Right Path Post order:" << rightPathPostOrder << std::endl;
    std::cout << "[Right Path Pre order:" << rightPathPreOrder << std::endl;
    std::cout << "[Right Sum:" << " 390" << std::endl;
    std::cout << "In-order Traversal: ";
    bst.inOrder(visitFuncPrint);
    std::cout << "\n";
    std::cout << "Sum: ";
    bst.inOrder(visitFuncSum, counter1);
    std::cout << counter1;
    std::cout << "\n";
    std::cout << "Pre-order Traversal: ";
    bst.postOrder(visitFuncPrint);
    std::cout << "\n";
    std::cout << "Sum: ";
    bst.postOrder(visitFuncSum, counter2);
    std::cout << counter2;
    std::cout << "\n";
    std::cout << "Post-order Traversal: ";
    bst.preOrder(visitFuncPrint);
    std::cout << "\n";
    std::cout << "Sum: ";
    bst.preOrder(visitFuncSum, counter3);
    std::cout << counter3;
    std::cout << "\n";
}

void startBinarySearchTreeUnitTests() {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    testInsertAndFind();
    testGetPair();
    testMap();
    testWhere();
    testTraversals();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "All tests passed." << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}