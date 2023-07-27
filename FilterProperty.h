#ifndef FILTERPROPERTY_H
#define FILTERPROPERTY_H

// #include <string>
// #include <vector>
// #include "Property.h"
// #include <iostream>
#include <cmath>
// #include "DataValidation.h"
// #include "Property.h"
// #include "DataConversion.h"
// #include "DoublyCircularLinkedList.h"
#include "User.h"
#include "Tenant.h"

using namespace std;

class FilterProperty {
    private:
        User user;
        Tenant tenant;
        DoublyCircularLinkedList<Property> propertyList;

    public:
    FilterProperty() {}

    FilterProperty(User &user) {
        this->user = user;
    }

    FilterProperty(User &user, Tenant &tenant) {
        this->user = user;
        this->tenant = tenant;
    }

    bool filterProperty(DynamicArray<Property>& properties) {
        // Implementation for displaying all property information
        DataValidation dv;
        Property property;
        DataConversion dc;

        bool validInput = false;
        while(!validInput) {
            cout << "Searching Options (Search By) [1]:" << endl;
            cout << "1. Property Name" << endl;
            cout << endl;

            cout << "Filtering Options (Filter By) [2-11]:" << endl;
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
                return false;
                break;

            } else if (userInput == "1") {
                string search;
                cout << "Enter relavant keyword (Property Name): ";
                getline(cin >> ws, search);
                cout << endl;
                validInput = true;
                filterByName(properties, dc.toLowercase(search));

            } else if (userInput == "2") {
                string search;
                long long minimum; long long maximum;
                bool check = false;
                while(!check) {
                    cout << "Enter minimum value (Monthly Rental): ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        minimum = stoi(search);
                        check = true;
                    } else {
                        cout << "Please enter digit only, try again!" << endl;
                    }
                    validInput = true;
                }

                check = false;
                while(!check) {
                    cout << "Enter maximum value (Monthly Rental): ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        maximum = stoi(search);
                        if(minimum > maximum) {
                            cout << "Invalid maximum value, please try again!" << endl;
                        } else if (maximum >= minimum) {
                            check = true;
                            filterByMonthlyRent(properties, minimum, maximum);
                        }
                        
                    } else {
                        cout << "Please enter digit only, try again!" << endl;
                    }
                    validInput = true;
                }

            } else if (userInput == "3") {
                string search;
                cout << "AVAILABLE LOCATIONS:" << endl;
                DynamicArray<string> locationList = property.getAvailableLocation(properties);
                for(int i = 0; i < locationList.getSize(); ++i) {
                    cout << i + 1 << ". " << locationList.get(i) << endl;
                }

                bool check = false;
                while(!check) {
                    cout << endl;
                    cout << "Enter the number of the desired region: ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        int selectedNum = stoi(search);
                        if(selectedNum > 0 && selectedNum <= locationList.getSize()) {
                            check = true;
                            filterByLocations(properties, locationList.get(selectedNum - 1));
                        } else {
                            cout << "Invalid input! Please enter within the range." << endl;
                        }
                    } else {
                        cout << "Invalid input! Please enter DIGIT only." << endl;
                    }
                }
                validInput = true;

            } else if (userInput == "4") {
                string search;
                cout << "AVAILABLE PROPERTY TYPE:" << endl;
                DynamicArray<string> propertyTypeList = property.getAvailablePropertyType(properties);
                for(int i = 0; i < propertyTypeList.getSize(); ++i) {
                    cout << i + 1 << ". " << propertyTypeList.get(i) << endl;
                }

                bool check = false;
                while(!check) {
                    cout << endl;
                    cout << "Enter the number of the desired property type: ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        int selectedNum = stoi(search);
                        if(selectedNum > 0 && selectedNum <= propertyTypeList.getSize()) {
                            check = true;
                            filterByPropertyType(properties, propertyTypeList.get(selectedNum - 1));
                        } else {
                            cout << "Invalid input! Please enter within the range." << endl;
                        }
                    } else {
                        cout << "Invalid input! Please enter DIGIT only." << endl;
                    }
                }
                validInput = true;

            } else if (userInput == "5") {
                string search;
                bool check = false;
                while(!check) {
                    cout << "Please select your desire number of rooms [1-5]:" << endl;
                    cout << "1. 1 Room" << endl;
                    cout << "2. 2 Rooms" << endl;
                    cout << "3. 3 Rooms" << endl;
                    cout << "4. 4 Rooms" << endl;
                    cout << "5. 5 Rooms and more" << endl;
                    cout << endl;
                    cout << "Enter the number: ";

                    getline(cin >> ws, search);
                    cout << endl;
                    
                    if(dv.isNumber(search)) {
                        int selectedNum = stoi(search);
                        if(selectedNum >= 1 && selectedNum <= 5) {
                            filterByRooms(properties, search);
                            check = true;
                        } else {
                            cout << "Invalid input! Please enter within the range." << endl;
                        }
                    } else {
                        cout << "Invalid input! Please enter DIGIT only." << endl;
                    }
                }
                validInput = true;

            } else if (userInput == "6") {
                string search;
                bool check = false;
                while(!check) {
                    cout << "Please select your desire number of parking [1-3]:" << endl;
                    cout << "1. 1 Parking" << endl;
                    cout << "2. 2 Parkings" << endl;
                    cout << "3. 3 Parkings and more" << endl;
                    cout << endl;
                    cout << "Enter the number: ";

                    getline(cin >> ws, search);
                    cout << endl;
                    
                    if(dv.isNumber(search)) {
                        int selectedNum = stoi(search);
                        if(selectedNum >= 1 && selectedNum <= 3) {
                            filterByParking(properties, search);
                            check = true;
                        } else {
                            cout << "Invalid input! Please enter within the range." << endl;
                        }
                    } else {
                        cout << "Invalid input! Please enter DIGIT only." << endl;
                    }
                }
                validInput = true;

            } else if (userInput == "7") {
                string search;
                bool check = false;
                while(!check) {
                    cout << "Please select your desire number of bathroom [1-3]:" << endl;
                    cout << "1. 1 Bathroom" << endl;
                    cout << "2. 2 Bathrooms" << endl;
                    cout << "3. 3 Bathrooms and more" << endl;
                    cout << endl;
                    cout << "Enter the number: ";

                    getline(cin >> ws, search);
                    cout << endl;
                    
                    if(dv.isNumber(search)) {
                        int selectedNum = stoi(search);
                        if(selectedNum >= 1 && selectedNum <= 3) {
                            filterByBathroom(properties, search);
                            check = true;
                        } else {
                            cout << "Invalid input! Please enter within the range." << endl;
                        }
                    } else {
                        cout << "Invalid input! Please enter DIGIT only." << endl;
                    }
                }
                validInput = true;

            } else if (userInput == "8") {
                string search;
                long long minimum; long long maximum;
                bool check = false;
                while(!check) {
                    cout << "Enter minimum value (sqft): ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        minimum = stoi(search);
                        check = true;
                    } else {
                        cout << "Please enter digit only, try again!" << endl;
                    }
                    validInput = true;
                }

                check = false;
                while(!check) {
                    cout << "Enter maximum value (sqft): ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        maximum = stoi(search);
                        if(minimum > maximum) {
                            cout << "Invalid maximum value, please try again!" << endl;
                        } else if (maximum >= minimum) {
                            check = true;
                            filterBySize(properties, minimum, maximum);
                        }
                        
                    } else {
                        cout << "Please enter digit only, try again!" << endl;
                    }
                    validInput = true;
                }

            } else if (userInput == "9") {
                string search;
                cout << "AVAILABLE FURNISHED TYPE:" << endl;
                DynamicArray<string> furnishedTypeList = property.getAvailableFurnishedType(properties);
                for(int i = 0; i < furnishedTypeList.getSize(); ++i) {
                    cout << i + 1 << ". " << furnishedTypeList.get(i) << endl;
                }

                bool check = false;
                while(!check) {
                    cout << endl;
                    cout << "Enter the number of the desired furnished type: ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        int selectedNum = stoi(search);
                        if(selectedNum > 0 && selectedNum <= furnishedTypeList.getSize()) {
                            check = true;
                            filterByFurnishedType(properties, furnishedTypeList.get(selectedNum - 1));
                        } else {
                            cout << "Invalid input! Please enter within the range." << endl;
                        }
                    } else {
                        cout << "Invalid input! Please enter DIGIT only." << endl;
                    }
                }
                validInput = true;

            } else if (userInput == "10") {
                string search;
                cout << "AVAILABLE REGIONS:" << endl;
                DynamicArray<string> regionList = property.getAvailableRegion(properties);
                for(int i = 0; i < regionList.getSize(); ++i) {
                    cout << i + 1 << ". " << regionList.get(i) << endl;
                }

                bool check = false;
                while(!check) {
                    cout << endl;
                    cout << "Enter the number of the desired region: ";
                    getline(cin >> ws, search);
                    cout << endl;
                    if(dv.isNumber(search)) {
                        int selectedNum = stoi(search);
                        if(selectedNum > 0 && selectedNum <= regionList.getSize()) {
                            check = true;
                            filterByRegion(properties, regionList.get(selectedNum - 1));
                        } else {
                            cout << "Invalid input! Please enter within the range." << endl;
                        }
                    } else {
                        cout << "Invalid input! Please enter DIGIT only." << endl;
                    }
                }
                validInput = true;

            } else if(userInput == "11") {
                displayFilteredPropertyList(properties);
                validInput = true;

            } else {
                cout << "Invalid input! Please try again." << endl;
                cout << endl;
            }
        }
        return true;
    }

    void filterByName(DynamicArray<Property>& properties, const string& search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string name = property.getPropName();
            if(name.find(search) != std::string::npos) {
                    temp.insertAtEnd(property);
            }
        } proceedMessage(properties, temp);
    }

    void filterByMonthlyRent(DynamicArray<Property>& properties, const long long& minimum, const long long& maximum) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string monthlyRent = property.getMonthlyRent();

            if(monthlyRent != "") {
                string result;
                for (char c : monthlyRent) {
                    if (std::isdigit(c)) {
                        result += c;
                    }
                }
                if(stoll(result) >= minimum && stoll(result) <= maximum) {
                    temp.insertAtEnd(property);
                }
            }
        } proceedMessage(properties, temp);
    }

    void filterByLocations(DynamicArray<Property>& properties, string search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string location = property.getLocation();
            if(location == search) {
                temp.insertAtEnd(property);
            }
        } proceedMessage(properties, temp);
    }

    void filterByPropertyType(DynamicArray<Property>& properties, string search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string propertyType = property.getPropertyType();
            if(propertyType == search) {
                temp.insertAtEnd(property);
            }
        } proceedMessage(properties, temp);
    }

    void filterByRooms(DynamicArray<Property>& properties, string search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string rooms = property.getRooms();
            if(search == "5") {
                if(rooms != "1" && rooms != "2" && rooms != "3" && rooms != "4" && rooms != "") {
                    temp.insertAtEnd(property);
                }
            } else {
                if(search == rooms) {
                    temp.insertAtEnd(property);
                } 
            }
        } proceedMessage(properties, temp);
    }

    void filterByParking(DynamicArray<Property>& properties, string search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string parking = property.getParking();
            if(search == "3") {
                if(parking != "1" && parking != "2" && parking != "") {
                    temp.insertAtEnd(property);
                }
            } else {
                if(search == parking) {
                    temp.insertAtEnd(property);
                } 
            }
        } proceedMessage(properties, temp);
    }

    void filterByBathroom(DynamicArray<Property>& properties, string search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string bathroom = property.getBathroom();
            if(search == "3") {
                if(bathroom != "1" && bathroom != "2" && bathroom != "") {
                    temp.insertAtEnd(property);
                }
            } else {
                if(search == bathroom) {
                    temp.insertAtEnd(property);
                } 
            }
        } proceedMessage(properties, temp);
    }

    void filterBySize(DynamicArray<Property>& properties, const long long& minimum, const long long& maximum) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string size = property.getSize();

            if(size != "") {
                string result;
                for (char c : size) {
                    if (std::isdigit(c)) {
                        result += c;
                    }
                }
                if(stoll(result) >= minimum && stoll(result) <= maximum) {
                    temp.insertAtEnd(property);
                }
            }
        } proceedMessage(properties, temp);
    }

    void filterByFurnishedType(DynamicArray<Property>& properties, string search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string furnishedType = property.getFurnished();
            if(furnishedType == search) {
                temp.insertAtEnd(property);
            }
        } proceedMessage(properties, temp);
    }

    void filterByRegion(DynamicArray<Property>& properties, string search) {
        DynamicArray<Property> temp;

        for(int i = 0; i < properties.getSize(); ++i) {
            Property property = properties.get(i);
            string region = property.getRegion();
            if(region == search) {
                temp.insertAtEnd(property);
            }
        } proceedMessage(properties, temp);
    }

    void proceedMessage(DynamicArray<Property>& properties, DynamicArray<Property>& temp) {
        if(temp.getSize() == 0) {
            cout << "Sorry, no record found..." << endl;
            cout << "Please try again." << endl;
            cout << endl;
            filterProperty(properties);
        } else if(temp.getSize() > 1) {
            bool flag = false;
            while(!flag) {
                string userInput;
                cout << "Additional Searching and Filtering Options? (Y/N): ";
                getline(cin >> ws, userInput);
                cout << endl;

                if(userInput == "Y" || userInput == "y") {
                    filterProperty(temp);
                    flag = true;
                } else if(userInput == "N" || userInput == "n") {
                    displayFilteredPropertyList(temp);
                    flag = true;
                } else {
                    cout << "Invalid input! Please try again..." << endl;
                }
            }
        } else if(temp.getSize() == 1) {
            displayFilteredPropertyList(temp);
        }
    }

    void displayFilteredPropertyList(DynamicArray<Property>& filteredList) {
        int pageSize = 5;  // Number of items to display per page
        int currentPage = 0;  // Current page index

        while (true) {
            int startIdx = currentPage * pageSize;
            int endIdx = startIdx + pageSize;

            cout << "[RESULT]" << endl;
            cout << "Page " << currentPage + 1 << " / " << ceil(static_cast<double>(filteredList.getSize())/pageSize) << endl;
            cout << "---------------------------\n";

            for (int i = startIdx; i < endIdx && i < filteredList.getSize(); ++i) {
                Property property = filteredList.get(i);
                std::cout << "NO: " << i + 1 << std::endl;
                std::cout << "Ads ID: " << property.getAdsID() << std::endl;
                std::cout << "Property Name: " << property.getPropName() << std::endl;
                std::cout << "Completion Year: " << property.getCompletionYear() << std::endl;
                std::cout << "Monthly Rent: " << property.getMonthlyRent() << std::endl;
                std::cout << "Location: " << property.getLocation() << std::endl;
                std::cout << "Property Type: " << property.getPropertyType() << std::endl;
                std::cout << "Rooms: " << property.getRooms() << std::endl;
                std::cout << "Parking: " << property.getParking() << std::endl;
                std::cout << "Bathroom: " << property.getBathroom() << std::endl;
                std::cout << "Size: " << property.getSize() << std::endl;
                std::cout << "Furnished: " << property.getFurnished() << std::endl;
                std::cout << "Facilities: " << property.getFacilities() << std::endl;
                std::cout << "Additional Facilities: " << property.getAdditionalFacilities() << std::endl;
                std::cout << "Region: " << property.getRegion() << std::endl;
                std::cout << "---------------------------\n";
            }

            if(user.getRole() == "Admin") {
                cout << "Options: (N)ext page, (P)revious page, (Q)uit" << endl;
                cout << ">> ";
            } else {
                cout << "Options: (N)ext page, (P)revious page, (Q)uit, (F)avourite List" << endl;
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

            } else if ((userInput == "F" || userInput == "f") && user.getRole()=="Tenant") {
                cout << endl;
                cout << "Please enter the respective Property No.: ";

                DataValidation dv;
                string choice;
                getline(cin >> ws, choice);
                cout << endl;

                if(dv.isNumber(choice)) {
                    if(stoi(choice) -1 >= startIdx && stoi(choice) -1 < endIdx && stoi(choice) -1 < filteredList.getSize()) {
                        cout << "[SELECTED PROPERTY]" << endl;
                        displaySingleProperty(filteredList.get(stoi(choice) - 1));
                        cout << endl;
                        cout << "Are you sure to add above property to your favourite list? (Y/N)" << endl;
                        cout << ">> ";

                        string confirm;
                        getline(cin >> ws, confirm);
                        cout << endl;

                        if(confirm == "Y" || confirm == "y") {
                            propertyList.insertAtEnd(filteredList.get(stoi(choice) - 1));

                            cout << endl;
                            cout << "[PROPERTY SAVED AS FAVOURITE SUCCESSFULLY]" << endl;
                            cout << "Enter any key to continue surfing: ";
                            string userInput;
                            getline(cin >> ws, userInput);
                            cout << endl;

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

            } 
            else if ((userInput == "F" || userInput == "f") && user.getRole()=="") {
                cout << "-Kindly login to an active account to make rent request.-" << endl;
                cout << "Enter any key to continue surfing: ";
                string userInput;
                getline(cin >> ws, userInput);
                cout << endl;
            }
            else {
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }

    void displaySingleProperty(const Property& property) {
        std::cout << "Ads ID: " << property.getAdsID() << std::endl;
        std::cout << "Property Name: " << property.getPropName() << std::endl;
        std::cout << "Completion Year: " << property.getCompletionYear() << std::endl;
        std::cout << "Monthly Rent: " << property.getMonthlyRent() << std::endl;
        std::cout << "Location: " << property.getLocation() << std::endl;
        std::cout << "Property Type: " << property.getPropertyType() << std::endl;
        std::cout << "Rooms: " << property.getRooms() << std::endl;
        std::cout << "Parking: " << property.getParking() << std::endl;
        std::cout << "Bathroom: " << property.getBathroom() << std::endl;
        std::cout << "Size: " << property.getSize() << std::endl;
        std::cout << "Furnished: " << property.getFurnished() << std::endl;
        std::cout << "Facilities: " << property.getFacilities() << std::endl;
        std::cout << "Additional Facilities: " << property.getAdditionalFacilities() << std::endl;
        std::cout << "Region: " << property.getRegion() << std::endl;
        std::cout << "---------------------------\n";
    }

    DoublyCircularLinkedList<Property> getProperty() {
        return this->propertyList;
    }
};

#endif