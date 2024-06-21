cmake_minimum_required(VERSION 3.27)
project(lab_04)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_04
        different_trees/binary_search_tree/binarySearchTree.h
        different_trees/binary_search_tree/binarySearchTreeUnitTests.cpp
        different_trees/binary_search_tree/binarySearchTreeUnitTests.h
        TUI/menu.h
        TUI/main.cpp
        TUI/main.cpp
)
