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

// Compare function for sorting properties in ascending order based on location
bool compareLocation(const Property& prop1, const Property& prop2) {
    return prop1.getLocation() > prop2.getLocation();
}

// Compare function for sorting properties in descending order based on size
bool compareSize(const Property& prop1, const Property& prop2) {
    DataConversion converter;
    long long size1 = converter.extractDigit(prop1.getSize());
    long long size2 = converter.extractDigit(prop2.getSize());
    return size1 > size2;
}

// Merge function for merging two sorted vectors based on monthly_rent
void merge(std::vector<Property>& merged, const std::vector<Property>& left, const std::vector<Property>& right, string option) {
    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = 0;

    if(option == "mr"){
        while (leftIndex < left.size() && rightIndex < right.size()) {
        if (compareMonthlyRent(left[leftIndex], right[rightIndex])) {
            merged[mergedIndex] = left[leftIndex];
            leftIndex++;
        } else {
            merged[mergedIndex] = right[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }
    }else if(option == "lc"){
        while (leftIndex < left.size() && rightIndex < right.size()) {
        if (compareLocation(left[leftIndex], right[rightIndex])) {
            merged[mergedIndex] = left[leftIndex];
            leftIndex++;
        } else {
            merged[mergedIndex] = right[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }
    }else if(option == "sz"){
        while (leftIndex < left.size() && rightIndex < right.size()) {
        if (compareSize(left[leftIndex], right[rightIndex])) {
            merged[mergedIndex] = left[leftIndex];
            leftIndex++;
        } else {
            merged[mergedIndex] = right[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }
    }

    

    while (leftIndex < left.size()) {
        merged[mergedIndex] = left[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < right.size()) {
        merged[mergedIndex] = right[rightIndex];
        rightIndex++;
        mergedIndex++;
    }
}

// Merge sort function for sorting properties based on monthly_rent in descending order
void mergeSort(std::vector<Property>& properties, string option) {
    if (properties.size() <= 1) {
        return;
    }

    int mid = properties.size() / 2;
    std::vector<Property> left(properties.begin(), properties.begin() + mid);
    std::vector<Property> right(properties.begin() + mid, properties.end());

    mergeSort(left,option);
    mergeSort(right,option);

    merge(properties, left, right, option);
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

    switch (choice) {
        case 1: {
            std::cout << "Sorting based on Monthly Rent" << std::endl;

            // Sort properties based on monthly rent in descending order
            mergeSort(properties,"mr");

            break;
        }
        case 2: {
            std::cout << "Sorting based on Location" << std::endl;

            // Sort properties based on location in descending order
            mergeSort(properties,"lc");

            break;
        }
        case 3: {
            std::cout << "Sorting based on Size" << std::endl;

            // Sort properties based on size in descending order
            mergeSort(properties,"sz");

            break;
        }
        default:
            std::cout << "Invalid choice. Exiting..." << std::endl;
            return 0;
    }

    // Display the sorted properties
    Property property;
    property.displayFilteredPropertyList(properties);

    return 0;
}
