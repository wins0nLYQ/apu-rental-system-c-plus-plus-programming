#ifndef MANAGER_H
#define MANAGER_H

/**
 * FILENAME: Manager.h
 */

#include "string"
#include "User.h"
#include "DynamicArray.h"
#include "DataConversion.h"
// #include <vector>
// #include "DataConversion.h"
#include "Tenant.h"

using namespace std;

class Manager : public User
{
private:
    string status;

public:
    Manager() {}

    Manager(const std::string &_name, const std::string &_email, const std::string &_phoneNo,
            const std::string &_identificationNo, const std::string &_gender,
            const std::string &_dateOfBirth, const std::string &_status)
        : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth, "Manager"),
          status(_status)
    {
    }

    string getStatus() const
    {
        return status;
    }

    void setStatus(const string &status)
    {
        this->status = status;
    }

    void displayRegisteredTenant()
    {
        // Implementation of displaying registered tenants logic
    }

    void searchTenant()
    {
        // Implementation of tenant search logic
    }

    void displayTenantStatus()
    {
        // Implementation of displaying tenant status logic
    }

    void deleteTenant()
    {
        // Implementation of tenant deletion logic
    }

    void displayFavoriteProperty()
    {
        // Implementation of displaying favorite properties logic
    }

    void generate_TopFavProp_Report()
    {
        // Implementation of generating top favorite properties report logic
    }

    void displayRentingRequest()
    {
        // Implementation of displaying renting requests logic
    }

    void acceptTenancy()
    {
        // Implementation of accepting tenancy logic
    }

    void rejectTenancy()
    {
        // Implementation of rejecting tenancy logic
    }

    void displayPaymentStatus()
    {
        // Implementation of displaying payment status logic
    }

    Manager login(const std::string &email, DynamicArray<Manager> &managerList)
    {
        Manager loginManager;
        DataConversion dc;
        for (int i = 0; i < managerList.getSize(); ++i)
        {
            Manager manager;
            manager = managerList.get(i);
            if (dc.toLowercase(manager.getEmail()) == dc.toLowercase(email))
            {
                loginManager.setName(manager.getName());
                loginManager.setEmail(manager.getEmail());
                loginManager.setPhoneNo(manager.getPhoneNo());
                loginManager.setIdentificationNo(manager.getIdentificationNo());
                loginManager.setGender(manager.getGender());
                loginManager.setDateOfBirth(manager.getDateOfBirth());
                loginManager.setPassword(manager.getPassword());
                loginManager.setStatus(manager.getStatus());
                loginManager.setRole(manager.getRole());
            }
        }
        return loginManager;
    }

    void getAllFavouriteList(DynamicArray<Tenant> tenantList, DynamicArray<Property> &allFavouriteProperty)
    {
        cout << "Testing" << endl;
        for (int count = 0; count < tenantList.getSize(); count++)
        {
            Tenant tenant = tenantList.get(count);
            cout << "Testing1" << endl;

            for (int count2 = 0; count2 < tenant.getFavoriteProperty().getSize(); count2++)
            {
                allFavouriteProperty.insertAtEnd(tenant.getFavoriteProperty().get(count2));
                cout << "Testing2" << endl;
            }
        }
        cout << "Testing3" << endl;
    }

    void getAllRentHistoryList(DynamicArray<Tenant> tenantList, DynamicArray<Rental> &allRentHistory)
    {
        cout << "Testing" << endl;
        for (int count = 0; count < tenantList.getSize(); count++)
        {
            Tenant tenant = tenantList.get(count);
            cout << "Testing1" << endl;

            for (int count2 = 0; count2 < tenant.getRentalHistory().getSize(); count2++)
            {
                allRentHistory.insertAtEnd(tenant.getRentalHistory().get(count2));
                cout << "Testing2" << endl;
            }
        }
        cout << "Testing3" << endl;
    }

    void printRentHistory(DynamicArray<Rental> &allRentHistory)
    {
        cout << "Rental History:" << endl;
        for (int i = 0; i < allRentHistory.getSize(); i++)
        {
            Rental rental = allRentHistory.get(i);
            // Print the details of the rental
            cout << "Property: " << rental.getProperty().getPropName() << endl; // Assuming Property has a getPropName() method
            cout << "Tenant Email: " << rental.getTenantEmail() << endl;
            cout << "Request Date/Time: " << rental.getRequestDateTime() << endl;
            cout << "Application Status: " << getStatusInString(rental.getApplicationStatus()) << endl;
            cout << "Remarks: " << rental.getRemarks() << endl;
            cout << "-----------------------------------------" << endl;
        }
    }
};

#endif