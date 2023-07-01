/**
 * FILENAME: Main.cpp
 */

#include<iostream>

#include "Asia_Pacific_Home.h"
#include "DoublyCircularLinkedList.h"

int main()
{
    // Asia_Pacific_Home APH;
    // APH.homePage();

    /** DEMO - Tutorial7 - LinkedLIst-Doubly */

    int n = 0;
    std::cout << "Enter number of student name to store = ";
    std::cin >> n;
    DoublyCircularLinkedList<string> nameLst;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        std::cout << "\n>Enter name " << (i + 1) << " = ";
        std::cin >> tmp;
        nameLst.insert(tmp);
    }

    nameLst.display();
    std::cout << endl;

    std::cout << "\nProgram ended!" << endl;
    std::cout << endl;

    return 0;
}
