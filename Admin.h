/**
 * FILENAME: Admin.h
*/

#include <string>

class Admin {
private:
    std::string email;
    std::string password;

public:
    Admin();

    std::string getEmail() const;
    std::string getPassword() const;
    void addManager();
    void updateManagerDetails();
    void deleteManager();
    void displayTenants(const std::string& propertyID);
    void displayTenants();
    void displayPropertyInformation(const std::string& tenantID);
    void displayPropertyInformation();
};
