#ifndef TENANT_H
#define TENANT_H

/**
 * FILENAME: Tenant.h
*/

#include "User.h"

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

#endif