#include <iostream>
#include <vector>
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

    // Determine the size of the merged vector
    int mergedSize = left.size() + right.size();
    merged.resize(mergedSize);

    int mergedIndex = 0;

    // Copy data to temp arrays leftArray[] and rightArray[]
    std::vector<Property> leftArray(left);
    std::vector<Property> rightArray(right);

    // Merge the two arrays
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (compareAdsID(leftArray[leftIndex], rightArray[rightIndex])) {
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

    // Print the sorted properties using the printProperties() function from ReadCSV.h
    reader.printProperties(properties);

    return 0;
}
