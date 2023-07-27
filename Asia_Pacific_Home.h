#ifndef ASIA_PACIFIC_HOME_H
#define ASIA_PACIFIC_HOME_H

/**
 * FILENAME: Asia_Pacific_Home.h
 */

// #include <string>
// #include <iostream>
// #include <regex>

#include "DynamicArray.h"
#include "User.h"
#include "Manager.h"
#include "Tenant.h"
#include "Admin.h"
#include "FilterTenant.h"
#include "FilterProperty.h"
#include "BubbleSort.h"
#include "ReadCSV.h"
#include "Property.h"
#include "DataValidation.h"
#include "DataConversion.h"
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "DoublyCircularLinkedList.h"
#include "Rental.h"

using namespace std;

class Asia_Pacific_Home
{
private:
    DynamicArray<Manager> managerList;
    DynamicArray<Tenant> tenantList;
    DynamicArray<Property> properties;
    User user;

public:
    Asia_Pacific_Home()
    {
        Tenant newTenant("Wong Hau", "hello@gmail.com", "01234567890", "123123123", "Male", "abc@123", "2022-09-01", "2023-07-01");
        tenantList.insertAtEnd(newTenant);

        Tenant newTenant2("Hello", "Wuuha@gmail.com", "0987654321", "123123123", "Female", "abc@123", "2022-05-01", "2023-07-02");
        tenantList.insertAtEnd(newTenant2);

        Manager newManager("Jesus", "wong@gmail.com", "0987654321", "123123123", "Female", "2022-05-01", "Active");
        managerList.insertAtEnd(newManager);

        ReadCSV read;
        read.readCSV("mudah-apartment-kl-selangor.csv", properties);
    }

    void homePage()
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
        cout << "X. Close Program" << endl;
        cout << ">> ";

        string userInput;
        getline(cin >> ws, userInput);
        cout << endl;

        if (userInput == "1")
        {
            FilterProperty fp(user);
            if (fp.filterProperty(properties) == false)
            {
                homePage();
            }
            homePage();
        }
        else if (userInput == "2")
        {
            loginPage();
        }
        else if (userInput == "3")
        {
            signUpPage();
        }
        else if (userInput == "X")
        {
            cout << endl
                 << "Exiting... Bye!" << endl;
            exit(0);
        }
        else
        {
            cout << endl
                 << "Invalid input! Please try again." << endl;
            cout << endl;
            homePage();
        }
    }

    void loginPage()
    {
        bool validInput = false;

        while (!validInput)
        {
            cout << "Please select your user role (1-3):" << endl;
            cout << "1. Tenant" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Admin" << endl;
            cout << "[-1 to back]" << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "-1")
            {
                homePage();
            }
            else if (userInput == "1")
            {
                handleUserLogin("Tenant");
                validInput = true;
            }
            else if (userInput == "2")
            {
                handleUserLogin("Manager");
                validInput = true;
            }
            else if (userInput == "3")
            {
                handleUserLogin("Admin");
                validInput = true;
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again." << endl;
                cout << endl;
            }
        }
    }

    void handleUserLogin(const string &userRole)
    {
        string email;
        string password;

        cout << "Please enter the email address (-1 to back): ";
        getline(cin >> ws, email);
        cout << endl;
        if (email == "-1")
        {
            loginPage();
            return;
        }
        DataValidation dv;
        while (!dv.isEmailValid(email))
        {
            cout << "Invalid email, please try again (-1 to back): ";
            getline(cin >> ws, email);
            cout << endl;
            if (email == "-1")
            {
                loginPage();
                return;
            }
        }

        cout << "Please enter the password (-1 to back): ";
        getline(cin >> ws, password);
        cout << endl;
        if (password == "-1")
        {
            loginPage();
            return;
        }

        while (!loginValidation(email, password, userRole))
        {
            cout << "Invalid credentials, please try again!" << endl;
            cout << endl;
            cout << "Please enter the email address (-1 to back): ";
            getline(cin >> ws, email);
            cout << endl;
            if (email == "-1")
            {
                loginPage();
                return;
            }

            while (!dv.isEmailValid(email))
            {
                cout << "Invalid email, please try again (-1 to back): ";
                getline(cin >> ws, email);
                cout << endl;

                if (email == "-1")
                {
                    loginPage();
                    return;
                }
            }

            cout << "Please enter the password (-1 to back): ";
            getline(cin >> ws, password);
            cout << endl;

            if (password == "-1")
            {
                loginPage();
                return;
            }
        }
        if (userRole == "Admin")
        {
            Admin admin;
            this->user = admin;
            admin_HomePage(admin);
        }
        else if (userRole == "Tenant")
        {
            Tenant tenant = tenant.login(email, tenantList);
            this->user = tenant;
            tenant_HomePage(tenant);
        }
        else if (userRole == "Manager")
        {
            Manager manager = manager.login(email, managerList);
            if (manager.getStatus() == "Active")
            {
                manager_HomePage(manager);
            }
            else
            {
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

    bool loginValidation(string email, string password, string userRole)
    {
        DataConversion dc;
        if (userRole == "Tenant")
        {
            Tenant tenant;
            for (int i = 0; i < tenantList.getSize(); ++i)
            {
                tenant = tenantList.get(i);
                if (dc.toLowercase(tenant.getEmail()) == dc.toLowercase(email) && tenant.getPassword() == password)
                {
                    return true;
                }
            }
            return false;
        }
        else if (userRole == "Manager")
        {
            Manager manager;
            for (int i = 0; i < managerList.getSize(); ++i)
            {
                manager = managerList.get(i);
                if (dc.toLowercase(manager.getEmail()) == dc.toLowercase(email) && manager.getPassword() == password)
                {
                    return true;
                }
            }
            return false;
        }
        else if (userRole == "Admin")
        {
            Admin admin;
            if ((dc.toLowercase(email) == dc.toLowercase(admin.getEmail())) && (password == admin.getPassword()))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }

    void signUpPage()
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "                  NEW ACCOUNT SIGN UP PAGE                   " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;

        Tenant tenant;
        DynamicArray<string> existingEmail = getExistingEmail();
        bool tenantRegistration = tenant.registration(tenantList, existingEmail);

        if (tenantRegistration == false)
        {
            homePage();
        }
        else
        {
            loginPage();
        }
    }

    /**
     * --------------------------------------------------------------------------------------------
     */

    void admin_HomePage(Admin admin)
    {

        bool validInput = false;

        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "                            ADMIN                            " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << endl;

        while (!validInput)
        {
            cout << "Please select an option (1-4):" << endl;
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
                admin_ManageManagerPage(admin);
                validInput = true;
            }
            else if (userInput == "2")
            {
                admin_ViewTenantInfoPage(admin);
                validInput = true;
            }
            else if (userInput == "3")
            {
                admin_ViewPropertyInfoPage(admin);
                validInput = true;
            }
            else if (userInput == "4")
            {
                homePage();
                validInput = true;
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again." << endl;
                cout << endl;
            }
        }
    }

    void admin_ManageManagerPage(Admin admin)
    {
        bool validInput = false;

        while (!validInput)
        {
            cout << "[MANAGER MANAGEMENT PAGE]" << endl;
            cout << "Please select an option (1-3):" << endl;
            cout << "1. Add New Manager" << endl;
            cout << "2. Mofify Account Status" << endl;
            cout << "3. Back" << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1")
            {
                admin_AddNewManagerPage(admin);
                validInput = true;
            }
            else if (userInput == "2")
            {
                admin_ModifyManagerStatusPage(admin);
                validInput = true;
            }
            else if (userInput == "3")
            {
                admin_HomePage(admin);
                validInput = true;
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again." << endl;
                cout << endl;
            }
        }
    }

    void admin_AddNewManagerPage(Admin admin)
    {
        DynamicArray<string> existingEmail = getExistingEmail();
        admin.addManager(managerList, existingEmail);
        admin_ManageManagerPage(admin);
    }

    DynamicArray<string> getExistingEmail()
    {
        DynamicArray<string> existingEmail;

        int managerNum = managerList.getSize();
        int tenantNum = tenantList.getSize();

        for (int i = 0; i < managerNum; ++i)
        {
            Manager manager = managerList.get(i);
            existingEmail.insertAtEnd(manager.getEmail());
        }

        for (int i = 0; i < tenantNum; ++i)
        {
            Tenant tenant = tenantList.get(i);
            existingEmail.insertAtEnd(tenant.getEmail());
        }
        return existingEmail;
    }

    void admin_ModifyManagerStatusPage(Admin admin)
    {
        if (admin.updateManagerStatus(managerList) == true)
        {
            cout << "Status has been changed successfully!" << endl;

            cout << endl;
            cout << "Input any key to back >> ";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;
            admin_ManageManagerPage(admin);
        }
        else
        {
            cout << endl;
            admin_ManageManagerPage(admin);
        }
    }

    void admin_ViewTenantInfoPage(Admin admin)
    {
        cout << "[VIEW TENANT INFORMATION PAGE]" << endl;
        cout << "Available Tenant: " << tenantList.getSize() << endl;
        cout << endl;

        if (tenantList.getSize() == 0)
        {
            cout << "Tenant information not available...." << endl;
            cout << "Input any key to back >> ";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;
            admin_HomePage(admin);
        }
        else
        {
            FilterTenant filterTenant;
            if (filterTenant.filterTenants(tenantList) == false)
            {
                admin_HomePage(admin);
            }
            // cout << "Input any key to back >> ";
            // string userInput;
            // getline(cin >> ws, userInput);
            // cout << endl;
            admin_HomePage(admin);
        }
    }

    void admin_ViewPropertyInfoPage(Admin admin)
    {
        cout << "[VIEW PROPERTY INFORMATION PAGE]" << endl;
        cout << "Available Property: " << properties.getSize() << endl;
        cout << endl;

        if (properties.getSize() == 0)
        {
            cout << "Property information not available...." << endl;
            cout << "Input any key to back >> ";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;
            admin_HomePage(admin);
        }
        else
        {
            FilterProperty filterProperty(user);
            if (filterProperty.filterProperty(properties) == false)
            {
                admin_HomePage(admin);
            }
            admin_HomePage(admin);
        }
    }

    /**
     * --------------------------------------------------------------------------------------------
     */

    void updateTenantList(Tenant &tenant)
    {
        for (int count = 0; count < tenantList.getSize(); count++)
        {
            Tenant &tempTenant = tenantList.get(count);
            if (tempTenant.getEmail() == tenant.getEmail())
            {
                tenantList.replace(tenant, count);
            }
        }
    }

    void tenant_HomePage(Tenant &tenant)
    {
        bool validInput = false;

        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "                      ASIA PACIFIC HOME                      " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Welcome Tenant: " << tenant.getName() << endl;
        cout << endl;

        while (!validInput)
        {
            cout << endl;
            cout << "Please select an option (1-4):" << endl;
            cout << "1. View Property" << endl;
            cout << "2. Property Favourite List" << endl;
            cout << "3. Rent Request History" << endl;
            cout << "4. Logout" << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1")
            {
                tenant_viewProperty(tenant);

                validInput = true;
            }
            else if (userInput == "2")
            {
                /**
                 * TODO: Call tenant favourite property list
                 */
                tenant.viewFavouriteProperty();
            }
            else if (userInput == "3")
            {
                /**
                 * TODO: Call tenant rent request function
                 */
                tenant_rentRequest(tenant);
            }
            else if (userInput == "4")
            {
                updateTenantList(tenant);
                updateTenantList(tenant);
                User emptyUser;
                this->user = emptyUser;
                homePage();
                validInput = true;
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again."
                     << endl
                     << endl;
            }
        }
    }

    void tenant_viewProperty(Tenant &tenant)
    {
        bool validInput = false;
        /**
         * TODO: Call the function that display all property list
         */
        while (!validInput)
        {
            std::cout << "[VIEW PROPERTY PAGE]" << endl;
            std::cout << "Please select an option (1-3):" << endl;
            std::cout << "1. Sort" << endl;
            std::cout << "2. Search" << endl;
            std::cout << "3. Advanced Searching and Filtering Options" << endl;
            std::cout << "4. Back" << endl;
            std::cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1")
            {
                tenant_sortSelectionPage(tenant);
                validInput = true;
            }
            else if (userInput == "2")
            {
                tenant_searchSelectionPage(tenant);
                validInput = true;
            }
            else if (userInput == "3")
            {
                FilterProperty filterProperty(user, tenant);
                validInput = true;
                if (filterProperty.filterProperty(properties) == false)
                {
                    tenant_HomePage(tenant);
                }

                DoublyCircularLinkedList<Property> favPropList = filterProperty.getProperty();

                if (favPropList.getSize() > 0)
                {
                    tenant.addFavouriteList(favPropList);
                }

                tenant_HomePage(tenant);
            }
            else if (userInput == "4")
            {
                validInput = true;
                tenant_HomePage(tenant);
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again."
                     << endl
                     << endl;
            }
        }
    }

    void tenant_sortSelectionPage(Tenant &tenant)
    {
        bool validInput = false;

        while (!validInput)
        {
            std::cout << "[Sorting Algorithm Selection]" << endl;
            std::cout << "Please select an option (1-3):" << endl;
            std::cout << "1. Bubble Sort" << endl;
            std::cout << "2. Merge Sort" << endl;
            std::cout << "3. Back" << endl;
            std::cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            tenant_sortItemOptions(tenant, userInput);
        }
    }

    void tenant_sortItemOptions(Tenant &tenant, const string &sortTypeSelection)
    {
        bool validInput = false;
        while (!validInput)
        {
            std::cout << "[SORTING OPTIONS]" << endl;
            std::cout << "Please select an option (1-3):" << endl;
            std::cout << "1. Sort by Monthly Rent" << endl;
            std::cout << "2. Sort by Location" << endl;
            std::cout << "3. Sort by Size as per Square Feet" << endl;
            std::cout << "4. Back" << endl;
            std::cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1")
            {
                validInput = true;
            }
            else if (userInput == "2")
            {
            }
            else if (userInput == "3")
            {
            }
            else if (userInput == "4")
            {
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again."
                     << endl
                     << endl;
            }
        }
    }

    void tenant_searchSelectionPage(Tenant &tenant)
    {
        bool validInput = false;

        while (!validInput)
        {
            std::cout << "[Searching Algorithm Selection]" << endl;
            std::cout << "Please select an option (1-3):" << endl;
            std::cout << "1. Linear Search" << endl;
            std::cout << "2. Binary Search" << endl;
            std::cout << endl;
            std::cout << "-------------------------------------" << endl;
            std::cout << "[-1 to back]" << endl;
            std::cout << ">>> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1" || userInput == "2")
            {
                /**
                 * TODO: Call linear search function
                 */
                tenant_searchItemOptions(tenant, userInput);
                validInput = true;
            }
            else if (userInput == "-1")
            {
                validInput = true;
                tenant_viewProperty(tenant);
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again."
                     << endl
                     << endl;
            }
        }
    }

    void tenant_searchItemOptions(Tenant &tenant, const string &searchTypeSelection)
    {
        bool validInput = false;
        while (!validInput)
        {
            cout << "Searching Options (Search By) [1-2]:" << endl;
            cout << "1. Ads ID" << endl;
            cout << "2. Property Name" << endl;
            cout << endl;
            cout << "-------------------------------------" << endl;
            cout << "[-1 to back]" << endl;
            cout << ">>> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1" || userInput == "2")
            {
                // call search function
                tenant_search(tenant, searchTypeSelection, userInput);
                validInput = true;
            }
            else if (userInput == "-1")
            {
                validInput = true;
                tenant_searchSelectionPage(tenant);
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again."
                     << endl
                     << endl;
            }
        }
    }

    void tenant_search(Tenant &tenant, const string &searchType, const string &searchItem)
    {
        FilterProperty filterProperty(user, tenant);

        std::string search;

        int searchTypeInt = std::stoi(searchType);
        int searchItemInt = std::stoi(searchItem);

        if (searchType == "1")
        {
            LinearSearch ls;

            if (searchItem == "1")
            {
                // call linear search for ads ID
                cout << "Enter Ads ID: ";
                getline(cin >> ws, search);
                cout << endl;

                DynamicArray<Property> result = ls.searchByAdsID(properties, search);
                if (result.getSize() > 0)
                {
                    filterProperty.displayFilteredPropertyList(result);
                }
                else
                {
                    cout << "Sorry, no record found..." << endl;
                    cout << "Please try again." << endl;
                    cout << endl;
                }
                tenant_searchSelectionPage(tenant);
            }
            else if (searchItem == "2")
            {
                cout << "Enter relavant keyword (Property Name): ";
                getline(cin >> ws, search);
                cout << endl;

                DynamicArray<Property> result = ls.searchByPropertyName(properties, search);
                if (result.getSize() > 0)
                {
                    filterProperty.displayFilteredPropertyList(result);
                }
                else
                {
                    cout << "Sorry, no record found..." << endl;
                    cout << "Please try again." << endl;
                    cout << endl;
                }
                tenant_searchSelectionPage(tenant);
            }
        }
        else if (searchType == "2")
        {
            BinarySearch binSearch;

            if (searchItem == "1")
            {
                // call binary search for ads ID
                cout << "Enter Ads ID: ";
                getline(cin >> ws, search);
                cout << endl;

                DynamicArray<Property> result;
                binSearch.binarySearch_AdsId(properties, search, result);

                if (result.getSize() > 0)
                {
                    filterProperty.displayFilteredPropertyList(result);
                }
                else
                {
                    cout << "Sorry, no record found..." << endl;
                    cout << "Please try again." << endl;
                    cout << endl;
                }

                tenant_searchSelectionPage(tenant);
            }
            else if (searchItem == "2")
            {
                cout << "Enter relavant keyword (Property Name): ";
                getline(cin >> ws, search);
                cout << endl;

                DynamicArray<Property> result;
                binSearch.binarySearch_PropertyName(properties, search, result);

                if (result.getSize() > 0)
                {
                    filterProperty.displayFilteredPropertyList(result);
                }
                else
                {
                    cout << "Sorry, no record found..." << endl;
                    cout << "Please try again." << endl;
                    cout << endl;
                }
                tenant_searchSelectionPage(tenant);
            }
        }
    }

    void tenant_favouriteList(Tenant &tenant)
    {
        bool validInput = false;
        /**
         * TODO: Display tenant favourite list
         */
    }

    void tenant_rentRequest(Tenant &tenant)
    {
        /**
         * TODO: Display tenant rent request list
         */

        DoublyCircularLinkedList<Rental> rentalHistory = tenant.getRentalHistory();

        if (rentalHistory.getSize() > 0)
        {
            int propIndex = 1;

            while (true)
            {
                cout << endl;
                cout << "[RENTAL HISTORY]" << endl;

                std::string option = tenant.rentalRequestSummary();

                if (option == "1")
                {
                    tenant.extractSpecificStatusRequest(Pending);
                }
                else if (option == "2")
                {
                    tenant.extractSpecificStatusRequest(Approved);
                }
                else if (option == "3")
                {
                    tenant.extractSpecificStatusRequest(Rejected);
                }
                else if (option == "4")
                {
                    tenant.extractSpecificStatusRequest(Active);
                }
                else if (option == "5")
                {
                    tenant.extractSpecificStatusRequest(Inactive);
                }
                else if (option == "-1")
                {
                    cout << endl
                         << "Returning back..." << endl
                         << endl;
                    break;
                }
                else
                {
                    cout << endl
                         << "Invalid input! Please try again..." << endl;
                }
            }
        }
        else
        {
            cout << endl
                 << "You have no rental history..." << endl
                 << endl;
        }
    }

    /**
     * --------------------------------------------------------------------------------------------
     */

    void manager_HomePage(Manager manager)
    {
        cout << tenantList.get(0).getFavoriteProperty().getSize() << endl;

        bool validInput = false;

        while (!validInput)
        {
            std::cout << "-------------------------------------------------------------" << endl;
            std::cout << "-------------------------------------------------------------" << endl;
            std::cout << "                           MANAGER                           " << endl;
            std::cout << "-------------------------------------------------------------" << endl;
            std::cout << "Welcome Manager: " << manager.getName() << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "Please select an option (1-3):" << std::endl;
            std::cout << "1. Display All Registered Tenant' Details" << std::endl;
            std::cout << "2. Favorite Property List" << std::endl;
            std::cout << "3. View Property Information" << std::endl;
            std::cout << "4. Logout" << std::endl;
            std::cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "1")
            {
                /**
                 * TODO: display tenant detail
                 */
                validInput = true;
            }
            else if (userInput == "2")
            {
                /**
                 * TODO: favoratie property list
                 */
                DynamicArray<Property> allFavouriteList;
                manager.getAllFavouriteList(tenantList, allFavouriteList);
                cout << allFavouriteList.getSize() << endl;
                FilterProperty fp;
                fp.displayFilteredPropertyList(allFavouriteList);

                validInput = true;
            }
            else if (userInput == "3")
            {
                /**
                 * TODO:  property info
                 */
                validInput = true;
            }
            else if (userInput == "4")
            {
                validInput = true;
                homePage();
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again."
                     << endl
                     << endl;
            }
        }
    }

    void getAllFavouriteList(DynamicArray<Tenant> &tenantList, DynamicArray<Property> &allFavouriteProperty)
    {
        for (int count = 0; count < tenantList.getSize(); count++)
        {
            Tenant tenant = tenantList.get(count);

            for (int count2 = 0; count2 < tenant.getFavoriteProperty().getSize(); count2++)
            {
                allFavouriteProperty.insertAtEnd(tenant.getFavoriteProperty().get(count2));
            }
        }
    }

    /**
     * --------------------------------------------------------------------------------------------
     * GET SET
     */

    DynamicArray<Property> getPropertyList()
    {
        return this->properties;
    }
};

#endif