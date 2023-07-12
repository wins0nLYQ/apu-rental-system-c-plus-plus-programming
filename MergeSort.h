#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <functional>
#include <chrono>
#include "Property.h"
#include "DataConverstion.h"
#include "DataValidation.h"

class MergeSort {
public:
    MergeSort() {}
    // Compare function for sorting properties in descending order based on monthly_rent
    static bool compareMonthlyRentDesc(const Property& prop1, const Property& prop2) {
        DataConversion dataConversion;
        long long rent1 = dataConversion.extractDigit(prop1.getMonthlyRent());
        long long rent2 = dataConversion.extractDigit(prop2.getMonthlyRent());
        return rent1 > rent2;
    }

    // Compare function for sorting properties in descending order based on location
    static bool compareLocationDesc(const Property& prop1, const Property& prop2) {
        return prop1.getLocation() > prop2.getLocation();
    }

    // Compare function for sorting properties in descending order based on size
    static bool compareSizeDesc(const Property& prop1, const Property& prop2) {
        DataConversion converter;
        long long size1 = converter.extractDigit(prop1.getSize());
        long long size2 = converter.extractDigit(prop2.getSize());
        return size1 > size2;
    }

    // Compare function for sorting properties in ascending order based on monthly_rent
    static bool compareMonthlyRentAsc(const Property& prop1, const Property& prop2) {
        DataConversion dataConversion;
        long long rent1 = dataConversion.extractDigit(prop1.getMonthlyRent());
        long long rent2 = dataConversion.extractDigit(prop2.getMonthlyRent());
        return rent1 < rent2;
    }

    // Compare function for sorting properties in ascending order based on location
    static bool compareLocationAsc(const Property& prop1, const Property& prop2) {
        return prop1.getLocation() < prop2.getLocation();
    }

    // Compare function for sorting properties in ascending order based on size
    static bool compareSizeAsc(const Property& prop1, const Property& prop2) {
        DataConversion converter;
        long long size1 = converter.extractDigit(prop1.getSize());
        long long size2 = converter.extractDigit(prop2.getSize());
        return size1 < size2;
    }

    // Merge function for merging two sorted vectors based on monthly_rent
    static std::vector<Property> merge(std::vector<Property>& left, std::vector<Property>& right, std::function<bool(const Property&, const Property&)> compare) {
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
    static std::vector<Property> mergeSort(std::vector<Property>& properties, std::function<bool(const Property&, const Property&)> compare) {
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

        left = mergeSort(left, compare);
        right = mergeSort(right, compare);

        return merge(left, right, compare);
    }

    // Perform merge sort and return the time taken in milliseconds
    static long long performMergeSort(std::vector<Property>& properties, std::function<bool(const Property&, const Property&)> compare) {
        auto startTime = std::chrono::steady_clock::now();
        properties = mergeSort(properties, compare);
        auto endTime = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    }
};

#endif
