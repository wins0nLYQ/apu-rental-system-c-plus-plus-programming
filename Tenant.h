#ifndef TENANT_H
#define TENANT_H

/**
 * FILENAME: Tenant.h
*/

#include "User.h"

class Tenant : public User {
  private:
    string lastLoginDate;

  public:
    Tenant();
    Tenant(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
            const std::string& _identificationNo, const std::string& _gender,
            const std::string& _dateOfBirth, const std::string& _lastLoginDate);
    string getLastLoginDate() const;
    void setLastLoginDate(const string& activityStatus);
    void registerTenant();
    void sortPropertyInformation();
    void searchProperty(); 
    void displayPropertyInformation();
    void saveFavorite();
    void placeRentRequest();
    void displayRentingHistory();
};

#endif