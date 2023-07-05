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
           const std::string& _dateOfBirth, const std::string& _lastLoginDate) : 
           User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth),
           lastLoginDate(_lastLoginDate)
          {};

    string getLastLoginDate() const
    {
      return lastLoginDate;
    };

    void setLastLoginDate(const string& lastLoginDate)
    {
      this->lastLoginDate = lastLoginDate;
    };
    
    // Implementation of tenant registration logic
    void registerTenant();

    // Implementation of sorting property information logic
    void sortPropertyInformation();

    // Implementation of property search logic
    void searchProperty(); 

    // Implementation of displaying property information logic
    void displayPropertyInformation();

    // Implementation of saving favorite properties logic
    void saveFavorite();

    // Implementation of placing a rent request logic
    void placeRentRequest();

    // Implementation of displaying renting history logic
    void displayRentingHistory();

};

#endif