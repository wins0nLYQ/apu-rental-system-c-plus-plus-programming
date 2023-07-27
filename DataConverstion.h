#ifndef DATACONVERSTION_H
#define DATACONVERSTION_H

#include <string>
#include <algorithm>

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
        string result;
        for (char c : input)
        {
            if (std::isdigit(c))
            {
                result += c;
            }
        }
        long long digit = stoll(result);
        return digit;
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
};

#endif