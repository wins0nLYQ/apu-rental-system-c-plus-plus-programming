#ifndef TENANT_H
#define TENANT_H

/**
 * FILENAME: Tenant.h
*/

#include "User.h"
#include "DoublyCircularLinkedList.h"

class Property;

using namespace std;

class Tenant : public User {
  private:
    string lastLoginDate;
    DoublyCircularLinkedList<Property> favouriteList;

  public:
    Tenant(){}
    Tenant(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
                const std::string& _identificationNo, const std::string& _gender,
                const std::string& _dateOfBirth, const std::string& _lastLoginDate)
            : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth),
              lastLoginDate(_lastLoginDate) {
        }
    string getLastLoginDate() const {}
    void setLastLoginDate(const string& lastLoginDate) {}
    DoublyCircularLinkedList<Property> getFavouriteList() const {}
    void addFavouriteList(Property& property) {}
    void registerTenant() {}
    void sortPropertyInformation() {}
    void searchProperty() {}
    void displayPropertyInformation() {}
    void saveFavorite() {}
    void placeRentRequest() {}
    void displayRentingHistory() {}
};



#endif


