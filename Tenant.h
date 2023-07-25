#ifndef TENANT_H
#define TENANT_H

/**
 * FILENAME: Tenant.h
*/

#include "User.h"
#include "DoublyCircularLinkedList.h"
#include "Property.h"
#include "DataConversion.h"
#include "Admin.h"
#include "Rental.h"
#include <ctime>
// #include "FilterProperty.h"

using namespace std;

class Tenant : public User {
  private:
    string lastLoginDate;
    DoublyCircularLinkedList<Property> favouriteList;
    DoublyCircularLinkedList<Rental> rentalHistory;

  public:
    Tenant(){}

    Tenant(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
                const std::string& _identificationNo, const std::string& _gender, const std::string& _password,
                const std::string& _dateOfBirth, const std::string& _lastLoginDate)
            : User(_name, _email, _phoneNo, _identificationNo, _gender, _password, _dateOfBirth, "Tenant"),
              lastLoginDate(_lastLoginDate) {
        }

    string getLastLoginDate() const {
        return lastLoginDate;
    }

    void setLastLoginDate(const string& lastLoginDate) {
        this->lastLoginDate = lastLoginDate;
    }

    void addFavouriteList(DoublyCircularLinkedList<Property> &newFavList) {
        this->favouriteList.mergeWith(newFavList);
    }

    bool registration(DynamicArray<Tenant>& tenantList, DynamicArray<string>& existingEmail) {
        // Implementation of tenant registration logic
        DataValidation dv;
        string name, email, phoneNo, identificationNo, gender, password, dateOfBirth, lastLoginDate;
        cout << "[ADD NEW USER ACCOUNT]" << endl;
        cout << "Enter '-1' to back to previous page." << endl;
        cout << endl;

        cout << "Name: ";
        getline(cin >> ws, name);
        cout << endl;

        if(name == "-1") {
            return false;
        }

        cout << "Email: ";
        getline(cin >> ws, email);
        cout << endl;

        if(email == "-1") {
            return false;
        }

        while(dv.isEmailValid(email) == false || isEmailExists(existingEmail, email) == true) {
            if (dv.isEmailValid(email) == false) {
                cout << "Invalid email! Please try again: ";
                getline(cin >> ws, email);
                cout << endl;
                if(email == "-1") {
                    return false;
                }

            } else if (isEmailExists(existingEmail, email) == true){
                cout << "Email exist! Please try another one: ";
                getline(cin >> ws, email);
                cout << endl;
                if(email == "-1") {
                    return false;
                }
            }
        }

        cout << "Phone Number: ";
        getline(cin >> ws, phoneNo);
        cout << endl;

        if(phoneNo == "-1") {
            return false;
        }

        while(dv.isValidPhoneNumber(phoneNo) == false) {
            cout << "Phone number should be 10-11 digits! Please try again: ";
            getline(cin >> ws, phoneNo);
            cout << endl;
            if(phoneNo == "-1") {
                return false;
            }
        }

        cout << "Identification No: ";
        getline(cin >> ws, identificationNo);
        cout << endl;

        if(identificationNo == "-1") {
            return false;
        }

        while(dv.isValidID(identificationNo) == false) {
            cout << "ID number should be 6-15 characters! Please try again: ";
            getline(cin >> ws, identificationNo);
            cout << endl;
            if(identificationNo == "-1") {
                return false;
            }
        }

        cout << "Gender (1 - MALE; 2 - FEMALE): ";
        getline(cin >> ws, gender);
        cout << endl;

        if(gender == "-1") {
            return false;
        }

        while(gender!="1" && gender!="2") {
            cout << "Invalid input! Please try again (1 - MALE; 2 - FEMALE): ";
            getline(cin >> ws, gender);
            cout << endl;
            if(gender == "-1") {
                return false;
            }
        }
        if(gender == "1") {
            gender = "Male";
        } else {
            gender = "Female";
        }

        cout << "Password: " << endl;
        cout << "- Minimum length of 8 characters." << endl;
        cout << "- At least one UPPERCASE." << endl;
        cout << "- At least one lowercase." << endl;
        cout << "- At least one digit." << endl;
        cout << "- At least one special character." << endl;
        cout << ">>> ";
        getline(cin >> ws, password);
        cout << endl;

        if(password == "-1") {
            return false;
        }

        while(dv.isValidPassword(password) == false) {
            cout << "Invalid password! Please try again: ";
            getline(cin >> ws, password);
            cout << endl;
            if(password == "-1") {
                return false;
            }
        }

        cout << "Date of Birth (YYYY-MM-DD): ";
        getline(cin >> ws, dateOfBirth);
        cout << endl;

        if(dateOfBirth == "-1") {
            return false;
        }

        while(dv.isValidDateOfBirth(dateOfBirth) == false) {
            cout << "Invalid date of birth! Please try again (YYYY-MM-DD): ";
            getline(cin >> ws, dateOfBirth);
            cout << endl;
            if(dateOfBirth == "-1") {
                return false;
            }
        }

        DataConversion dc;
        string loginDate = dc.getTodayDate();
        Tenant newTenant(name, email, phoneNo, identificationNo, gender, password, dateOfBirth, loginDate);
        tenantList.insertAtEnd(newTenant);

        cout << "User account created successfully!" << endl;

        std::cout << "Name: " << newTenant.getName() << std::endl;
        std::cout << "Email: " << newTenant.getEmail() << std::endl;
        std::cout << "Phone Number: " << newTenant.getPhoneNo() << std::endl;
        std::cout << "Identification No: " << newTenant.getIdentificationNo() << std::endl;
        std::cout << "Gender: " << newTenant.getGender() << std::endl;
        std::cout << "Date of Birth: " << newTenant.getDateOfBirth() << std::endl;
        std::cout << "---------------------------\n";

        cout << "You may proceed the login page and login with your account." << endl;
        cout << "Input any key to back >> ";
        string userInput;
        getline(cin >> ws, userInput);
        cout << endl;

        return true;
    }

    bool isEmailExists(DynamicArray<string>& existingEmail, const std::string& email) {
        Admin admin; DataConversion dc;
        if(dc.toLowercase(email) == dc.toLowercase(admin.getEmail())) {
            return true;
        }

        int userNum = existingEmail.getSize();
        for (int i = 0; i < userNum; ++i) {
            if (dc.toLowercase(existingEmail.get(i)) == dc.toLowercase(email)) {
                return true;
            }
        }
        return false;
    }

    void sortPropertyInformation() {
        // Implementation of sorting property information logic
    }

    void searchProperty() {
        // Implementation of property search logic
    }

    void displayPropertyInformation() {
        // Implementation of displaying property information logic
    }

    void setFavoriteProperty(const Property& property) {
        // Implementation of saving favorite properties logic
        this->favouriteList.insertAtEnd(property);
    }

    void removeFavouriteProperty(const int &remIndex) {
        // Implementation of removing favorite properties logic
        this->favouriteList.removeAtIndex(remIndex);
    }

    void viewFavouriteProperty() {
        if (favouriteList.getSize() > 0) {
            int propIndex = 1;

            Property property = favouriteList.getFirst();

            while (true) {
                cout << endl;
                cout << "[FAVOURITE PROPERTY LIST]" << endl;
                cout << "NO: " << propIndex << " OUT OF " << favouriteList.getSize() << endl;

                displaySingleProperty(property);

                cout << "Options: (N)ext, (P)revious, (Q)uit, (U)nfavourite, (R)ent Request" << endl;
                cout << ">> ";

                std::string choice;
                getline(cin >> ws, choice);

                if (choice == "N" || choice == "n") {
                    if (propIndex < favouriteList.getSize()) {
                        property = favouriteList.nextItem();
                        propIndex++;
                    }
                    else {
                        cout << "No more items. Reached the last favourite property." << endl << endl;
                    }
                }
                else if (choice == "P" || choice == "p") {
                    if (propIndex > 1) {
                        property = favouriteList.prevItem();
                        propIndex--;
                    }
                    else {
                        cout << endl << "This is the first favourite property." << endl << endl;
                    }
                }
                else if (choice == "Q" || choice == "q") {
                    break;
                }
                else if (choice == "U" || choice == "u") {
                    property = favouriteList.removeCurrent();
                    cout << endl << "Property has been removed from favourite list." << endl << endl;
                }
                else if (choice == "R" || choice == "r") {
                    // call rent request function
                    cout << endl << "Are you sure to rent this property (Y/N)" << endl;
                    cout << ">>> ";

                    std::string rentChoice;
                    getline(cin >> ws, rentChoice);
                    
                    if (rentChoice == "Y" || rentChoice == "y") {
                        // Add Rent Request Function
                        addRentalRequest(favouriteList.getCurrent());
                        cout << "Enter any key to continue: ";
                        string userInput;
                        getline(cin >> ws, userInput);
                        cout << endl;
                    }
                    else if (rentChoice == "N" || rentChoice == "n") {
                        cout << endl << "[RENT REQUEST CANCELLED]" << endl << endl;
                    }
                    else {
                        cout << endl << "Invalid input! Please try again..." << endl;
                    }
                }
                else {
                    cout << endl << "Invalid input! Please try again..." << endl;
                }
            }
        }
        else {
            cout << endl << "You have no favourite property..." << endl << endl;
        }
    }

    void addRentalRequest(Property &propertySelected) {
        for (int count = 0; count < rentalHistory.getSize(); count++) {
            if (rentalHistory.get(count).getProperty() == propertySelected) {
                cout << endl << "You have already sent a rental request for this property." << endl << endl;
                return;
            }
        }

        // // Get the current time
        // std::time_t now = std::time(nullptr);

        // // Convert the time to a string representation
        // std::stringstream ss;
        // ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");
        // std::string currentDateTime = ss.str();

        DataConversion dc;
        Rental request(propertySelected, this->getEmail(), dc.getTodayDate(), Status::Approved, "");

        this->rentalHistory.insertAtEnd(request);

        cout << endl << "[RENT REQUEST HAS SENT]" << endl;
    }

    void extractSpecificStatusRequest(Status stat) {
        int total = 0;
        Rental rental;

        for (int count = 0; count < rentalHistory.getSize(); count++) {
            if (rentalHistory.get(count).getApplicationStatus() == stat) {
                total++;
            }
        }

        while (true) {
            Rental eachReq = rentalHistory.getFirst();
            if (eachReq.getApplicationStatus() == stat) {
                rental = eachReq;
                break;
            }

            eachReq = rentalHistory.nextItem();
        }

        int propIndex = 1;
        std::string statStr = getStatusInString(stat);

        while (true) {
            cout << endl << "[RENTAL REQUEST: " << statStr << "]" << endl;

            cout << "NO: " << propIndex << " OUT OF " << total << endl;

            displaySingleProperty(rental.getProperty());

            cout << "Request Date: " << rental.getRequestDateTime() << endl;
            cout << "Application Status: " << getStatusInString(rental.getApplicationStatus()) << endl;
            cout << "Remarks: " << rental.getRemarks() << endl;

            cout << "---------------------------------------" << endl;

            switch (stat) {
                case Approved:
                    cout << "Options: (N)ext, (P)revious, (D)elete, (Q)uit, (T)ransaction" << endl;
                    cout << ">> ";
                    break;
                default:
                    cout << "Options: (N)ext, (P)revious, (D)elete, (Q)uit" << endl;
                    cout << ">> ";
                    break;
            }

            std::string choice;
            getline(cin >> ws, choice);

            if (choice == "N" || choice == "n") {
                if (propIndex < total) {
                    rental = rentalHistory.nextItem();

                    while (true) {
                        if (rental.getApplicationStatus() == stat) {
                            propIndex++;
                            break;
                        }

                        rental = rentalHistory.nextItem();
                    }
                }
                else {
                    cout << "No more items. Reached the last rental history." << endl << endl;
                }
            }
            else if (choice == "P" || choice == "p") {
                if (propIndex > 1) {
                    rental = rentalHistory.prevItem();

                    while (true) {
                        if (rental.getApplicationStatus() == stat) {
                            propIndex--;
                            break;
                        }

                        rental = rentalHistory.prevItem();
                    }
                }
                else {
                    cout << endl << "This is the first rental history." << endl << endl;
                }
            }
            else if (choice == "D" || choice == "d") {
                while (true) {
                    cout << "Are you sure to remove the current rental history from the list? (Y/N)" << endl;
                    cout << ">> ";
                    string option;
                    getline(cin >> ws, option);

                    if (option == "Y" || option == "y") {
                        rental = rentalHistory.removeCurrent();
                        cout << endl << "Rental history has been removed." << endl << endl;
                        break;
                    }
                    else if (option == "N" || option == "n") {
                        cout << endl << "Rental request remove unsuccessful" << endl << endl;
                        break;
                    }
                    else {
                        cout << endl << "Invalid Option. Please Try Again..." << endl << endl;
                    }
                }
            }
            else if (choice == "T" || choice == "t") {
                if (rental.getApplicationStatus() == 1) {
                    cout << endl << "Going to payment page..." << endl << endl;

                    if(rentalPayment(rental, rentalHistory.getIndex())) {
                        cout << "Payment successful!" << endl << endl;
                        break;
                    }
                    else {
                        cout << "Payment Unsuccess!" << endl << endl;
                    }
                }
                else {
                    cout << "This application is not approved..." << endl;
                }
            }
            else if (choice == "Q" || choice == "q") {
                break;
            }
            else {
                cout << endl << "Invalid input! Please try again..." << endl;
            }
        }
    }

    bool rentalPayment(Rental &rental, const int &oriItemIndex) {
        // Implementation of rental payment logic
        bool paidSuccessfully = false;

        while (true) {
            cout << "[PAYMENT PAGE]" << endl;
            cout << "Property Information" << endl;
            cout << "---------------------------------------" << endl;
            displaySingleProperty(rental.getProperty());
            cout << "Application Date: " << rental.getRequestDateTime() << endl;
            cout << "Remarks: " << rental.getRemarks() << endl;

            cout << "Enter 'P' to proceed payment (0 to Back): " << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);

            if (userInput == "P" || userInput == "p") {
                paidSuccessfully = paymentInterface();

                if (paidSuccessfully) {
                    rental.setApplicationStatus(Status::Active);
                    this->rentalHistory.replace(rental, oriItemIndex);
                    break;
                }
            }
            else if (userInput == "0") {
                cout << endl << "Payment Cancelled... Returning Back!" << endl << endl;
                break;
            }
            else {
                cout << endl << "Invalid Option... Please try again!" << endl << endl;
            }
        }
        
        return paidSuccessfully;
    }

    bool paymentInterface() {
        // Implementation of payment interface logic
        DataConversion dc;

        bool paymentStatus = false;

        while (true) {
            cout  << endl << "Enter Card No. [16-Digits] (-1 to Cancel): ";
            string cardNo;
            getline(cin >> ws, cardNo);

            if (cardNo == "-1") {
                break;
            }
            else if (cardNo.size() == 16 && dc.isInteger(cardNo)) {
                cout << endl << "Enter Card Holder Name (-1 to Cancel): ";
                string holderName;
                getline(cin >> ws, holderName);

                if (holderName == "-1") {
                    break;
                }
                else {
                    while (true) {
                        cout << endl << "Enter CVV [3-Digits] (-1 to Cancel): ";
                        string cvv;
                        getline(cin >> ws, cvv);

                        if (cvv == "-1") {
                            break;
                        }
                        else if (cvv.size() == 3 && dc.isInteger(cvv)) {
                            while (true) {
                                cout << endl << "Card Expiry Date: " << endl;
                                cout << ">> Month [1-12] (-1 to Cancel): ";
                                string expiryMonth;
                                getline(cin >> ws, expiryMonth);
                                
                                if (expiryMonth == "-1") {
                                    break;
                                }
                                else if (dc.isInteger(expiryMonth)) {
                                    int cardMonth = stoi(expiryMonth);
                                    
                                    if (cardMonth > 0 && cardMonth < 13) {
                                        while (true) {
                                            cout << endl << ">> Year [2023 - 2028] (-1 to Cancel): ";
                                            string expiryYear;
                                            getline(cin >> ws, expiryYear);

                                            if (expiryYear == "-1") {
                                                cout << endl << "Payment Cancelled... Returning Back!" << endl;
                                                paymentStatus = true;
                                                break;
                                            }
                                            else if (dc.isInteger(expiryYear)) {
                                                int cardYear = stoi(expiryYear);

                                                if (expiryYear.size() == 4) {
                                                    std::tm date = {0};

                                                    date.tm_year = cardYear - 1900;
                                                    date.tm_mon = cardMonth - 1;
                                                    date.tm_mday = 1;

                                                    std::time_t cardDate = std::mktime(&date);

                                                    if (dc.comapreDate(cardDate, dc.todayDateInTimeT()) == 1) {
                                                        paymentStatus = true;
                                                    }
                                                    else {
                                                        cout << endl << "The card is expired... Please user another card" << endl;
                                                    }

                                                    break;
                                                }
                                                else {
                                                    cout << endl << "Invalid Expiry Year... Please Try Again!" << endl;
                                                }
                                            }
                                            else {
                                                cout << endl << "Invalid Year... Please Try Again!" << endl;
                                            }
                                        }

                                        break;
                                    }
                                    else {
                                        cout << endl << "Invalid Expiry Date... Please Try Again!" << endl;
                                    }
                                }
                                else {
                                    cout << endl << "Invalid Expiry Date... Please Try Again!" << endl;
                                }
                            }

                            break;
                        }
                        else {
                            cout << endl << "Invalid CVV... Please Try Again!" << endl;
                        }
                    }

                    break;
                }

                break;
            }
            else {
                cout << endl << "Invalid Card...Please Try Again!" << endl;
            }
        }
        
        return paymentStatus;
    }

    std::string rentalRequestSummary() {
        Status stat;
        int pending = 0, approved = 0, rejected = 0, active = 0, inactive = 0;
        // Implementation of rental request summary logic
        for (int count = 0; count < rentalHistory.getSize(); count++) {
            stat = rentalHistory.get(count).getApplicationStatus();

            switch (stat) {
                case Pending:
                    pending++;
                    break;
                case Approved:
                    approved++;
                    break;
                case Rejected:
                    rejected++;
                    break;
                case Active:
                    active++;
                    break;
                case Inactive:
                    inactive++;
                    break;
                default:
                    break;
            }    
        }

        cout << "[Summary of Rental History]" << endl;
        cout << " 1. Pending: " << pending << endl;
        cout << " 2. Approved: " << approved << endl;
        cout << " 3. Rejected: " << rejected << endl;
        cout << " 4. Moved In: " << active << endl;
        cout << " 5. Moved Out: " << inactive << endl;
        cout << "------------------------------" << endl << endl;
        cout << "Please select an option (-1 to Back): " << endl;
        cout << ">> ";

        string userInput;
        getline(cin >> ws, userInput);
        
        return userInput;
    }

    void removeRentalRequest() {
        // Implementation of removing rental request logic
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
        std::cout << "---------------------------------------\n";
    }

    DoublyCircularLinkedList<Property> getFavoriteProperty() const {
        return favouriteList;
    }

    DoublyCircularLinkedList<Rental> getRentalHistory() const {
        return rentalHistory;
    }

    void placeRentRequest() {
        // Implementation of placing a rent request logic
    }

    void displayRentingHistory() {
        // Implementation of displaying renting history logic
    }

    Tenant login(const std::string& email, DynamicArray<Tenant>& tenantList) {
        Tenant loginTenant; DataConversion dc;
        for(int i = 0; i < tenantList.getSize(); ++i) {
            Tenant tenant;
            tenant = tenantList.get(i);
            if(dc.toLowercase(tenant.getEmail()) == dc.toLowercase(email)) {
                loginTenant.setName(tenant.getName());
                loginTenant.setEmail(tenant.getEmail());
                loginTenant.setPhoneNo(tenant.getPhoneNo());
                loginTenant.setIdentificationNo(tenant.getIdentificationNo());
                loginTenant.setGender(tenant.getGender());
                loginTenant.setDateOfBirth(tenant.getDateOfBirth());
                loginTenant.setLastLoginDate(tenant.getLastLoginDate());
                loginTenant.setPassword(tenant.getPassword());
                loginTenant.setLastLoginDate(dc.getTodayDate());
                loginTenant.setRole(tenant.getRole());

                tenantList.replace(loginTenant, i);
            }
        } return loginTenant;
    } 

};

#endif