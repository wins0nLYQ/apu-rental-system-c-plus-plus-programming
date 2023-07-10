#ifndef ASIA_PACIFIC_HOME_H
#define ASIA_PACIFIC_HOME_H

/**
 * FILENAME: Asia_Pacific_Home.h
*/

#include <string>
#include "User.h"
#include <iostream>
#include <regex>
#include "DynamicArray.h"
#include "Manager.h"
#include "Tenant.h"
#include "Admin.h"
#include "FilterTenant.h"
#include "FilterProperty.h"
// #include "DataValidation.h"

#include "ReadCSV.h"
#include "Property.h"

using namespace std;

class Asia_Pacific_Home {
private:
    DynamicArray<Manager> managerList;
    DynamicArray<Tenant> tenantList;
    DynamicArray<Property> properties;

public:
    void homePage() {
        Tenant newTenant("Wong Hau", "hello@gmail.com", "01234567890", "123123123", "Male", "2022-09-01", "hello");
        tenantList.insertAtEnd(newTenant);

        Tenant newTenant2("Hello", "Wuuha@gmail.com", "0987654321", "123123123", "Female", "2022-05-01", "hi");
        tenantList.insertAtEnd(newTenant2);

        Manager newManager("Jesus", "wong@gmail.com", "0987654321", "123123123", "Female", "2022-05-01", "Inactive");
        managerList.insertAtEnd(newManager);

        ReadCSV read;
        properties = read.readCSV("mudah-apartment-kl-selangor.csv");

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

    void loginPage() {
        bool validInput = false;
        // User user;

        while (!validInput) {
            cout << "Please select your user role (1-3):" << endl;
            cout << "1. Tenant" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Admin" << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1") {
                handleUserLogin("Tenant");
                validInput = true;
            }
            else if (userInput == "2") {
                handleUserLogin("Manager");
                validInput = true;
            }
            else if (userInput == "3") {
                handleUserLogin("Admin");
                validInput = true;
                // if (validInput) {
                //     admin_HomePage();
                // }
            }
            else {
                cout << endl << "Invalid input! Please try again." << endl;
                cout << endl;
            }
        }
    }



    void handleUserLogin(const string& userRole) {
        string email;
        string password;

        cout << "Please enter the email address (-1 to back): ";
        getline(cin >> ws, email);
        cout << endl;
        if(email == "-1") {
            // return false;
            loginPage();
        }
        DataValidation dv;
        while (!dv.isEmailValid(email)) {
            cout << "Invalid email, please try again (-1 to back): ";
            getline(cin >> ws, email);
            cout << endl;
            if(email == "-1") {
                // return false;
                loginPage();
            }
        }

        cout << "Please enter the password (-1 to back): ";
        getline(cin >> ws, password);
        cout << endl;
        if(password == "-1") {
            // return false;
            loginPage();
        }

        while (!loginValidation(email, password, userRole)) {
            cout << "Invalid credentials, please try again!" << endl;
            cout << endl;
            cout << "Please enter the email address (-1 to back): ";
            getline(cin >> ws, email);
            cout << endl;

            if(email == "-1") {
                // return false;
                loginPage();
            }

            while (!dv.isEmailValid(email)) {
                cout << "Invalid email, please try again (-1 to back): ";
                getline(cin >> ws, email);
                cout << endl;

                if(email == "-1") {
                    // return false;
                    loginPage();
                }
            }

            cout << "Please enter the password (-1 to back): ";
            getline(cin >> ws, password);
            cout << endl;

            if(password == "-1") {
                // return false;
                loginPage();
            }
        }
        // return true;
        if(userRole == "Admin") {
            admin_HomePage();
        } else if(userRole == "Tenant") {
            Tenant tenant = tenant.login(email, tenantList);
            tenant_HomePage(tenant);

        } else if(userRole == "Manager") {
            Manager manager = manager.login(email, managerList);
            if(manager.getStatus() == "Active") {
                manager_HomePage(manager);
            } else {
                cout << "Sorry to inform that you do not have access to this account anymore." << endl;
                cout << "Please contact admin for further information." << endl;
                cout << endl;

                cout << "Input any key to proceed >> ";
                string input;
                getline(cin >> ws, input);
                cout << endl;
                loginPage();
            }
        }
    }

    bool loginValidation(string email, string password, string userRole) {
        if (userRole == "Tenant") {
            Tenant tenant;
            for(int i = 0; i < tenantList.getSize(); ++i) {
                tenant = tenantList.get(i);
                if(tenant.getEmail() == email && tenant.getPassword()==password) {
                    return true;
                }
            } return false;

        } else if (userRole == "Manager") {
            Manager manager;
            for(int i = 0; i < managerList.getSize(); ++i) {
                manager = managerList.get(i);
                if(manager.getEmail() == email && manager.getPassword()==password) {
                    return true;
                }
            } return false;

        } else if (userRole == "Admin") {
            if ((email == "admin@gmail.com") && (password == "Admin@1234")) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }










/**
 * --------------------------------------------------------------------------------------------
*/


    void admin_HomePage() {
        bool validInput = false;

        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "                            ADMIN                            " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;

        while (!validInput) {
            cout << "Please select an option (1-4):" << endl;
            cout << "1. Manage Manager Account" << endl;
            cout << "2. View Tenant Information" << endl;
            cout << "3. View Property Information" << endl;
            cout << "4. Logout" << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1") {
                admin_ManageManagerPage();
                validInput = true;
            } else if(userInput == "2") {
                admin_ViewTenantInfoPage();
                validInput = true;
            } else if(userInput == "3") {
                admin_ViewPropertyInfoPage();
                validInput = true;
            } else if(userInput == "4") {
                homePage();
                validInput = true;
            } else {
                cout << endl << "Invalid input! Please try again." << endl;
                cout << endl;
            }
        }
    }

    void admin_ManageManagerPage()
    {
        bool validInput = false;

        while(!validInput) {
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
                admin_AddNewManagerPage();
                validInput = true;
            }
            else if (userInput == "2")
            {
                admin_ModifyManagerStatusPage();
                validInput = true;
            }
            else if (userInput == "3")
            {
                admin_HomePage();
                validInput = true;
            }
            else
            {
                cout << endl << "Invalid input! Please try again." << endl;
                cout << endl;
            }                                               
        }       
    }               

    void admin_AddNewManagerPage() {
        Admin admin;
        vector<string> existingEmail = getExistingEmail();
        admin.addManager(managerList, existingEmail);
        admin_ManageManagerPage();
    }

    vector<string> getExistingEmail() {
        vector<string> existingEmail;

        int managerNum = managerList.getSize();
        int tenantNum = tenantList.getSize();

        for (int i = 0; i < managerNum; ++i) {
            Manager manager = managerList.get(i);
            existingEmail.push_back(manager.getEmail());
        }

        for (int i = 0; i < tenantNum; ++i) {
            Tenant tenant = tenantList.get(i);
            existingEmail.push_back(tenant.getEmail());
        }
        return existingEmail;
    }

    void admin_ModifyManagerStatusPage() {
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

    void admin_ViewTenantInfoPage() {
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
            FilterTenant filterTenant;
            if (filterTenant.filterTenants(tenantList) == false) {
                admin_HomePage();
            }
            cout << "Input any key to back >> ";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;
            admin_HomePage();
            
        }
    }

    void admin_ViewPropertyInfoPage() {
        cout << "[VIEW PROPERTY INFORMATION PAGE]" << endl;
        cout << "Available Property: " << properties.getSize() << endl;
        cout << endl;

        if(properties.getSize() == 0) {
            cout << "Property information not available...." << endl;
            cout << "Input any key to back >> ";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;
            admin_HomePage();
        } else {
            FilterProperty filterProperty;
            if (filterProperty.filterProperty(properties) == false) {
                admin_HomePage();
            }
            admin_HomePage();
        }
    }



/**
 * --------------------------------------------------------------------------------------------
*/


    void tenant_HomePage(Tenant tenant) {
        cout << "Welcome Tenant: " << tenant.getName() << endl;
    }





/**
 * --------------------------------------------------------------------------------------------
*/



    void manager_HomePage(Manager manager) {
        cout << "Welcome Manager: " << manager.getName() << endl;
    }


};

#endif