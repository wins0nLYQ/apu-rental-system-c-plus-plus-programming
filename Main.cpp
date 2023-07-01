/**
 * FILENAME: Main.cpp
*/

#include "Asia_Pacific_Home.cpp"
#include "DoublyCircularLinkedList.h"

int main() {
    // Asia_Pacific_Home APH;
    // APH.homePage();
    // return 0;

    /** DEMO - Tutorial7 - LinkedLIst-Doubly */

    int n = 0;
    cout << "Enter number of student name to store = ";
    cin >> n;
    DoublyCircularLinkedList<string> nameLst;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cout << "\n>Enter name " << (i+1) << " = ";
        cin >> tmp;
        nameLst.insert(tmp);
    }

    nameLst.display();
    cout << endl;

    cout << "\nProgram ended!" << endl;
    cout << endl;

    return 0;
}