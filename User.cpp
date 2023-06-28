/**
 * FILENAME: User.cpp
*/

#include "User.h"

User::User(){}

User::User(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
         const std::string& _identificationNo, const std::string& _gender,const std::string& _password,
         const std::string& _dateOfBirth)
        : name(_name), email(_email), password(_password), phoneNo(_phoneNo),
          identificationNo(_identificationNo), gender(_gender), dateOfBirth(_dateOfBirth) {
    }

string User::getName() const {
    return name;
}

void User::setName(const string& name) {
    this->name = name;
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

string User::getDateOfBirth() const {
    return dateOfBirth;
}

void User::setDateOfBirth(const string& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
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