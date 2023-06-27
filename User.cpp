#include <string>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class User {
private:
    string userID;
    string firstName;
    string lastName;
    string email;
    string password;
    string phoneNo;
    string identificationNo;
    string gender;
    tm birthOfDate;

public:
    string getUserID() const;
    void setUserID(const string& userID);

    string getFirstName() const;
    void setFirstName(const string& firstName);

    string getLastName() const;
    void setLastName(const string& lastName);

    string getEmail() const;
    void setEmail(const string& email);

    string getPassword() const;
    void setPassword(const string& password);

    string getPhoneNo() const;
    void setPhoneNo(const string& phoneNo);

    string getIdentificationNo() const;
    void setIdentificationNo(const string& identificationNo);

    string getGender() const;
    void setGender(const string& gender);

    tm getBirthOfDate() const;
    void setBirthOfDate(const tm& birthOfDate);

    void login();
    void logout();
    void resetPassword();
};

string User::getUserID() const {
    return userID;
}

void User::setUserID(const string& userID) {
    this->userID = userID;
}

string User::getFirstName() const {
    return firstName;
}

void User::setFirstName(const string& firstName) {
    this->firstName = firstName;
}

string User::getLastName() const {
    return lastName;
}

void User::setLastName(const string& lastName) {
    this->lastName = lastName;
}

string User::getEmail() const {
    return email;
}

void User::setEmail(const string& email) {
    this->email = email;
}

string User::getPassword() const {
    return password;
}

void User::setPassword(const string& password) {
    this->password = password;
}

string User::getPhoneNo() const {
    return phoneNo;
}

void User::setPhoneNo(const string& phoneNo) {
    this->phoneNo = phoneNo;
}

string User::getIdentificationNo() const {
    return identificationNo;
}

void User::setIdentificationNo(const string& identificationNo) {
    this->identificationNo = identificationNo;
}

string User::getGender() const {
    return gender;
}

void User::setGender(const string& gender) {
    this->gender = gender;
}

tm User::getBirthOfDate() const {
    return birthOfDate;
}

void User::setBirthOfDate(const tm& birthOfDate) {
    this->birthOfDate = birthOfDate;
}

void User::login() {
    // Implementation of login logic
}

void User::logout() {
    // Implementation of logout logic
}

void User::resetPassword() {
    // Implementation of password reset logic
}