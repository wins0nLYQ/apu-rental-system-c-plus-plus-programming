#ifndef FILTERTENANT_H
#define FILTERTENANT_H

#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>
#include "Tenant.h"
#include "User.h"

using namespace std;

class FilterTenant {
private:
    User user;
    DynamicArray<Tenant> tenantList;
public:
    FilterTenant() {}
    FilterTenant(User &user) {
        this->user = user;
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
        string status;

        while (true) {
            int startIdx = currentPage * pageSize;
            int endIdx = startIdx + pageSize;

            cout << "[RESULT]" << endl;
            cout << "Page " << currentPage + 1 << " / " << ceil(static_cast<double>(filteredList.getSize())/pageSize) << endl;
            cout << "---------------------------\n";

            for (int i = startIdx; i < endIdx && i < filteredList.getSize(); ++i) {
                Tenant tenant = filteredList.get(i);
                std::cout << "NO: " << i + 1 << std::endl;
                std::cout << "Name: " << tenant.getName() << std::endl;
                std::cout << "Email: " << tenant.getEmail() << std::endl;
                std::cout << "Phone Number: " << tenant.getPhoneNo() << std::endl;
                std::cout << "Identification No: " << tenant.getIdentificationNo() << std::endl;
                std::cout << "Gender: " << tenant.getGender() << std::endl;
                std::cout << "Date of Birth: " << tenant.getDateOfBirth() << std::endl;
                std::cout << "Last Login: " << tenant.getLastLoginDate() << std::endl;
                std::tm givenDate = parseDateString(tenant.getLastLoginDate());
                int daysDifference = calculateDaysDifference(givenDate);
                if (daysDifference > 30){
                    status = "Inactive";
                }else{
                    status = "Active";
                }
                std::cout << "Status: " << status << std::endl;
                std::cout << "---------------------------\n";
            }
            if(user.getRole() == "Manager") {
                cout << "Options: (N)ext page, (P)revious page, (D)elete Account, (Q)uit" << endl;
                cout << ">> ";
            } else {
                cout << user.getRole() << endl;
                cout << "Options: (N)ext page, (P)revious page, (Q)uit" << endl;
                cout << ">> ";
            }

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
            }else if (userInput == "D" || userInput == "d" && user.getRole()=="Manager") {
                 cout << endl;
                cout << "Please enter the respective Tenant no: ";

                DataValidation dv;
                string choice;
                getline(cin >> ws, choice);
                cout << endl;

                if(dv.isNumber(choice)) {
                    if(stoi(choice) -1 >= startIdx && stoi(choice) -1 < endIdx && stoi(choice) -1 < filteredList.getSize()) {
                        cout << "[SELECTED TENANT]" << endl;
                        displaySingleFilteredTenantList(filteredList.get(stoi(choice) - 1));
                        cout << endl;
                        cout << "Are you sure to delete the above Tenant account? (Y/N)" << endl;
                        cout << ">> ";

                        string confirm;
                        getline(cin >> ws, confirm);
                        cout << endl;

                        if(confirm == "Y" || confirm == "y") {
                            if(status == "Active"){
                                cout << "Action Failed !! Tenant Accound is Active!! " << endl;
                                cout << "Enter any key to continue surfing: ";
                                string userInput;
                                getline(cin >> ws, userInput);
                                cout << endl;
                            }else{
                                removeTenant(filteredList,stoi(choice)-1);
                                cout << endl;
                                cout << "[TENANT ACCOUNT DELETED]" << endl;
                                cout << "Enter any key to continue surfing: ";
                                string userInput;
                                getline(cin >> ws, userInput);
                                cout << endl;
                            }

                        } else if(confirm == "N" || confirm == "n") {
                            cout << "Enter any key to continue surfing: ";
                            string userInput;
                            getline(cin >> ws, userInput);
                            cout << endl;

                        } else {
                            cout << "Invalid input! Please try again..." << endl;
                            cout << endl;
                        }

                    } else {
                        cout << "Invalid input! Please try again..." << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Enter digit ONLY! Please try again..." << endl;
                    cout << endl;
                }
            } else {
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }

    tm parseDateString(const string& dateString) {
        tm dateStruct = {};
        istringstream dateStream(dateString);
        dateStream >> get_time(&dateStruct, "%Y-%m-%d");
        if (dateStream.fail()) {
            cerr << "Error parsing date string: " << dateString << endl;
        }
        return dateStruct;
    }

    int calculateDaysDifference(const tm& givenDate) {
        time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        tm currentDate = *localtime(&now);

        chrono::system_clock::time_point currentTimePoint =
            chrono::system_clock::from_time_t(mktime(&currentDate));

        chrono::system_clock::time_point givenTimePoint =
            chrono::system_clock::from_time_t(mktime(const_cast<tm*>(&givenDate)));

        chrono::duration<double> diff = currentTimePoint - givenTimePoint;
        int daysDifference = static_cast<int>(chrono::duration_cast<chrono::hours>(diff).count() / 24);

        return daysDifference;
    }

    void displaySingleFilteredTenantList(const Tenant& tenant) {
        string status;
        std::cout << "Name: " << tenant.getName() << std::endl;
        std::cout << "Email: " << tenant.getEmail() << std::endl;
        std::cout << "Phone Number: " << tenant.getPhoneNo() << std::endl;
        std::cout << "Identification No: " << tenant.getIdentificationNo() << std::endl;
        std::cout << "Gender: " << tenant.getGender() << std::endl;
        std::cout << "Date of Birth: " << tenant.getDateOfBirth() << std::endl;
        std::cout << "Last Login: " << tenant.getLastLoginDate() << std::endl;
        std::tm givenDate = parseDateString(tenant.getLastLoginDate());
        int daysDifference = calculateDaysDifference(givenDate);
        if (daysDifference > 30){
            status = "Inactive";
        }else{
            status = "Active";
        }
        std::cout << "Status: " << status << std::endl;
        std::cout << "---------------------------\n";
    }

    void removeTenant(DynamicArray<Tenant>& tenantList, int index) {
    if (index >= 0 && index < tenantList.getSize()) {
        tenantList.removeAt(index);
    } else {
        // Handle invalid index error
        throw std::out_of_range("Invalid index");
    }
}

};

#endif