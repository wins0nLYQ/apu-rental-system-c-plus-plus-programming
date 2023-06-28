/**
 * FILENAME: Manager.h
*/

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