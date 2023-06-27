#include "User.cpp"

using namespace std;

class Manager : public User {
private:
    vector<string> registeredTenants;
    vector<string> favoriteProperties;

public:
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