/**
 * FILENAME: Tenant.cpp
*/

#include "Tenant.h"

Tenant::Tenant(){}

Tenant::Tenant(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
            const std::string& _identificationNo, const std::string& _gender,
            const std::string& _dateOfBirth, const std::string& _activityStatus)
        : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth),
          registerDate(registerDate) {
    }

string Tenant::getRegisterDate() const {
    return registerDate;
}

void Tenant::setRegisterDate(const string& registerDate) {
    this->registerDate = registerDate;
}

void Tenant::registerTenant() {
    // Implementation of tenant registration logic
}

void Tenant::sortPropertyInformation() {
    // Implementation of sorting property information logic
}

void Tenant::searchProperty() {
    // Implementation of property search logic
}

void Tenant::displayPropertyInformation() {
    // Implementation of displaying property information logic
}

void Tenant::saveFavorite() {
    // Implementation of saving favorite properties logic
}

void Tenant::placeRentRequest() {
    // Implementation of placing a rent request logic
}

void Tenant::displayRentingHistory() {
    // Implementation of displaying renting history logic
}