#include <iostream>
#include <vector>
#include "Property.h"
#include "ReadCSV.h"
#include "DataConverstion.h"

// Compare function for sorting properties in descending order based on monthly_rent
bool compareMonthlyRent(const Property& prop1, const Property& prop2) {
    DataConversion dataConversion;
    long long rent1 = dataConversion.extractDigit(prop1.getMonthlyRent());
    long long rent2 = dataConversion.extractDigit(prop2.getMonthlyRent());
    return rent1 > rent2;
}

// Compare function for sorting properties in descending order based on size
bool compareSize(const Property& prop1, const Property& prop2) {
    DataConversion converter;
    long long size1 = converter.extractDigit(prop1.getSize());
    long long size2 = converter.extractDigit(prop2.getSize());
    return size1 > size2;
}

// Merge function for merging two sorted vectors based on monthly_rent
std::vector<Property> merge(std::vector<Property>& left, std::vector<Property>& right) {
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
        if (compareMonthlyRent(leftArray[leftIndex], rightArray[rightIndex])) {
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
std::vector<Property> mergeSort(std::vector<Property>& properties) {
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

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    ReadCSV reader;
    std::vector<Property> properties = reader.readCSV("mudah-apartment-kl-selangor.csv");

    DataConversion converter;

    std::cout << "Sort Properties by:" << std::endl;
    std::cout << "1. Monthly Rent" << std::endl;
    std::cout << "2. Location" << std::endl;
    std::cout << "3. Size" << std::endl;
    std::cout << "Enter your choice (1-3): ";

    int choice;
    std::cin >> choice;

    std::vector<Property> sortedProperties;

    switch (choice) {
        case 1: {
            std::cout << "Sorting based on Monthly Rent" << std::endl;

            // Extract the monthly rent digits for sorting
            for (Property& property : properties) {
                std::string rent = property.getMonthlyRent();
                long long rentDigits = converter.extractDigit(rent);
                property.setMonthlyRent(std::to_string(rentDigits));
            }

            // Sort properties based on monthly rent in descending order
            sortedProperties = mergeSort(properties);

            // Convert the monthly rent back to original format for display
            for (Property& property : sortedProperties) {
                long long rentDigits = std::stoll(property.getMonthlyRent());
                std::string rent = "RM " + std::to_string(rentDigits) + " per month";
                property.setMonthlyRent(rent);
            }

            break;
        }
        case 2: {
            std::cout << "Sorting based on Location" << std::endl;

            // Sort properties based on location in ascending order
            std::sort(properties.begin(), properties.end(), [](const Property& prop1, const Property& prop2) {
                return prop1.getLocation() < prop2.getLocation();
            });

            sortedProperties = properties;
            break;
        }
        case 3: {
            std::cout << "Sorting based on Size" << std::endl;

            // Extract the size digits for sorting
            for (Property& property : properties) {
                std::string size = property.getSize();
                long long sizeDigits = converter.extractDigit(size);
                property.setSize(std::to_string(sizeDigits));
            }

            // Sort properties based on size in descending order
            sortedProperties = mergeSort(properties);

            // Convert the size back to original format for display
            for (Property& property : sortedProperties) {
                long long sizeDigits = std::stoll(property.getSize());
                std::string size = std::to_string(sizeDigits) + " sq.ft.";
                property.setSize(size);
            }

            break;
        }
        default:
            std::cout << "Invalid choice. Exiting..." << std::endl;
            return 0;
    }

    // Display the sorted properties
    Property property;
    property.displayFilteredPropertyList(sortedProperties);

    return 0;
}
