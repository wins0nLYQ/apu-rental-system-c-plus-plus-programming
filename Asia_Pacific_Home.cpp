/**
 * FILENAME: Asia_Pacific_Home.cpp
 */

#include <iostream>
#include <regex>
#include "Asia_Pacific_Home.h"
#include "DynamicArray.h"
#include "Manager.h"
#include "Tenant.h"
#include "DataValidation.h"
#include "Admin.h"
#include "ReadCSV.h"

using namespace std;

DynamicArray<Manager> managerList;
DynamicArray<Tenant> tenantList;
vector<Property> properties;

void Asia_Pacific_Home::homePage() {
    Tenant newTenant("Wong Hau", "hello@gmail.com", "01234567890", "123123123", "Male", "2022-09-01", "hello");
    tenantList.insertAtEnd(newTenant);

    Tenant newTenant2("Hello", "Wuuha@gmail.com", "0987654321", "123123123", "Female", "2022-05-01", "hi");
    tenantList.insertAtEnd(newTenant2);

    ReadCSV readCSV;
    properties = readCSV.readCSV("mudah-apartment-kl-selangor.csv");

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
    getline(cin >> ws, userInput);
    cout << endl;

    if (userInput == "1")
    {
        cout << "Option 1";
    }
    else if (userInput == "2")
    {
        loginPage();
    }
    else if (userInput == "3")
    {
        cout << "Option 3";
    }
    else
    {
        cout << endl
             << "Invalid input! Please try again." << endl;
        cout << endl;
        homePage();
    }
}

void Asia_Pacific_Home::loginPage()
{
    DataValidation dv;
    cout << "Please select your user role (1-3):" << endl;
    cout << "1. Tenant" << endl;
    cout << "2. Manager" << endl;
    cout << "3. Admin" << endl;
    cout << ">> ";

    string userInput;
    getline(cin >> ws, userInput);
    cout << endl;

    if (userInput == "1")
    {
        if (dv.handleUserLogin("Tenant") == false)
        {
            loginPage();
        }
        else
        {
        }
    }
    else if (userInput == "2")
    {
        if (dv.handleUserLogin("Manager") == false)
        {
            loginPage();
        }
        else
        {
        }
    }
    else if (userInput == "3")
    {
        if (dv.handleUserLogin("Admin") == false)
        {
            loginPage();
        }
        else
        {
            admin_HomePage();
        }
    }
    else
    {
        cout << endl
             << "Invalid input! Please try again." << endl;
        cout << endl;
        loginPage();
    }
}

void Asia_Pacific_Home::admin_HomePage()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "                            ADMIN                            " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "Please select an option (1-3):" << endl;
    cout << "1. Manage Manager Account" << endl;
    cout << "2. View Tenant Information" << endl;
    cout << "3. View Property Information" << endl;
    cout << "4. Logout" << endl;
    cout << ">> ";

    string userInput;
    getline(cin >> ws, userInput);
    cout << endl;

    if (userInput == "1")
    {
        admin_ManageManagerPage();
    } else if(userInput == "2") {
        admin_ViewTenantInfoPage();
    } else if(userInput == "3") {
        homePage();
    }
    else if (userInput == "4")
    {
        homePage();
    }
    else
    {
        cout << endl
             << "Invalid input! Please try again." << endl;
        cout << endl;
        admin_HomePage();
    }
}

void Asia_Pacific_Home::admin_ManageManagerPage()
{
    cout << "[MANAGER MANAGEMENT PAGE]" << endl;
    cout << "Please select an option (1-2):" << endl;
    cout << "1. Add New Manager" << endl;
    cout << "2. Mofify Account Status" << endl;
    cout << "3. Back" << endl;
    cout << ">> ";

    string userInput;
    getline(cin >> ws, userInput);
    cout << endl;

    if (userInput == "1")
    {
        // Admin add new manager
    }
    else if (userInput == "2")
    {
        admin_ModifyManagerStatusPage();
    }
    else if (userInput == "3")
    {
        admin_HomePage();
    }
    else
    {
        cout << endl
             << "Invalid input! Please try again." << endl;
        cout << endl;
        admin_HomePage();
    }
}

// void Asia_Pacific_Home::admin_AddNewManagerPage() {
//     DataValidation dv;
//     string name, email, phoneNo, identificationNo, gender, dateOfBirth, status;
//     cout << "[ADD NEW MANAGER ACCOUNT]" << endl;

void Asia_Pacific_Home::admin_AddNewManagerPage() {
    Admin admin;
    admin.addManager(managerList, tenantList);

    cout << "Input any key to back >> ";
    string userInput;
    getline(cin >> ws, userInput);
    cout << endl;
    admin_ManageManagerPage();
}

void Asia_Pacific_Home::admin_ModifyManagerStatusPage() {
    Admin admin;
    if (admin.updateManagerStatus(managerList) == true)
    {
        cout << "Status has been changed successfully!" << endl;

        cout << endl;
        cout << "Input any key to back >> ";
        string userInput;
        getline(cin >> ws, userInput);
        cout << endl;
        admin_ManageManagerPage();
    }
    else
    {
        cout << endl;
        admin_ManageManagerPage();
    }
}

void Asia_Pacific_Home::admin_ViewTenantInfoPage()
{
    cout << "[VIEW TENANT INFORMATION PAGE]" << endl;
    cout << "Available Tenant: " << tenantList.getSize() << endl;
    cout << endl;

    if(tenantList.getSize() == 0) {
        cout << "Tenant information not available...." << endl;
        cout << "Input any key to back >> ";
        string userInput;
        getline(cin >> ws, userInput);
        cout << endl;
        admin_HomePage();
    } else {
        Admin admin;
        if(admin.filterTenants(tenantList) == false) {
            admin_HomePage();
        } 

        
            cout << "Input any key to back >> ";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;
            admin_HomePage();
        
    }
}