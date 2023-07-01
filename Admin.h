#ifndef ADMIN_H
#define ADMIN_H

/**
 * FILENAME: Admin.h
*/

#include <string>
#include "UserAccount_Manager.h"
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
    void addManager();
    bool updateManagerStatus(UserAccount_Manager<Manager>& managerList);
    void deleteManager();
    void filterTenants(UserAccount_Manager<Tenant>& tenantList);
    void displayPropertyInformation(const std::string& tenantID);
    void displayPropertyInformation();
};


#endif