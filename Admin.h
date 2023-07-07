#ifndef ADMIN_H
#define ADMIN_H

/**
 * FILENAME: Admin.h
*/

#include <string>
#include <iomanip>
// #include <iostream>
// #include "Asia_Pacific_Home.h"

#include "DynamicArray.h"
// #include "Manager.h"
// #include "Tenant.h"
#include "User.h"
// #include "AccountManagement.h"
// #include "Property.h"
#include "DataValidation.h"
#include "DataConverstion.h"

using namespace std;

class Tenant;
class Manager;

class Admin : public User {
private:
    std::string email;
    std::string password;

public:
    Admin() {
        email = "admin@gmail.com";
        password = "Admin@1234";
    }


    string getEmail() const {
        return email;
    }

    string getPassword() const {
        return password;
    }

    void addManager(DynamicArray<Manager>& managerList, vector<string>& existingEmail) {
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

        while(isEmailExists(existingEmail, email) == true) {
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

        cout << "Input any key to back >> ";
        string userInput;
        getline(cin >> ws, userInput);
        cout << endl;
    }

    bool isEmailExists(vector<string>& existingEmail, const std::string& email) {
        Admin admin;
        if(email == admin.getEmail()) {
            return true;
        }

        int userNum = existingEmail.size();
        for (int i = 0; i < userNum; ++i) {
            if (existingEmail[i] == email) {
                return true;
            }
        }
        return false;
    }

    bool updateManagerStatus(DynamicArray<Manager>& managerList) {
        // Implementation for updating manager details
        cout << "Existing Manager Account Status:" << endl;
        cout << endl;
        int size = managerList.getSize();
        
        for (int i = 0; i < size; ++i) {
            Manager& manager = managerList.get(i);
            cout << setw(5) << right << i + 1 << ". ";
            cout << setw(25) << left << manager.getEmail();
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

    void deleteManager() {
        // Implementation for deleting a manager
    }

    bool filterTenants(DynamicArray<Tenant>& tenantList) {
        // Implementation for displaying all tenants
        DataValidation dv;

        string filterBy; string search;

        bool validInput = false;
        while(!validInput) {
            cout << "Searching Options (Search By) [1-4]:" << endl;
            cout << "1. Name" << endl;
            cout << "2. Email" << endl;
            cout << "3. Phone Number" << endl;
            cout << "4. Identification Number" << endl;
            cout << endl;

            cout << "Filtering Options (Filter By) [5-6]:" << endl;
            cout << "5. Gender" << endl;
            cout << "6. Date of Birth" << endl;
            cout << endl;

            cout << "7. DISPLAY ALL" << endl;
            cout << "-------------------------------------" << endl;
            cout << "[-1 to back]" << endl;
            cout << ">>> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if(userInput == "-1") {
                // APH->admin_HomePage();
                return false;

            } else if (userInput == "1") {
                filterBy = "Name";
                cout << "Enter relavant keyword (Name): ";
                getline(cin >> ws, search);
                cout << endl;
                validInput = true;

            } else if (userInput == "2") {
                filterBy = "Email";
                cout << "Enter relavant keyword (Email): ";
                getline(cin >> ws, search);
                cout << endl;
                validInput = true;

            } else if (userInput == "3") {
                filterBy = "Phone No";
                cout << "Enter relavant keyword (Phone Number): ";
                getline(cin >> ws, search);
                cout << endl;
                validInput = true;

            } else if (userInput == "4") {
                filterBy = "ID";
                cout << "Enter relavant keyword (Identification Number): ";
                getline(cin >> ws, search);
                cout << endl;
                validInput = true;

            } else if (userInput == "5") {
                filterBy = "Gender";
                cout << "Gender (1 - MALE; 2 - FEMALE): ";
                getline(cin >> ws, search);
                cout << endl;
                while(search!="1" && search!="2") {
                    cout << "Invalid input! Please try again (1 - MALE; 2 - FEMALE): ";
                    getline(cin >> ws, search);
                    cout << endl;
                }
                if(search == "1") {
                    search = "Male";
                } else {
                    search = "Female";
                }
                validInput = true;

            } else if (userInput == "6") {
                filterBy = "DOB";
                cout << "Date of Birth (YYYY-MM-DD): ";
                getline(cin >> ws, search);
                cout << endl;
                while(dv.isValidDateOfBirth(search) == false) {
                    cout << "Invalid date of birth! Please try again (YYYY-MM-DD): ";
                    getline(cin >> ws, search);
                    cout << endl;
                } validInput = true;

            } else if (userInput == "7") {
                filterBy = "ALL";
                cout << "Total Tenant Account: " << tenantList.getSize() << endl;
                cout << endl;
                displayFilteredTenantList(tenantList);
                validInput = true;

            } else {
                cout << "Invalid input! Please try again." << endl;
                cout << endl;
            }
        }
        if(filterBy != "ALL") {
            DataConversion dc;
            search = dc.toLowercase(search);
            tenantFilteringProcess(tenantList, filterBy, search);
        }
        return true;
    }

    void tenantFilteringProcess(DynamicArray<Tenant>& tenantList, const string& filterBy, const string& search) {
        DynamicArray<Tenant> temp;
        DataConversion dc;

        for(int i = 0; i < tenantList.getSize(); ++i) {
            Tenant tenant = tenantList.get(i);
            
            if(filterBy == "Name") {
                string name = dc.toLowercase(tenant.getName());
                if(name.find(search) != std::string::npos) {
                    temp.insertAtEnd(tenant);
                }
            } else if(filterBy == "Email") {
                string email = dc.toLowercase(tenant.getEmail());
                if(email.find(search) != std::string::npos) {
                    temp.insertAtEnd(tenant);
                }
            } else if(filterBy == "Phone No") {
                string phoneNo = tenant.getPhoneNo();
                if(phoneNo.find(search) != std::string::npos) {
                    temp.insertAtEnd(tenant);
                }
            } else if(filterBy == "ID") {
                string idNo = tenant.getIdentificationNo();
                if(idNo.find(search) != std::string::npos) {
                    temp.insertAtEnd(tenant);
                }
            } else if(filterBy == "Gender") {
                if(tenant.getGender() == search) {
                    temp.insertAtEnd(tenant);
                }
            } else if(filterBy == "DOB") {
                if(tenant.getDateOfBirth() == search) {
                    temp.insertAtEnd(tenant);
                }
            }
        }

        if(temp.getSize() == 0) {
            cout << "Sorry, no record found..." << endl;
            cout << "Please try again." << endl;
            cout << endl;
            filterTenants(tenantList);
        } else {
            bool flag = false;
            while(!flag) {
                string userInput;
                cout << "Additional Searching and Sorting Options? (Y/N): ";
                getline(cin >> ws, userInput);
                cout << endl;

                if(userInput == "Y") {
                    filterTenants(temp);
                    flag = true;
                } else if(userInput == "N") {
                    displayFilteredTenantList(temp);
                    flag = true;
                }
            }
        }
    }

    void displayFilteredTenantList(DynamicArray<Tenant>& filteredList) {
        cout << "[RESULT]" << endl;
        for(int i=0; i<filteredList.getSize(); ++i) {
            Tenant tenant = filteredList.get(i);
            std::cout << "Name: " << tenant.getName() << std::endl;
            std::cout << "Email: " << tenant.getEmail() << std::endl;
            std::cout << "Phone Number: " << tenant.getPhoneNo() << std::endl;
            std::cout << "Identification No: " << tenant.getIdentificationNo() << std::endl;
            std::cout << "Gender: " << tenant.getGender() << std::endl;
            std::cout << "Date of Birth: " << tenant.getDateOfBirth() << std::endl;
            // std::cout << "Status: " << tenant.getActivityStatus() << std::endl;
            std::cout << "---------------------------\n";
        }
    }
};


#endif