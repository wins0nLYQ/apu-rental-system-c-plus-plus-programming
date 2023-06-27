/**
 * FILENAME: Asia_Pacific_Home.cpp
*/

#include <iostream>
#include <regex>
#include "DataValidation.cpp"
#include "Asia_Pacific_Home.h"

using namespace std;

Asia_Pacific_Home::Asia_Pacific_Home() {}

void Asia_Pacific_Home::homePage() {
    cout << "-------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "                      ASIA PACIFIC HOME                      " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "Please select an option (1-3):" << endl;
    cout << "1. View Property" << endl;
    cout << "2. Login" << endl;
    cout << "3. Sign Up" << endl;
    cout << ">> ";

    string userInput;
    cin >> userInput;
    cout << endl;

    if(userInput == "1") {
        cout << "Option 1";
    } else if(userInput == "2") {
        loginPage();
    } else if(userInput == "3") {
        cout << "Option 3";
    } else {
        cout << endl << "Invalid input! Please try again." << endl;
        cout << endl;
        homePage();
    }
}

void Asia_Pacific_Home::loginPage() {
    DataValidation dv;
    cout << "Please select your user role (1-3):" << endl;
    cout << "1. Tenant" << endl;
    cout << "2. Manager" << endl;
    cout << "3. Admin" << endl;
    cout << ">> ";

    string userInput;
    cin >> userInput;
    cout << endl;

    if(userInput == "1") {
        if(dv.handleUserLogin("Tenant") == false) {
            loginPage();
        } else {

        }

    } else if(userInput == "2") {
        if(dv.handleUserLogin("Manager") == false) {
            loginPage();
        } else {
            
        }

    } else if(userInput == "3") {
        if(dv.handleUserLogin("Admin") == false) {
            loginPage();
        } else {
            cout << "Welcome Admin!" << endl;
        }

    } else {
        cout << endl << "Invalid input! Please try again." << endl;
        cout << endl;
        loginPage();
    }
}

