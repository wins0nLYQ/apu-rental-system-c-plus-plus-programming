#ifndef FILTERTENANT_H
#define FILTERTENANT_H

// #include <string>
#include <iostream>
#include <cmath>
// #include "DynamicArray.h"
// #include "DataValidation.h"
// #include "DataConversion.h"
#include "Tenant.h"

using namespace std;

class FilterTenant {
public:
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
                string idNo = dc.toLowercase(tenant.getIdentificationNo());
                if(idNo.find(search) != std::string::npos) {
                    temp.insertAtEnd(tenant);
                }
            } else if(filterBy == "Gender") {
                if(dc.toLowercase(tenant.getGender()) == search) {
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
        } else if(temp.getSize() > 1){
            bool flag = false;
            while(!flag) {
                string userInput;
                cout << "Additional Searching and Filtering Options? (Y/N): ";
                getline(cin >> ws, userInput);
                cout << endl;

                if(userInput == "Y" || userInput == "y") {
                    filterTenants(temp);
                    flag = true;
                } else if(userInput == "N" || userInput == "n") {
                    displayFilteredTenantList(temp);
                    flag = true;
                } else {
                    cout << "Invalid input! Please try again..." << endl;
                }
            }
        } else if(temp.getSize() == 1) {
            displayFilteredTenantList(temp);
        }
    }

    // void displayFilteredTenantList(DynamicArray<Tenant>& filteredList) {
    //     cout << "[RESULT]" << endl;
    //     for(int i=0; i<filteredList.getSize(); ++i) {
    //         Tenant tenant = filteredList.get(i);
    //         std::cout << "Name: " << tenant.getName() << std::endl;
    //         std::cout << "Email: " << tenant.getEmail() << std::endl;
    //         std::cout << "Phone Number: " << tenant.getPhoneNo() << std::endl;
    //         std::cout << "Identification No: " << tenant.getIdentificationNo() << std::endl;
    //         std::cout << "Gender: " << tenant.getGender() << std::endl;
    //         std::cout << "Date of Birth: " << tenant.getDateOfBirth() << std::endl;
    //         // std::cout << "Status: " << tenant.getActivityStatus() << std::endl;
    //         std::cout << "---------------------------\n";
    //     }
    // }

    void displayFilteredTenantList(DynamicArray<Tenant>& filteredList) {
        int pageSize = 5;  // Number of items to display per page
        int currentPage = 0;  // Current page index

        while (true) {
            int startIdx = currentPage * pageSize;
            int endIdx = startIdx + pageSize;

            cout << "[RESULT]" << endl;
            cout << "Page " << currentPage + 1 << " / " << ceil(static_cast<double>(filteredList.getSize())/pageSize) << endl;
            cout << "---------------------------\n";

            for (int i = startIdx; i < endIdx && i < filteredList.getSize(); ++i) {
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
            cout << "Options: (N)ext page, (P)revious page, (Q)uit" << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "N" || userInput == "n") {
                if (endIdx < filteredList.getSize()) {
                    currentPage++;
                } else {
                    cout << "No more items. Reached the last page." << endl;
                }
            } else if (userInput == "P" || userInput == "p") {
                if (currentPage > 0) {
                    currentPage--;
                } else {
                    cout << "Already on the first page." << endl;
                }
            } else if (userInput == "Q" || userInput == "q") {
                break;  // Exit the loop
            } else {
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }

};

#endif