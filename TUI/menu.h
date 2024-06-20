//#pragma once
//
//#include <iostream>
//#include <limits>
//#include "../different_trees/binary_search_tree/binarySearchTreeUnitTests.h"
//#include "../different_trees/binary_search_tree/binarySearchTree.h"
//
//class TUI {
//public:
//    TUI() = default;
//
//    static int listenUser(int numItems) {
//        int chosenItem = -1;
//        while (true) {
//            std::cin >> chosenItem;
//
//            if (std::cin.fail() or chosenItem < 0 or chosenItem > numItems) {
//                std::cin.clear();
//                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                std::cout << "Invalid input. Please enter a number between 0 and " << numItems << ".\n";
//            } else {
//                break;
//            }
//        }
//
//        return chosenItem;
//    }
//
//    static void sayHello() {
//        std::cout << "~ Hello, dear User! :)"<< std::endl;
//        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;
//    }
//
//    void creatingTreeChooseTypeOfValuesScreen() {
//        std::cout << "~ Great! Now you you will build Binary Search Tree object and test it!" << std::endl;
//        std::cout << "~ You should to choose the type of value in your Tree:) \n" << std::endl;
//
//        std::cout << "~ Enter the number(0 - to exit from the program):" << std::endl;
//        std::cout << "---------------------" << std::endl;
//        std::cout << "0 - HELP (this point additionally explains what is each point about)" << std::endl;
//        std::cout << "1 - Integer" << std::endl;
//        std::cout << "2 - Double" << std::endl;
//        std::cout << "3 - Char" << std::endl;
//        std::cout << "--------------------- \n" << std::endl;
//        int keys[] = {1, 2, 3, 4, 5, 6};
//        int intDataset[] = {1, 2, 3, 4, 5, 6};
//        double doubleDataset[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
//        char charDataset[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//
//        switch (listenUser(4)) {
//            case 0:
//                exit(1);
//                break;
//            case 1:
//                BinarySearchTree<int, int> *intTree;
//
//                for (int i = 0; i < 6; i ++) {
//                    intTree -> insert(keys[i], intDataset[i]);
//                }
//
//                this -> workingWithTreeScreen(intTree, "int");
//                break;
//            case 2:
//                BinarySearchTree<int, double> *doubleTree;
//
//                for (int i = 0; i < 6; i ++) {
//                   doubleTree -> insert(keys[i], doubleDataset[i]);
//                }
//
//                this -> workingWithTreeScreen(doubleTree, "double");
//                break;
//            case 3:
//                BinarySearchTree<int, char> *charTree;
//
//                for (int i = 0; i < 6; i ++) {
//                    charTree -> insert(keys[i], charDataset[i]);
//                }
//
//                this -> workingWithTreeScreen(charTree, "char");
//                break;
//        }
//    }
//
//    template<Numeric Key, typename Value>
//    void workingWithTreeScreen(BinarySearchTree<Key, Value> *tree, std::string typeOfContent) {
//        std::cout << "~ You successfully create BinarySearchTree object! Now you you can test it!" << std::endl;
//
//        if (typeOfContent == "int") {
//            std::cout << "~ An object was filled by test values from this array -> [1, 2, 3, 4, 5, 6, 7, 8]" << std::endl;
//        } else if (typeOfContent == "double") {
//            std::cout << "~ An object was filled by test values from this array -> [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0]" << std::endl;
//        } else if (typeOfContent == "char") {
//            std::cout << "~ An object was filled by test values from this array -> ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']" << std::endl;
//
//        std::cout << "~ At that moment you can test methods of this object." << std::endl;
//        std::cout << "~ Follow the prompts on the screen! \n" << std::endl;
//        std::cout << "~ Enter the number(0 - to exit from the program):" << std::endl;
//        std::cout << "---------------------" << std::endl;
//        std::cout << "1 - Insert element in BinarySearchTree" << std::endl;
//        std::cout << "2 - Map element in BinarySearchTree" << std::endl;
//        std::cout << "3 - Map element in BinarySearchTree" << std::endl;
//        std::cout << "4 - Is element in BinarySearchTree" << std::endl;
//        std::cout << "5 - Get Pair by key from BinarySearchTree" << std::endl;
//        std::cout << "6 - Print BinarySearchTree" << std::endl;
//        std::cout << "7 - Different Tree Traversals" << std::endl;
//        std::cout << "--------------------- \n" << std::endl;
//
//        switch(listenUser(7)) {
//            case 0:
//                exit(1);
//            case 1:
//                std::cout << "-------result------->" << std::endl;
//                workingWithSequenceScreen(arrayObject, nameOfSequence, typeOfContent);
//                break;
//            case 2:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "First element is " << arrayObject -> getFirst() << std::endl;
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 3:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "Last element is " << arrayObject -> getLast() << std::endl;
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 4:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "Enter index of element that you want to get " << std::endl;
//                int index;
//                std::cin >> index;
//                std::cout << "Element with index " << index << " is " << arrayObject -> get(index) << std::endl;
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 5:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "Length of Sequence is " << arrayObject -> getLength() << std::endl;
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 6:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "Current sequence: ";
//                arrayObject -> printSequence();
//                std::cout << "Input item that you want to add: ";
//                std::cin >> item;
//                arrayObject -> append(item);
//                std::cout << "Updated sequence: ";
//                arrayObject -> printSequence();
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 7:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "Current sequence: ";
//                arrayObject -> printSequence();
//                std::cout << "Input item that you want to add: ";
//                std::cin >> item;
//                arrayObject -> prepend(item);
//                std::cout << "Updated sequence: ";
//                arrayObject -> printSequence();
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 8:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "Current sequence: ";
//                arrayObject -> printSequence();
//                std::cout << "Input item that you want to add: ";
//                std::cin >> item;
//                std::cout << "Input index: ";
//                std::cin >> index;
//                arrayObject -> insertAt(item, index);
//                std::cout << "Updated sequence: ";
//                arrayObject -> printSequence();
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 9:
//                std::cout << "-------result------->" << std::endl;
//                std::cout << "The result of coupling a sequence with itself" << std::endl;
//                arrayObject -> concat(arrayObject) -> printSequence();
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//            case 10:
//                if (nameOfSequence == "Array Sequence") {
//                    testArraySequence();
//                }
//                else {
//                    testListSequence();
//                }
//                break;
//            case 11:
//                std::cout << "-------result------->" << std::endl;
//                int startIndex, endIndex;
//                std::cout << "Input startIndex:" << std::endl;
//                std::cout << "Input endIndex:" << std::endl;
//                std::cin >> startIndex;
//                std::cin >> endIndex;
//                SequenceAbstract<T> *subSequence = arrayObject -> getSubSequence(startIndex, endIndex);
//                std::cout << "Sub-sequence from " << startIndex << " to " << endIndex << " is: ";
//                subSequence -> printSequence();
//                delete subSequence;
//                std::cout << "<-------------------- \n" << std::endl;
//                break;
//        }
//
//        std::cout << "~ Input 0 - to continue" << std::endl;
//
//        switch (listenUser(0)) {
//            case 0:
//                workingWithTreeScreen(arrayObject, nameOfSequence, typeOfContent);
//                break;
//        }
//    }
//};
//
//int main() {
//    TUI session;
//    TUI::sayHello();
//}
