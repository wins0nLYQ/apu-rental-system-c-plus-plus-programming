#include "Admin.h"
#include <iomanip>
#include <iostream>
#include "DataValidation.h"


using namespace std;

Admin::Admin() {
    email = "admin@gmail.com";
    password = "Admin@1234";
}


string Admin::getEmail() const {
    return email;
}

string Admin::getPassword() const {
    return password;
}

void Admin::addManager(DynamicArray<Manager>& managerList, DynamicArray<Tenant>& tenantList) {
    // Implementation for adding a manager

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

    while(dv.isEmailExists(managerList, tenantList, email) == true) {
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
    while(dv.isValidID(identificationNo) == false) {
        cout << "ID number should be 6-15 characters! Please try again: ";
        getline(cin >> ws, identificationNo);
        cout << endl;
    }

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
    managerList.insertAtEnd(newManager);

    cout << "User account created successfully!" << endl;

    std::cout << "[MANAGER " << managerList.getSize() << "]\n";
    std::cout << "Name: " << newManager.getName() << std::endl;
    std::cout << "Email: " << newManager.getEmail() << std::endl;
    std::cout << "Phone Number: " << newManager.getPhoneNo() << std::endl;
    std::cout << "Identification No: " << newManager.getIdentificationNo() << std::endl;
    std::cout << "Gender: " << newManager.getGender() << std::endl;
    std::cout << "Date of Birth: " << newManager.getDateOfBirth() << std::endl;
    std::cout << "Status: " << newManager.getStatus() << std::endl;
    std::cout << "---------------------------\n";

    cout << "Default login password: abc@1234" << endl;
    cout << endl;

    std::cout << std::endl;
}

bool Admin::updateManagerStatus(DynamicArray<Manager>& managerList) {
    // Implementation for updating manager details
    cout << "Existing Manager Account Status:" << endl;
    cout << endl;
    int size = managerList.getSize();
    
    for (int i = 0; i < size; ++i) {
        Manager& manager = managerList.get(i);
        cout << setw(5) << right << i + 1 << ". ";
        cout << setw(15) << left << manager.getName();
        cout << " - " << manager.getStatus() << endl;
    }
    cout << endl;
    cout << "-1 to Back" << endl;
    cout << "Please enter the respective number to change the account status >> ";

    DataValidation dv; string userInput;
    getline(cin >> ws, userInput);
    cout << endl;
    if(userInput == "-1") {
        return false;
    }

    while(!dv.isNumber(userInput)) {
        cout << "-1 to Back" << endl;
        cout << "Invalid input! Please try again >> ";
        getline(cin >> ws, userInput);
        cout << endl;
        if(userInput == "-1") {
            return false;
        }
    }
    int inputNum = stoi(userInput) - 1;
    while(inputNum < 0 || inputNum >= size) {
        cout << "-1 to Back" << endl;
        cout << "Invalid input! Please try again >> ";
        getline(cin >> ws, userInput);
        cout << endl;
        if(userInput == "-1") {
            return false;
        } else {
            inputNum = stoi(userInput) - 1;
        }
    }
    cout << "-1 to Back" << endl;
    cout << "Are you sure to change the account status? (Y/N) >> ";
    getline(cin >> ws, userInput);
    cout << endl;

    while(userInput!="Y" && userInput!="N") {
        cout << "-1 to Back" << endl;
        cout << "Invalid input! Please try again >> ";
        getline(cin >> ws, userInput);
        cout << endl;
    }
    if(userInput == "Y") {
        Manager& manager = managerList.get(inputNum);
        string status = manager.getStatus();
        if(status == "Inactive") {
            manager.setStatus("Active");
        } else if(status == "Active") {
            manager.setStatus("Inactive");
        }
        managerList.get(inputNum) = manager;

        for (int i = 0; i < size; ++i) {
            Manager& manager = managerList.get(i);
            cout << setw(5) << right << i + 1 << ". ";
            cout << setw(15) << left << manager.getName();
            cout << " - " << manager.getStatus() << endl;
        }
        cout << endl;

        return true;
    } else if(userInput == "N") {
        return false;
    } 
}

void Admin::deleteManager() {
    // Implementation for deleting a manager
}

void Admin::filterTenants(DynamicArray<Tenant>& tenantList) {
    // Implementation for displaying all tenants

}

void Admin::displayPropertyInformation(const string& tenantID) {
    // Implementation for displaying property information for a specific tenant
}

void Admin::displayPropertyInformation() {
    // Implementation for displaying all property information
}