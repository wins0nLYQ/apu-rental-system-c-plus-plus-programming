#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
private:
    string name;
    string email;
    string password;
    string phoneNo;
    string identificationNo;
    string gender;
    string dateOfBirth;
    string role;

public:
    User(){}

    User(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
            const std::string& _identificationNo, const std::string& _gender,const std::string& _password,
            const std::string& _dateOfBirth, const std::string& _role)
            : name(_name), email(_email), password(_password), phoneNo(_phoneNo),
            identificationNo(_identificationNo), gender(_gender), dateOfBirth(_dateOfBirth),
            role(_role) {
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

    string getRole() const {
        return role;
    }

    void setRole(const string& role) {
        this->role = role;
    }

    bool isAuthorised() {
        return this->email != "";
    }
};

#endif