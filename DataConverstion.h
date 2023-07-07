#ifndef DATACONVERSTION_H
#define DATACONVERSTION_H

#include <string>
#include <algorithm>

class DataConversion {
public:
    std::string toLowercase(const std::string& input) {
        std::string result = input;

        for (char& c : result) {
            c = std::tolower(c);
        }

        return result;
    }

    std::string toUppercase(const std::string& input) {
        std::string result = input;

        for (char& c : result) {
            c = std::toupper(c);
        }

        return result;
    }
};



#endif