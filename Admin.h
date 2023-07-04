#ifndef ADMIN_H
#define ADMIN_H

/**
 * FILENAME: Admin.h
*/

#include <string>
#include "DynamicArray.h"
#include "Manager.h"
#include "Tenant.h"
#include "User.h"
#include "AccountManagement.h"
#include "Property.h"

class Admin : public User {
private:
    std::string email;
    std::string password;

public:
    Admin();

    std::string getEmail() const;
    std::string getPassword() const;
    void addManager(DynamicArray<Manager>& managerList, DynamicArray<Tenant>& tenantList);
    bool updateManagerStatus(DynamicArray<Manager>& managerList);
    void deleteManager();
    void filterTenants(DynamicArray<Tenant>& tenantList);
    void tenantFilteringProcess(DynamicArray<Tenant>& tenantList, const string& filterBy, const string& search);
    void displayFilteredTenantList(DynamicArray<Tenant>& filteredList);
    void filterProperty(vector<Property>& properties);
};


#endif