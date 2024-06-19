#include <cassert>
#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

void testInsert() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);

    assert(tree.find(10) && "Insert test failed: Key 10 not found");
    assert(tree.find(5) && "Insert test failed: Key 5 not found");
    assert(tree.find(15) && "Insert test failed: Key 15 not found");

    std::cout << "testInsert passed" << std::endl;
}

void testFind() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);

    assert(tree.find(10) && "Find test failed: Key 10 not found");
    assert(tree.find(5) && "Find test failed: Key 5 not found");
    assert(tree.find(15) && "Find test failed: Key 15 not found");
    assert(!tree.find(20) && "Find test failed: Non-existent key 20 found");

    std::cout << "testFind passed" << std::endl;
}

void testInOrderTraversal() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);

    std::vector<int> result;
    tree.inOrder([&result](int &item) { result.push_back(item); });

    assert((result == std::vector<int>{50, 100, 150}) && "InOrderTraversal test failed");

    std::cout << "testInOrderTraversal passed" << std::endl;
}

void testPreOrderTraversal() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);

    std::vector<int> result;
    tree.preOrder([&result](int &item) { result.push_back(item); });

    assert((result == std::vector<int>{100, 50, 150}) && "PreOrderTraversal test failed");

    std::cout << "testPreOrderTraversal passed" << std::endl;
}

void testPostOrderTraversal() {
    BinarySearchTree<int, int> tree;
    tree.insert(10, 100);
    tree.insert(5, 50);
    tree.insert(15, 150);

    std::vector<int> result;
    tree.postOrder([&result](int &item) { result.push_back(item); });

    assert((result == std::vector<int>{50, 150, 100}) && "PostOrderTraversal test failed");

    std::cout << "testPostOrderTraversal passed" << std::endl;
}

int main() {
    testInsert();
    testFind();
    testInOrderTraversal();
    testPreOrderTraversal();
    testPostOrderTraversal();

    std::cout << "All tests passed." << std::endl;
    return 0;
}
