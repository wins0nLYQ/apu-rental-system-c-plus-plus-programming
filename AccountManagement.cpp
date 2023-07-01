#include "AccountManagement.h"
#include "DataValidation.cpp"
#include "Asia_Pacific_Home.cpp"
#include <string>


void AccountManagement::addNewAccount() {
    DataValidation dv;
    string name, email, phoneNo, identificationNo, gender, dateOfBirth, status;
    cout << "[ADD NEW MANAGER ACCOUNT]" << endl;

    cout << "Name: ";
    getline(cin >> ws, name);
    cout << endl;

    cout << "Email: ";
    getline(cin >> ws, email);
    cout << endl;
    while(dv.isEmailValid(email) == false) {
        cout << "Invalid email! Please try again: ";
        getline(cin >> ws, email);
        cout << endl;
    }
    while(managerList.isEmailExists(email) == true) {
        cout << "Email exist! Please try another one: ";
        getline(cin >> ws, email);
        cout << endl;
    }
    while(tenantList.isEmailExists(email) == true) {
        cout << "Email exist! Please try another one: ";
        getline(cin >> ws, email);
        cout << endl;
    }

    cout << "Phone Number: ";
    getline(cin >> ws, phoneNo);
    cout << endl;
    while(dv.isValidPhoneNumber(phoneNo) == false) {
        cout << "Phone number should be 10-11 digits! Please try again: ";
        getline(cin >> ws, phoneNo);
        cout << endl;
    }

    cout << "Identification No: ";
    getline(cin >> ws, identificationNo);
    cout << endl;

    cout << "Gender (1 - MALE; 2 - FEMALE): ";
    getline(cin >> ws, gender);
    cout << endl;
    while(gender!="1" && gender!="2") {
        cout << "Invalid input! Please try again (1 - MALE; 2 - FEMALE): ";
        getline(cin >> ws, gender);
        cout << endl;
    }
    if(gender == "1") {
        gender = "Male";
    } else {
        gender = "Female";
    }

    cout << "Date of Birth (YYYY-MM-DD): ";
    getline(cin >> ws, dateOfBirth);
    cout << endl;
    while(dv.isValidDateOfBirth(dateOfBirth) == false) {
        cout << "Invalid date of birth! Please try again (YYYY-MM-DD): ";
        getline(cin >> ws, dateOfBirth);
        cout << endl;
    }

    cout << "Status (0 - INACTIVE; 1 - ACTIVE): ";
    getline(cin >> ws, status);
    cout << endl;
    while(status!="0" && status!="1") {
        cout << "Invalid input! Please try again (0 - INACTIVE; 1 - ACTIVE): ";
        getline(cin >> ws, status);
        cout << endl;
    }
    if(status == "0") {
        status = "Inactive";
    } else {
        status = "Active";
    }

    Manager newManager(name, email, phoneNo, identificationNo, gender, dateOfBirth, status);
    managerList.add(newManager);

    cout << "User account created successfully!" << endl;
    managerList.displayLatest("MANAGER");
    cout << "Default login password: abc@1234" << endl;
    cout << endl;

    cout << "Input any key to back >> ";
    string userInput;
    getline(cin >> ws, userInput);
    cout << endl;
}