#pragma once
#include <iostream>
#include <limits>
#include "../different_trees/binary_search_tree/binarySearchTreeUnitTests.h"
#include "../different_trees/binary_search_tree/binarySearchTree.h"

class TUI {
public:
    TUI() = default;

    static int listenUser(int numItems) {
        int chosenItem = -1;
        while (true) {
            std::cin >> chosenItem;

            if (std::cin.fail() or chosenItem < 0 or chosenItem > numItems) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 0 and " << numItems << ".\n";
            } else {
                break;
            }
        }

        return chosenItem;
    }

    static void sayHello() {
        std::cout << "~ Hello, dear User! :)" << std::endl;
        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;
    }


    void creatingTreeChooseTypeOfValuesScreen() {
        std::cout << "~ Great! Now you will build a Binary Search Tree object and test it!" << std::endl;
        std::cout << "~ Choose the type of value for your Tree: \n" << std::endl;

        std::cout << "~ Enter the number (0 to exit from the program):" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "0 - HELP (additional explanation)" << std::endl;
        std::cout << "1 - Integer" << std::endl;
        std::cout << "2 - Double" << std::endl;
        std::cout << "3 - Char" << std::endl;
        std::cout << "--------------------- \n" << std::endl;

//        int keys[] = {1, 2, 3, 4, 5, 6};
//        int intDataset[] = {1, 2, 3, 4, 5, 6};
//        double doubleDataset[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
//        char charDataset[] = {'a', 'b', 'c', 'd', 'e', 'f'};

        switch(listenUser(4)) {
            case 0:
                exit(1);
            case 1: {
                BinarySearchTree<int, int> intTree;
                intTree.insert(3, 3);
                intTree.insert(2, 2);
                intTree.insert(1, 1);
                intTree.insert(4, 4);
                intTree.insert(5, 5);
                intTree.insert(6, 6);
                this -> workingWithTreeScreen(&intTree, "int");
                break;
            }
            case 2: {
                BinarySearchTree<int, double> doubleTree;
                doubleTree.insert(3, 3.0);
                doubleTree.insert(2, 2.0);
                doubleTree.insert(1, 1.0);
                doubleTree.insert(4, 4.0);
                doubleTree.insert(5, 5.0);
                doubleTree.insert(6, 6.0);
                this -> workingWithTreeScreen(&doubleTree, "double");
                break;
            }
            case 3: {
                BinarySearchTree<int, char> charTree;
                charTree.insert(3, 'a');
                charTree.insert(2, 'a');
                charTree.insert(1, 'a');
                charTree.insert(4, 'a');
                charTree.insert(5, 'a');
                charTree.insert(6, 'a');
                this -> workingWithTreeScreen(&charTree, "char");
                break;
            }
            default:
                std::cout << "Invalid choice. Please select a number between 0 and 3." << std::endl;
                break;
        }

        std::cout << "~ Input 0 - to continue" << std::endl;
    }

    template<Numeric Key, typename Value>
    void workingWithTreeScreen(BinarySearchTree<Key, Value> *tree, std::string typeOfContent) {
        std::cout << "~ You successfully create BinarySearchTree object! Now you you can test it!" << std::endl;

        if (typeOfContent == "int") {
            std::cout << "~ An object was filled by test values from this array -> [1, 2, 3, 4, 5, 6, 7, 8]"
                      << std::endl;
        } else if (typeOfContent == "double") {
            std::cout
                    << "~ An object was filled by test values from this array -> [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0]"
                    << std::endl;
        } else if (typeOfContent == "char") {
            std::cout
                    << "~ An object was filled by test values from this array -> ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']"
                    << std::endl;
        }
        std::cout << "~ At that moment you can test methods of this object." << std::endl;
        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;
        std::cout << "~ Enter the number(0 - to exit from the program):" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "1 - Help" << std::endl;
        std::cout << "2 - Insert element in BinarySearchTree" << std::endl;
        std::cout << "3 - Map element in BinarySearchTree" << std::endl;
        std::cout << "4 - StartUnitTests" << std::endl;
        std::cout << "5 - Is element in BinarySearchTree" << std::endl;
        std::cout << "6 - Get Pair by key from BinarySearchTree" << std::endl;
        std::cout << "7 - Print BinarySearchTree" << std::endl;
        std::cout << "8 - Different Tree Traversals" << std::endl;
        std::cout << "--------------------- \n" << std::endl;

        Key key;
        Value item;

        switch (listenUser(8)) {
            case 0:
                exit(1);
                break;
            case 1:
                std::cout << "------- Result ------->" << std::endl;
                this -> workingWithTreeScreen(tree, typeOfContent);

                break;
            case 2:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Current sequence: ";
                tree -> printTree();
                std::cout << "Input key: ";
                std::cin >> key;
                std::cout << "Input value: ";
                std::cin >> item;
                std::cout << "Updated tree: ";
                tree -> insert(key, item);
                tree -> printTree();
                std::cout << "<-------------------- \n" << std::endl;
                break;
            case 3:
                sayHello();
                break;
            case 4:
                startBinarySearchTreeUnitTests();
                break;
            case 5:
                sayHello();
                break;
            case 6:
                sayHello();
                break;
            case 7:
                std::cout << "-------result------->" << std::endl;
                std::cout << "Current sequence: ";
                tree -> printTree();
                std::cout << "Input key: ";
                std::cin >> key;
                std::cout << "Input value: ";
                std::cin >> item;
                std::cout << "Updated tree: ";
                tree -> printTree();
                std::cout << "<-------------------- \n" << std::endl;
                break;

            case 8:
                sayHello();
                break;
        }

        std::cout << "~ Input 0 - to continue" << std::endl;

        switch (listenUser(0)) {
            case 0:
                workingWithTreeScreen(tree, typeOfContent);
                break;
        }

    }
};