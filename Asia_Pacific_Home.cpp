/**
 * FILENAME: Asia_Pacific_Home.cpp
 */

#include <iostream>
#include <regex>
#include "Asia_Pacific_Home.h"
#include "UserAccount_Manager.h"
#include "Manager.h"
#include "Tenant.h"
#include "DataValidation.h"
#include "Admin.h"

using namespace std;

UserAccount_Manager<Manager> managerList;
UserAccount_Manager<Tenant> tenantList;

void Asia_Pacific_Home::homePage()
{
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
    }
    else if (userInput == "2")
    {
        cout << "Option 2";
    }
    else if (userInput == "3")
    {
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

//     cout << "Name: ";
//     getline(cin >> ws, name);
//     cout << endl;

//     cout << "Email: ";
//     getline(cin >> ws, email);
//     cout << endl;
//     while(dv.isEmailValid(email) == false) {
//         cout << "Invalid email! Please try again: ";
//         getline(cin >> ws, email);
//         cout << endl;
//     }
//     while(managerList.isEmailExists(email) == true) {
//         cout << "Email exist! Please try another one: ";
//         getline(cin >> ws, email);
//         cout << endl;
//     }
//     while(tenantList.isEmailExists(email) == true) {
//         cout << "Email exist! Please try another one: ";
//         getline(cin >> ws, email);
//         cout << endl;
//     }

//     cout << "Phone Number: ";
//     getline(cin >> ws, phoneNo);
//     cout << endl;
//     while(dv.isValidPhoneNumber(phoneNo) == false) {
//         cout << "Phone number should be 10-11 digits! Please try again: ";
//         getline(cin >> ws, phoneNo);
//         cout << endl;
//     }

//     cout << "Identification No: ";
//     getline(cin >> ws, identificationNo);
//     cout << endl;

//     cout << "Gender (1 - MALE; 2 - FEMALE): ";
//     getline(cin >> ws, gender);
//     cout << endl;
//     while(gender!="1" && gender!="2") {
//         cout << "Invalid input! Please try again (1 - MALE; 2 - FEMALE): ";
//         getline(cin >> ws, gender);
//         cout << endl;
//     }
//     if(gender == "1") {
//         gender = "Male";
//     } else {
//         gender = "Female";
//     }

//     cout << "Date of Birth (YYYY-MM-DD): ";
//     getline(cin >> ws, dateOfBirth);
//     cout << endl;
//     while(dv.isValidDateOfBirth(dateOfBirth) == false) {
//         cout << "Invalid date of birth! Please try again (YYYY-MM-DD): ";
//         getline(cin >> ws, dateOfBirth);
//         cout << endl;
//     }

//     cout << "Status (0 - INACTIVE; 1 - ACTIVE): ";
//     getline(cin >> ws, status);
//     cout << endl;
//     while(status!="0" && status!="1") {
//         cout << "Invalid input! Please try again (0 - INACTIVE; 1 - ACTIVE): ";
//         getline(cin >> ws, status);
//         cout << endl;
//     }
//     if(status == "0") {
//         status = "Inactive";
//     } else {
//         status = "Active";
//     }

//     Manager newManager(name, email, phoneNo, identificationNo, gender, dateOfBirth, status);
//     managerList.add(newManager);

//     cout << "User account created successfully!" << endl;
//     managerList.displayLatest("MANAGER");
//     cout << "Default login password: abc@1234" << endl;
//     cout << endl;

//     cout << "Input any key to back >> ";
//     string userInput;
//     getline(cin >> ws, userInput);
//     cout << endl;
//     admin_ManageManagerPage();
// }

void Asia_Pacific_Home::admin_ModifyManagerStatusPage()
{
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
    cout << "Available Tenant: " << managerList.getSize() << endl;
    cout << endl;

    if (managerList.getSize() == 0)
    {
        cout << "Tenant information not available...." << endl;
    }
    else
    {
        cout << "Filtering Options (Filter By) [1-7]:" << endl;
        cout << "1. Name" << endl;
        cout << "2. Email" << endl;
        cout << "3. Phone Number" << endl;
        cout << "4. Identification Number" << endl;
        cout << "5. Gender" << endl;
        cout << "6. Date of Birth" << endl;
        cout << "7. DISPLAY ALL" << endl;

        cout << ">>> " << endl;
    }
}