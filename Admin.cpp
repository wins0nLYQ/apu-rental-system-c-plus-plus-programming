#include "Admin.h"

using namespace std;

Admin::Admin() {
    email = "admin@gmail.com";
    password = "Admin@1234";
}

string Admin::getEmail() const {
    return email;
}

string Admin::getPassword() const {
    return password;
}

void Admin::addManager() {
    // Implementation for adding a manager
}

void Admin::updateManagerDetails() {
    // Implementation for updating manager details
}

void Admin::deleteManager() {
    // Implementation for deleting a manager
}

void Admin::displayTenants(const string& propertyID) {
    // Implementation for displaying tenants for a specific property
}

void Admin::displayTenants() {
    // Implementation for displaying all tenants
}

void Admin::displayPropertyInformation(const string& tenantID) {
    // Implementation for displaying property information for a specific tenant
}

void Admin::displayPropertyInformation() {
    // Implementation for displaying all property information
}