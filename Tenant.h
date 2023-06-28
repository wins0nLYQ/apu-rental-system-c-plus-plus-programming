/**
 * FILENAME: Tenant.h
*/

#include "User.cpp"

class Tenant : public User {
  public:
    void registerTenant();
    void sortPropertyInformation();
    void searchProperty();
    void displayPropertyInformation();
    void saveFavorite();
    void placeRentRequest();
    void displayRentingHistory();
};