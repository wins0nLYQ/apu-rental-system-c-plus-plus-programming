/**
 * FILENAME: Manager.cpp
*/

#include "Manager.h"

Manager::Manager(){}

Manager::Manager(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
            const std::string& _identificationNo, const std::string& _gender,
            const std::string& _dateOfBirth, const std::string& _status)
        : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth),
          status(_status) {
    }

string Manager::getStatus() const {
    return status;
}

void Manager::setStatus(const string& status) {
    this->status = status;
}

void Manager::displayRegisteredTenant() {
    // Implementation of displaying registered tenants logic
}

void Manager::searchTenant() {
    // Implementation of tenant search logic
}

void Manager::displayTenantStatus() {
    // Implementation of displaying tenant status logic
}

void Manager::deleteTenant() {
    // Implementation of tenant deletion logic
}

void Manager::displayFavoriteProperty() {
    // Implementation of displaying favorite properties logic
}

void Manager::generate_TopFavProp_Report() {
    // Implementation of generating top favorite properties report logic
}

void Manager::displayRentingRequest() {
    // Implementation of displaying renting requests logic
}

void Manager::acceptTenancy() {
    // Implementation of accepting tenancy logic
}

void Manager::rejectTenancy() {
    // Implementation of rejecting tenancy logic
}

void Manager::displayPaymentStatus() {
    // Implementation of displaying payment status logic
}