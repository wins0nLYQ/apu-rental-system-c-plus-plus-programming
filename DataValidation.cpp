#include <iostream>
#include <regex>
#include "DataValidation.h"
#include "Admin.cpp"

using namespace std;

DataValidation::DataValidation(){}

bool DataValidation::loginValidation(string email, string password, string userRole) {
    if (userRole == "Tenant") {
        cout << "Option 1";
        return true;
    } else if (userRole == "Manager") {
        cout << "Option 2";
        return true;
    } else if (userRole == "Admin") {
        Admin admin;
        if ((email == admin.getEmail()) && (password == admin.getPassword())) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool DataValidation::validateEmail(const string& email) {
    // Regular expression pattern for email validation
    regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

    // Match the email pattern against the provided email
    return regex_match(email, emailRegex);
}

bool DataValidation::handleUserLogin(const string& userRole) {
    string email;
    string password;

    cout << "Please enter the email address (-1 to back): ";
    cin >> email;
    cout << endl;
    if(email == "-1") {
        return false;
    }
    while (!validateEmail(email)) {
        cout << "Invalid email, please try again (-1 to back): ";
        cin >> email;
        cout << endl;
        if(email == "-1") {
            return false;
        }
    }

    cout << "Please enter the password (-1 to back): ";
    cin >> password;
    cout << endl;
    if(password == "-1") {
        return false;
    }

    while (!loginValidation(email, password, userRole)) {
        cout << "Invalid credentials, please try again!" << endl;
        cout << endl;
        cout << "Please enter the email address (-1 to back): ";
        cin >> email;
        cout << endl;

        if(email == "-1") {
            return false;
        }

        while (!validateEmail(email)) {
            cout << "Invalid email, please try again (-1 to back): ";
            cin >> email;
            cout << endl;

            if(email == "-1") {
                return false;
            }
        }

        cout << "Please enter the password (-1 to back): ";
        cin >> password;
        cout << endl;

        if(password == "-1") {
            return false;
        }
    }
    return true;
}