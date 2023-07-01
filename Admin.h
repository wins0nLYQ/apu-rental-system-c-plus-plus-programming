#ifndef ADMIN_H
#define ADMIN_H

/**
 * FILENAME: Admin.h
*/

#include <string>
#include "DynamicArray.h"
#include "Manager.h"
#include "Tenant.h"


class Admin {
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
    void displayPropertyInformation(const std::string& tenantID);
    void displayPropertyInformation();
};


#endif