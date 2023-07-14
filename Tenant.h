#ifndef TENANT_H
#define TENANT_H

/**
 * FILENAME: Tenant.h
*/

#include "User.h"
#include "Property.h"
#include "DataConversion.h"
#include "Admin.h"
#include "DoublyCircularLinkedList.h"
#include "Property.h"


using namespace std;

class Tenant : public User {
  private:
    string lastLoginDate;
    DoublyCircularLinkedList<Property> dcll;

  public:
    Tenant(){}

    Tenant(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
                const std::string& _identificationNo, const std::string& _gender, const std::string& _password,
                const std::string& _dateOfBirth, const std::string& _lastLoginDate)
            : User(_name, _email, _phoneNo, _identificationNo, _gender, _password, _dateOfBirth),
              lastLoginDate(_lastLoginDate) {
        }

    string getLastLoginDate() const {
        return lastLoginDate;
    }

    void setLastLoginDate(const string& lastLoginDate) {
        this->lastLoginDate = lastLoginDate;
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

    void saveFavorite() {
        // Implementation of saving favorite properties logic
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
            if(tenant.getEmail() == email) {
                loginTenant.setName(tenant.getName());
                loginTenant.setEmail(tenant.getEmail());
                loginTenant.setPhoneNo(tenant.getPhoneNo());
                loginTenant.setIdentificationNo(tenant.getIdentificationNo());
                loginTenant.setGender(tenant.getGender());
                loginTenant.setDateOfBirth(tenant.getDateOfBirth());
                loginTenant.setLastLoginDate(tenant.getLastLoginDate());
                loginTenant.setPassword(tenant.getPassword());
                loginTenant.setLastLoginDate(dc.getTodayDate());

                tenantList.replace(tenant, i);
            }
        } return loginTenant;
    } 

};

#endif