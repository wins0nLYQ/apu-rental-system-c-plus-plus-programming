/**
 * FILENAME: User.h
*/

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