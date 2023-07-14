#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iostream>

#include "DynamicArray.h"
#include "Property.h"
#include "MergeSort.h"

class BinarySearch 
{
  public:
    BinarySearch(){};

    bool hasSubstring(Property prop, const string& target) {
      string str = prop.getPropName();
      return str.find(target) != string::npos;
    }

    void binarySearchSubstring(DynamicArray<Property> &items, const string& target, Property &property) {
      // Start Timer
      auto startTime = std::chrono::steady_clock::now();

      int left = 0;
      int right = items.getSize() - 1;

      while (left <= right) {
          int mid = left + (right - left) / 2;

          if (hasSubstring(items.get(mid), target)) {
              // Target item found
              property = items.get(mid);
              break;
          } else if (items.get(mid).getPropName() < target) {
              left = mid + 1;  // Target is in the right half
          } else {
              right = mid - 1;  // Target is in the left half
          }
      }

      // End the timer
      auto endTime = std::chrono::steady_clock::now();

      // Calculate the duration in seconds
      std::chrono::duration<double> duration = endTime - startTime;

      // Print the time spent
      std::cout << "Time spent for binary search: " << std::fixed << std::setprecision(4) << duration.count() << " seconds" << std::endl;
    }

    void binarySearch(DynamicArray<Property> &items, const string &target, Property &property) {
      // Sort the array in ascending order
      MergeSort ms;
      ms.mergeSort(items, 0, items.getSize()-1, MergeSort::compareNameAsc);

      // Perform binary search
      binarySearchSubstring(items, target, property);
    }
};

#endif