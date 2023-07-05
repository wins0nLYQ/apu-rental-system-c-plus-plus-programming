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
    Manager(){}

    Manager(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
                const std::string& _identificationNo, const std::string& _gender,
                const std::string& _dateOfBirth, const std::string& _status)
            : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth),
            status(_status) {
        }

    string getStatus() const {
        return status;
    }

    void setStatus(const string& status) {
        this->status = status;
    }

    void displayRegisteredTenant() {
        // Implementation of displaying registered tenants logic
    }

    void searchTenant() {
        // Implementation of tenant search logic
    }

    void displayTenantStatus() {
        // Implementation of displaying tenant status logic
    }

    void deleteTenant() {
        // Implementation of tenant deletion logic
    }

    void displayFavoriteProperty() {
        // Implementation of displaying favorite properties logic
    }

    void generate_TopFavProp_Report() {
        // Implementation of generating top favorite properties report logic
    }

    void displayRentingRequest() {
        // Implementation of displaying renting requests logic
    }

    void acceptTenancy() {
        // Implementation of accepting tenancy logic
    }

    void rejectTenancy() {
        // Implementation of rejecting tenancy logic
    }

    void displayPaymentStatus() {
        // Implementation of displaying payment status logic
    }
};

#endif