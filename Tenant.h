#ifndef TENANT_H
#define TENANT_H

/**
 * FILENAME: Tenant.h
*/

#include "User.h"

using namespace std;

class Tenant : public User {
  private:
    string lastLoginDate;

  public:
    Tenant(){}

    Tenant(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
                const std::string& _identificationNo, const std::string& _gender,
                const std::string& _dateOfBirth, const std::string& _lastLoginDate)
            : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth),
              lastLoginDate(_lastLoginDate) {
        }

    string getLastLoginDate() const {
        return lastLoginDate;
    }

    void setLastLoginDate(const string& lastLoginDate) {
        this->lastLoginDate = lastLoginDate;
    }

    void registerTenant() {
        // Implementation of tenant registration logic
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
};

#endif