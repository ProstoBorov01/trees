cmake_minimum_required(VERSION 3.27)
project(lab_04)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_04 main.cpp
        different_trees/binary_search_tree/binarySearchTree.h
        different_trees/binary_search_tree/binarySearchTreeUnitTests.cpp)
