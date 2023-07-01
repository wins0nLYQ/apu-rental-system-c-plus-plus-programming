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

void Admin::addManager() {
    // Implementation for adding a manager
}

bool Admin::updateManagerStatus(UserAccount_Manager<Manager>& managerList) {
    // Implementation for updating manager details
    cout << "Existing Manager Account Status:" << endl;
    cout << endl;
    int size = managerList.getSize();
    
    for (int i = 0; i < size; ++i) {
        Manager& manager = managerList.getManager(i);
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
        Manager& manager = managerList.getManager(inputNum);
        string status = manager.getStatus();
        if(status == "Inactive") {
            manager.setStatus("Active");
        } else if(status == "Active") {
            manager.setStatus("Inactive");
        }
        managerList.getManager(inputNum) = manager;

        for (int i = 0; i < size; ++i) {
            Manager& manager = managerList.getManager(i);
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

void Admin::filterTenants(UserAccount_Manager<Tenant>& tenantList) {
    // Implementation for displaying all tenants

}

void Admin::displayPropertyInformation(const string& tenantID) {
    // Implementation for displaying property information for a specific tenant
}

void Admin::displayPropertyInformation() {
    // Implementation for displaying all property information
}