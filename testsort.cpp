#include <iostream>
#include <vector>
#include <functional>
#include "Property.h"
#include "ReadCSV.h"
#include "DataConverstion.h"
#include "DataValidation.h"

using namespace std;

// Compare function for sorting properties in descending order based on monthly_rent
bool compareMonthlyRentDesc(const Property& prop1, const Property& prop2) {
    DataConversion dataConversion;
    long long rent1 = dataConversion.extractDigit(prop1.getMonthlyRent());
    long long rent2 = dataConversion.extractDigit(prop2.getMonthlyRent());
    return rent1 > rent2;
}

// Compare function for sorting properties in descending order based on location
bool compareLocationDesc(const Property& prop1, const Property& prop2) {
    return prop1.getLocation() > prop2.getLocation();
}

// Compare function for sorting properties in descending order based on size
bool compareSizeDesc(const Property& prop1, const Property& prop2) {
    DataConversion converter;
    long long size1 = converter.extractDigit(prop1.getSize());
    long long size2 = converter.extractDigit(prop2.getSize());
    return size1 > size2;
}

// Compare function for sorting properties in ascending order based on monthly_rent
bool compareMonthlyRentAsc(const Property& prop1, const Property& prop2) {
    DataConversion dataConversion;
    long long rent1 = dataConversion.extractDigit(prop1.getMonthlyRent());
    long long rent2 = dataConversion.extractDigit(prop2.getMonthlyRent());
    return rent1 < rent2;
}

// Compare function for sorting properties in ascending order based on location
bool compareLocationAsc(const Property& prop1, const Property& prop2) {
    return prop1.getLocation() < prop2.getLocation();
}

// Compare function for sorting properties in ascending order based on size
bool compareSizeAsc(const Property& prop1, const Property& prop2) {
    DataConversion converter;
    long long size1 = converter.extractDigit(prop1.getSize());
    long long size2 = converter.extractDigit(prop2.getSize());
    return size1 < size2;
}

// Merge function for merging two sorted vectors based on monthly_rent
std::vector<Property> merge(std::vector<Property>& left, std::vector<Property>& right, std::function<bool(const Property&, const Property&)> compare) {
    std::vector<Property> merged;
    int leftIndex = 0;
    int rightIndex = 0;

    // Determine the size of the merged vector
    int mergedSize = left.size() + right.size();
    merged.resize(mergedSize);

    int mergedIndex = 0;

    // Copy data to temp arrays leftArray[] and rightArray[]
    std::vector<Property> leftArray(left.size());
    std::vector<Property> rightArray(right.size());

    // Copy data to temp arrays
    for (int i = 0; i < left.size(); i++) {
        leftArray[i] = left[i];
    }

    for (int i = 0; i < right.size(); i++) {
        rightArray[i] = right[i];
    }

    // Merge the two arrays
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (compare(leftArray[leftIndex], rightArray[rightIndex])) {
            merged[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            merged[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    // Copy the remaining elements from left vector, if any
    while (leftIndex < leftArray.size()) {
        merged[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    // Copy the remaining elements from right vector, if any
    while (rightIndex < rightArray.size()) {
        merged[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    return merged;
}

// Merge sort function for sorting properties based on monthly_rent in descending order
std::vector<Property> mergeSort(std::vector<Property>& properties, std::function<bool(const Property&, const Property&)> compare) {
    if (properties.size() <= 1) {
        return properties;
    }

    int mid = properties.size() / 2;
    std::vector<Property> left(properties.size() - mid);
    std::vector<Property> right(mid);

    // Copy data to left and right vectors
    for (int i = 0; i < properties.size(); i++) {
        if (i < mid) {
            right[i] = properties[i];
        } else {
            left[i - mid] = properties[i];
        }
    }

    left = mergeSort(left,compare);
    right = mergeSort(right,compare);

    return merge(left, right,compare);
}

int main() {
    ReadCSV reader;
    std::vector<Property> properties = reader.readCSV("mudah-apartment-kl-selangor.csv");

    std::cout << "Sort Properties by:" << std::endl;
    std::cout << "1. Monthly Rent" << std::endl;
    std::cout << "2. Location" << std::endl;
    std::cout << "3. Size" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    
    string choice;
    getline(cin >> ws, choice);

    DataValidation validator;
    Property propertyObj;
    if (validator.isNumber(choice)) {
        int decision = stoi(choice);
        cout << " " << endl;
        std::cout << "Sort in:" << std::endl;
        std::cout << "1. Ascending Order" << std::endl;
        std::cout << "2. Descending Order" << std::endl;
        std::cout << "Enter your choice (1-2): ";

        string orderChoice;
        getline(cin >> ws, orderChoice);

        if (validator.isNumber(orderChoice)) {
            int orderDecision = stoi(orderChoice);

            // Sort properties based on user's choice
            switch (decision) {
                case 1:
                    if (orderDecision == 1) {
                        cout << " " << endl;
                        cout << "Sorting based on Monthly Rent in ascending order" << std::endl;
                        // Sort by monthly rent in ascending order
                        properties = mergeSort(properties, compareMonthlyRentAsc);
                    } else if (orderDecision == 2) {
                        cout << " " << endl;
                        cout << "Sorting based on Monthly Rent in descending order" << std::endl;
                        // Sort by monthly rent in descending order
                        properties = mergeSort(properties, compareMonthlyRentDesc);
                    } else {
                        cout << " " << endl;
                        std::cout << "Invalid input. Please try again." << std::endl;
                        return 0;
                    }
                    break;
                case 2:
                    if (orderDecision == 1) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Monthly Rent in asecending order" << std::endl;
                        // Sort by location in ascending order
                        properties = mergeSort(properties, compareLocationAsc);
                    } else if (orderDecision == 2) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Monthly Rent in descending order" << std::endl;
                        // Sort by location in descending order
                        properties = mergeSort(properties, compareLocationDesc);
                    } else {
                        cout << " " << endl;
                        std::cout << "Invalid input. Please try again." << std::endl;
                        return 0;
                    }
                    break;
                case 3:
                    if (orderDecision == 1) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Size in ascending order" << std::endl;
                        // Sort by size in ascending order
                        properties = mergeSort(properties, compareSizeAsc);
                    } else if (orderDecision == 2) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Size in desencing order" << std::endl;
                        // Sort by size in descending order
                        properties = mergeSort(properties, compareSizeDesc);
                    } else {
                        cout << " " << endl;
                        std::cout << "Invalid input. Please try again." << std::endl;
                        return 0;
                    }
                    break;
                default:
                    std::cout << "Invalid input. Please try again." << std::endl;
                    cout << " " << endl;
                    return 0;
            }

            // Display the sorted properties using the displayFilteredPropertyList() function from Property.h
            propertyObj.displayFilteredPropertyList(properties);
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
            cout << " " << endl;
            return 0;
        }
    } else {
        std::cout << "Invalid input. Please try again." << std::endl;
        cout << " " << endl;
        return 0;
    }

    return 0;
}


