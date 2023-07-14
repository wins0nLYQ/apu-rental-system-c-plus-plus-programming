#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <functional>
#include <chrono>
#include "Property.h"
#include "DataConversion.h"
#include "DataValidation.h"
#include "DynamicArray.h"

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

    // Compare function for sorting properties in ascending order based on property name
    static bool compareNameAsc(const Property& prop1, const Property& prop2) {
        return prop1.getPropName() < prop2.getPropName();
    }

    void merge(DynamicArray<Property>& arr, int left, int mid, int right, std::function<bool(const Property&, const Property&)> compareFunction) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        DynamicArray<int> mergedIndices;

        int i = left;   // Initial index of the first subarray
        int j = mid + 1; // Initial index of the second subarray

        // Merge the subarrays while maintaining the descending order of ads_id
        while (i <= mid && j <= right) {
            if (compareFunction(arr.get(i), arr.get(j))) {
                mergedIndices.insertAtEnd(i);
                i++;
            } else {
                mergedIndices.insertAtEnd(j);
                j++;
            }
        }

        // Copy the remaining elements of the first subarray, if any
        while (i <= mid) {
            mergedIndices.insertAtEnd(i);
            i++;
        }

        // Copy the remaining elements of the second subarray, if any
        while (j <= right) {
            mergedIndices.insertAtEnd(j);
            j++;
        }

        DynamicArray<Property> sortedArr;
        for (int k = 0; k < mergedIndices.getSize(); k++) {
            sortedArr.insertAtEnd(arr.get(mergedIndices.get(k)));
        }

        for (int k = 0; k < sortedArr.getSize(); k++) {
            arr.set(left + k, sortedArr.get(k));
        }
    }

    void mergeSort(DynamicArray<Property>& arr, int left, int right, std::function<bool(const Property&, const Property&)> compareFunction) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Sort first and second halves
            mergeSort(arr, left, mid, compareFunction);
            mergeSort(arr, mid + 1, right, compareFunction);

            // Merge the sorted halves
            merge(arr, left, mid, right, compareFunction);
        }
    }

    // Function to calculate the time spent for merge sort
    void calculateMergeSortTime(DynamicArray<Property>& arr, std::function<bool(const Property&, const Property&)> compareFunction) {
        // Start the timer
        auto startTime = std::chrono::steady_clock::now();

        // Perform merge sort
        MergeSort mergeSortObj;
        mergeSortObj.mergeSort(arr, 0, arr.getSize() - 1, compareFunction);

        // End the timer
        auto endTime = std::chrono::steady_clock::now();

        // Calculate the duration in seconds
        std::chrono::duration<double> duration = endTime - startTime;

        // Print the time spent
        std::cout << "Time spent for merge sort: " << duration.count() << " seconds" << std::endl;
    }

};

#endif // MERGE_SORT_H
