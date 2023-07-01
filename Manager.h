#ifndef MANAGER_H
#define MANAGER_H

/**
 * FILENAME: Manager.h
*/

#include <vector>
#include "User.h"

using namespace std;

class Manager : public User {
private:
    string status;
    vector<string> registeredTenants;
    vector<string> favoriteProperties;

public:
    Manager();
    Manager(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
            const std::string& _identificationNo, const std::string& _gender,
            const std::string& _dateOfBirth, const std::string& _status);

    string getStatus() const;
    void setStatus(const string& status);
    void displayRegisteredTenant();
    void searchTenant();
    void displayTenantStatus();
    void deleteTenant();
    void displayFavoriteProperty();
    void generate_TopFavProp_Report();
    void displayRentingRequest();
    void acceptTenancy();
    void rejectTenancy();
    void displayPaymentStatus();
};

#endif