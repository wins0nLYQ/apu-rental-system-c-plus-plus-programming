/**
 * FILENAME: Asia_Pacific_Home.cpp
*/

#include <iostream>

using namespace std;

void homePage() {
    cout << "-------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "                      ASIA PACIFIC HOME                      " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "Please select an option (1-2):" << endl;
    cout << "1. View Property" << endl;
    cout << "2. Login" << endl;
    cout << ">> ";

    string userInput;
    cin >> userInput;

    if(userInput == "1") {
        cout << "Option 1";
    } else if(userInput == "2") {
        cout << "Option 2";
    } else {
        cout << endl << "Invalid input! Please try again." << endl;
        cout << endl;
        homePage();
    }
}