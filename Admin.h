#ifndef ADMIN_H
#define ADMIN_H

/**
 * FILENAME: Admin.h
*/

#include <string>
#include "UserAccount_Manager.cpp"
#include "Manager.cpp"

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
    void displayTenants(const std::string& propertyID);
    void displayTenants();
    void displayPropertyInformation(const std::string& tenantID);
    void displayPropertyInformation();
};


#endif