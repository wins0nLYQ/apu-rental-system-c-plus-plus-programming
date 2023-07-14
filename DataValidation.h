#ifndef DATAVALIDATION_H
#define DATAVALIDATION_H

/**
 * FILENAME: DataValidation.h
*/

#include <string>
#include "DynamicArray.h"
// #include "Manager.h"
// #include "Tenant.h"
#include <iostream>
#include <regex>
// #include "Admin.h"

using namespace std;

class Manager;
class Tenant;

class DataValidation {
public:
    DataValidation(){}

    bool isEmailValid(const string& email) {
        // Regular expression pattern for email validation
        regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

        // Match the email pattern against the provided email
        return regex_match(email, emailRegex);
    }

    bool isValidPhoneNumber(const std::string& phoneNumber) {
        // Regular expression pattern to match a valid phone number
        std::regex pattern(R"(\d{10,11})");

        return std::regex_match(phoneNumber, pattern);
    }

    bool isValidDateOfBirth(const std::string& dateOfBirth) {
        // Regular expression pattern to match a valid date in the format "YYYY-MM-DD"
        std::regex pattern(R"(\d{4}-\d{2}-\d{2})");

        // Check if the date format is valid
        if (!std::regex_match(dateOfBirth, pattern)) {
            return false;
        }

        // Parse the date components
        std::istringstream iss(dateOfBirth);
        int year, month, day;
        char delimiter;
        iss >> year >> delimiter >> month >> delimiter >> day;

        // Check if the parsed values are within the valid range
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            return false;
        }

        // Check if the date is a valid date
        std::tm time = {};
        time.tm_year = year - 1900;
        time.tm_mon = month - 1;
        time.tm_mday = day;

        std::time_t currentTime = std::time(nullptr);
        std::tm* currentDate = std::localtime(&currentTime);

        // Check if the date is in the future
        if (time.tm_year > currentDate->tm_year ||
            (time.tm_year == currentDate->tm_year && time.tm_mon > currentDate->tm_mon) ||
            (time.tm_year == currentDate->tm_year && time.tm_mon == currentDate->tm_mon && time.tm_mday > currentDate->tm_mday)) {
            return false;
        }
    
        return true;
    }

    bool isNumber(const std::string& input) {
        for (char c : input) {
            if (!std::isdigit(c)) {
                return false; // Non-digit character found, input is not a number
            }
        }
        return true; // All characters are digits, input is a number
    }

    bool isValidID(const std::string& identificationNo) {
        // Check if it matches the identification number format
        int length = identificationNo.length();
        if (length >= 6 && length <= 15) {
            return true;
        }
        return false;
    }

    bool isValidPassword(const std::string& password) {
        // Check the password against the criteria for validity

        // Criteria:
        // - Minimum length of 8 characters
        // - Contains at least one uppercase letter
        // - Contains at least one lowercase letter
        // - Contains at least one digit
        // - Contains at least one special character

        if (password.length() < 8) {
            return false;  // Password is too short
        }

        bool hasUppercase = false;
        bool hasLowercase = false;
        bool hasDigit = false;
        bool hasSpecialChar = false;
        for (char c : password) {
            if (std::isupper(c)) {
                hasUppercase = true;
            } else if (std::islower(c)) {
                hasLowercase = true;
            } else if (std::isdigit(c)) {
                hasDigit = true;
            } else if (!std::isalnum(c)) {
                hasSpecialChar = true;
            }
        }

        // Check if all criteria are met
        return hasUppercase && hasLowercase && hasDigit && hasSpecialChar;
    }
};

#endif