#ifndef DATAVALIDATION_H
#define DATAVALIDATION_H

/**
 * FILENAME: DataValidation.h
*/

#include <string>
#include "DynamicArray.h"
#include "Manager.h"
#include "Tenant.h"

class DataValidation {
public:
    DataValidation();
    bool loginValidation(std::string email, std::string password, std::string userRole);
    bool isEmailValid(const std::string& email);
    bool handleUserLogin(const std::string& userRole);
    bool isValidPhoneNumber(const std::string& phoneNumber);
    bool isValidDateOfBirth(const std::string& dateOfBirth);
    bool isNumber(const std::string& input);
    bool isEmailExists(DynamicArray<Manager>& managerList, DynamicArray<Tenant>& tenantList, const std::string& email);
    bool isValidID(const std::string& identificationNo);
};

#endif