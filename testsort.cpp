#include <iostream>
#include <vector>
#include <algorithm>
#include "Property.h"
#include "ReadCSV.h"

// Compare function for sorting properties in descending order based on ads_id
bool compareAdsID(const Property& prop1, const Property& prop2) {
    return prop1.getAdsID() > prop2.getAdsID();
}

// Merge function for merging two sorted vectors based on ads_id
std::vector<Property> merge(std::vector<Property>& left, std::vector<Property>& right) {
    std::vector<Property> merged;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (compareAdsID(left[leftIndex], right[rightIndex])) {
            merged.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            merged.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    // Append remaining elements from left vector
    while (leftIndex < left.size()) {
        merged.push_back(left[leftIndex]);
        leftIndex++;
    }

    // Append remaining elements from right vector
    while (rightIndex < right.size()) {
        merged.push_back(right[rightIndex]);
        rightIndex++;
    }

    return merged;
}

// Merge sort function for sorting properties based on ads_id in descending order
std::vector<Property> mergeSort(std::vector<Property>& properties) {
    if (properties.size() <= 1) {
        return properties;
    }

    int mid = properties.size() / 2;
    std::vector<Property> left(properties.begin(), properties.begin() + mid);
    std::vector<Property> right(properties.begin() + mid, properties.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    ReadCSV reader;
    std::vector<Property> properties = reader.readCSV("mudah-apartment-kl-selangor.csv");

    // Sort properties based on ads_id in descending order
    properties = mergeSort(properties);

    // Print the sorted properties
    reader.printProperties(properties);

    return 0;
}
