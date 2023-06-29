#include <iostream>
#include <regex>
#include "DataValidation.h"
#include "Admin.cpp"

using namespace std;

DataValidation::DataValidation(){}

bool DataValidation::loginValidation(string email, string password, string userRole) {
    if (userRole == "Tenant") {
        cout << "Option 1";
        return true;
    } else if (userRole == "Manager") {
        cout << "Option 2";
        return true;
    } else if (userRole == "Admin") {
        Admin admin;
        if ((email == admin.getEmail()) && (password == admin.getPassword())) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool DataValidation::isEmailValid(const string& email) {
    // Regular expression pattern for email validation
    regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");

    // Match the email pattern against the provided email
    return regex_match(email, emailRegex);
}

bool DataValidation::handleUserLogin(const string& userRole) {
    string email;
    string password;

    cout << "Please enter the email address (-1 to back): ";
    getline(cin >> ws, email);
    cout << endl;
    if(email == "-1") {
        return false;
    }
    while (!isEmailValid(email)) {
        cout << "Invalid email, please try again (-1 to back): ";
        getline(cin >> ws, email);
        cout << endl;
        if(email == "-1") {
            return false;
        }
    }

    cout << "Please enter the password (-1 to back): ";
    getline(cin >> ws, password);
    cout << endl;
    if(password == "-1") {
        return false;
    }

    while (!loginValidation(email, password, userRole)) {
        cout << "Invalid credentials, please try again!" << endl;
        cout << endl;
        cout << "Please enter the email address (-1 to back): ";
        getline(cin >> ws, email);
        cout << endl;

        if(email == "-1") {
            return false;
        }

        while (!isEmailValid(email)) {
            cout << "Invalid email, please try again (-1 to back): ";
            getline(cin >> ws, email);
            cout << endl;

            if(email == "-1") {
                return false;
            }
        }

        cout << "Please enter the password (-1 to back): ";
        getline(cin >> ws, password);
        cout << endl;

        if(password == "-1") {
            return false;
        }
    }
    return true;
}

bool DataValidation::isValidPhoneNumber(const std::string& phoneNumber) {
    // Regular expression pattern to match a valid phone number
    std::regex pattern(R"(\d{10,11})");

    return std::regex_match(phoneNumber, pattern);
}

bool DataValidation::isValidDateOfBirth(const std::string& dateOfBirth) {
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