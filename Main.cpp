/**
 * FILENAME: Main.cpp
 */

#include<iostream>

#include "Asia_Pacific_Home.h"
#include "DoublyCircularLinkedList.h"

using namespace std;

int main()
{
    // Asia_Pacific_Home APH;
    // APH.homePage();

    /** Doubly-Circular LinkedList Testing*/
    int n = 0;
    std::cout << "Enter number of student name to store = ";
    std::cin >> n;
    DoublyCircularLinkedList<string> nameLst;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        std::cout << "\n>Enter name " << (i + 1) << " = ";
        std::cin >> tmp;
        nameLst.insertAtEnd(tmp);
    }

    nameLst.display();
    std::cout << endl;

    int index;
    string name;

    std::cout << "Enter index to insert: ";
    std::cin >> index;

    std::cout << "\n>Enter new name: ";
    std::cin >> name;

    nameLst.insertAtIndex(name, index);

    nameLst.display();
    std::cout << endl;

    int item;
    std::cout << "Get item at index: ";
    std::cin >> item;

    string node = nameLst.get(item);
    std::cout << "Selected item: " << node << std::endl;

    std::cout << "\nProgram ended!" << endl;
    std::cout << endl;

    return 0;
}
