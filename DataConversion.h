#ifndef DATACONVERSION_H
#define DATACONVERSION_H

// #include <string>
// #include <algorithm>
#include "DynamicArray.h"
#include <ctime>
// #include <iomanip>

using namespace std;

class DataConversion
{
public:
    std::string toLowercase(const std::string &input)
    {
        std::string result = input;

        for (char &c : result)
        {
            c = std::tolower(c);
        }

        return result;
    }

    std::string toUppercase(const std::string &input)
    {
        std::string result = input;

        for (char &c : result)
        {
            c = std::toupper(c);
        }

        return result;
    }

    long long extractDigit(const std::string &input)
    {
        std::string result;
        for (char c : input)
        {
            if (std::isdigit(c))
            {
                result += c;
            }
        }

        try
        {
            long long digit = std::stoll(result);
            return digit;
        }
        catch (const std::invalid_argument &)
        {
            // Handle invalid string gracefully
            return 0;
        }
    }

    void sort(DynamicArray<string> &array)
    {
        int size = array.getSize();
        bool swapped;

        for (int i = 0; i < size - 1; ++i)
        {
            swapped = false;

            for (int j = 0; j < size - i - 1; ++j)
            {
                if (array.get(j) > array.get(j + 1))
                {                                    // Compare adjacent elements
                    std::string temp = array.get(j); // Use a temporary variable to swap elements
                    array.replace(array.get(j + 1), j);
                    array.get(j + 1) = temp;
                    swapped = true;
                }
            }
            // If no elements were swapped in the inner loop, the array is already sorted
            if (!swapped)
                break;
        }
    }

    string getTodayDate()
    {
        std::time_t now = std::time(nullptr);
        std::tm *localTime = std::localtime(&now);

        char buffer[11];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);

        return buffer;
    }

    std::time_t todayDateInTimeT()
    {
        // Get the current time as std::time_t
        std::time_t now = std::time(nullptr);

        // Convert to local time representation (std::tm)
        std::tm localTime = *std::localtime(&now);

        // Reset the time components to represent midnight (00:00:00)
        localTime.tm_hour = 0;
        localTime.tm_min = 0;
        localTime.tm_sec = 0;

        // Convert the modified std::tm back to std::time_t
        std::time_t todayTimeT = std::mktime(&localTime);

        return todayTimeT;
    }

    bool isInteger(const std::string &input)
    {
        if (input.empty() || ((!isdigit(input[0])) && (input[0] != '-') && (input[0] != '+')))
        {
            return false; // Invalid input, not an integer
        }

        char *endPtr; // Pointer to the character following the parsed integer
        std::strtol(input.c_str(), &endPtr, 10);

        // Check if all characters after the integer are whitespaces (endPtr should point to the null terminator)
        for (char ch : std::string(endPtr))
        {
            if (!isspace(ch))
            {
                return false; // Not an integer (contains non-whitespace characters after the integer)
            }
        }

        return true; // Valid integer input
    }

    int comapreDate(std::time_t dateInput, std::time_t dateToCompare)
    {
        // Compare dates
        if (dateInput < dateToCompare)
        {
            return -1;
        }
        else if (dateInput > dateToCompare)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

#endif