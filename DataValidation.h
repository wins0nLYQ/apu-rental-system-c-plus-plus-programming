#ifndef DATAVALIDATION_H
#define DATAVALIDATION_H

/**
 * FILENAME: DataValidation.h
*/

#include <string>

class DataValidation {
public:
    DataValidation();
    bool loginValidation(std::string email, std::string password, std::string userRole);
    bool isEmailValid(const std::string& email);
    bool handleUserLogin(const std::string& userRole);
    bool isValidPhoneNumber(const std::string& phoneNumber);
    bool isValidDateOfBirth(const std::string& dateOfBirth);
    bool isNumber(const std::string& input);
};

#endif