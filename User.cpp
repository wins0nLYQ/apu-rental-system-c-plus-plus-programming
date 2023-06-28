/**
 * FILENAME: User.cpp
*/

#include "User.h"

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