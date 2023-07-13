#ifndef USER_H
#define USER_H

#include <string>
#include <regex>
#include <iostream>
#include "DataValidation.h"


using namespace std;

class Manager;
class Tenant;

class User {
private:
    string name;
    string email;
    string password;
    string phoneNo;
    string identificationNo;
    string gender;
    string dateOfBirth;

public:
    User(){}

    User(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
            const std::string& _identificationNo, const std::string& _gender,const std::string& _password,
            const std::string& _dateOfBirth)
            : name(_name), email(_email), password(_password), phoneNo(_phoneNo),
            identificationNo(_identificationNo), gender(_gender), dateOfBirth(_dateOfBirth) {
    }

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    string getEmail() const {
        return email;
    }

    void setEmail(const string& email) {
        this->email = email;
    }

    string getPassword() const {
        return password;
    }

    void setPassword(const string& password) {
        this->password = password;
    }

    string getPhoneNo() const {
        return phoneNo;
    }

    void setPhoneNo(const string& phoneNo) {
        this->phoneNo = phoneNo;
    }

    string getIdentificationNo() const {
        return identificationNo;
    }

    void setIdentificationNo(const string& identificationNo) {
        this->identificationNo = identificationNo;
    }

    string getGender() const {
        return gender;
    }

    void setGender(const string& gender) {
        this->gender = gender;
    }

    string getDateOfBirth() const {
        return dateOfBirth;
    }

    void setDateOfBirth(const string& dateOfBirth) {
        this->dateOfBirth = dateOfBirth;
    }

    bool isAuthorised() {
        return this->email != "";
    }

    void login() {
        // Implementation of login logic
    }

    void logout() {
        // Implementation of logout logic
    }

    void resetPassword() {
        // Implementation of password reset logic
    }
    

    // bool handleUserLogin(const string& userRole, DynamicArray<Manager>& managerList, DynamicArray<Tenant>& tenantList) {
    //     string email;
    //     string password;

    //     cout << "Please enter the email address (-1 to back): ";
    //     getline(cin >> ws, email);
    //     cout << endl;
    //     if(email == "-1") {
    //         return false;
    //     }
    //     DataValidation dv;
    //     while (!dv.isEmailValid(email)) {
    //         cout << "Invalid email, please try again (-1 to back): ";
    //         getline(cin >> ws, email);
    //         cout << endl;
    //         if(email == "-1") {
    //             return false;
    //         }
    //     }

    //     cout << "Please enter the password (-1 to back): ";
    //     getline(cin >> ws, password);
    //     cout << endl;
    //     if(password == "-1") {
    //         return false;
    //     }

    //     while (!loginValidation(email, password, userRole, managerList, tenantList)) {
    //         cout << "Invalid credentials, please try again!" << endl;
    //         cout << endl;
    //         cout << "Please enter the email address (-1 to back): ";
    //         getline(cin >> ws, email);
    //         cout << endl;

    //         if(email == "-1") {
    //             return false;
    //         }

    //         while (!dv.isEmailValid(email)) {
    //             cout << "Invalid email, please try again (-1 to back): ";
    //             getline(cin >> ws, email);
    //             cout << endl;

    //             if(email == "-1") {
    //                 return false;
    //             }
    //         }

    //         cout << "Please enter the password (-1 to back): ";
    //         getline(cin >> ws, password);
    //         cout << endl;

    //         if(password == "-1") {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // bool loginValidation(string email, string password, string userRole, DynamicArray<Manager>& managerList, DynamicArray<Tenant>& tenantList) {
    //     if (userRole == "Tenant") {
    //         cout << "Option 1";
    //         return true;
    //     } else if (userRole == "Manager") {
    //         cout << "Option 2";
    //         return true;
    //     } else if (userRole == "Admin") {
    //         // Admin admin;
    //         if ((email == "admin@gmail.com") && (password == "Admin@1234")) {
    //             return true;
    //         } else {
    //             return false;
    //         }
    //     }
    //     return false;
    // }
};

#endif