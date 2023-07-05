#include <string>
#include <vector>
#include "Property.h"
#include <iostream>
#include <DataValidation.h>
#include "Asia_Pacific_Home.h"

using namespace std;

class FilterProperty {

    public:

    void filterProperty(vector<Property>& properties) {
        // Implementation for displaying all property information
        DataValidation dv;

        string filterBy; string search;

        bool validInput = false;
        while(!validInput) {
            cout << "Searching Options (Search By) [1]:" << endl;
            cout << "1. Property Name" << endl;
            cout << endl;

            cout << "Filtering Options (Filter By) [2-10]:" << endl;
            cout << "2. Monthly Rent" << endl;
            cout << "3. Location" << endl;
            cout << "4. Property Type" << endl;
            cout << "5. Rooms" << endl;
            cout << "6. Parking" << endl;
            cout << "7. Bathroom" << endl;
            cout << "8. Size" << endl;
            cout << "9. Furnished" << endl;
            cout << "10. Region" << endl;
            cout << endl;

            cout << "11. DISPLAY ALL" << endl;
            cout << "-------------------------------------" << endl;
            cout << "[-1 to back]" << endl;
            cout << ">>> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if(userInput == "-1") {
                Asia_Pacific_Home APH;
                APH.admin_HomePage();
                break;

            } else if (userInput == "1") {
                filterBy = "Property Name";
                cout << "Enter relavant keyword (Property Name): ";
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
            tenantFilteringProcess(tenantList, filterBy, search);
        }
    }
};