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

public:
    User();
    User(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
         const std::string& _identificationNo, const std::string& _gender, const std::string& _password,
         const std::string& _dateOfBirth);

    string getName() const;
    void setName(const string& name);

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

    string getDateOfBirth() const;
    void setDateOfBirth(const string& dateOfBirth);

    void login();
    void logout();
    void resetPassword();

    bool authenticated();
};

#endif