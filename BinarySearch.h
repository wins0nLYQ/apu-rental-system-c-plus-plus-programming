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

    bool hasSubstring_PropName(Property prop, const string& target) {
      string str = prop.getPropName();
      return str.find(target) != string::npos;
    }

    bool hasSubstring_AdsId(Property prop, const string& target) {
      string str = prop.getAdsID();
      return str.find(target) != string::npos;
    }

    void binarySearchPropertyName(DynamicArray<Property> &items, const string& target, Property &property) {
      int left = 0;
      int right = items.getSize() - 1;

      while (left <= right) {
          int mid = left + (right - left) / 2;

          if (hasSubstring_PropName(items.get(mid), target)) {
              // Target item found
              property = items.get(mid);
              break;
          } else if (items.get(mid).getPropName() < target) {
              left = mid + 1;  // Target is in the right half
          } else {
              right = mid - 1;  // Target is in the left half
          }
      }
    }

    void binarySearchAdsId(DynamicArray<Property> &items, const string& target, Property &property) {
      int left = 0;
      int right = items.getSize() - 1;

      while (left <= right) {
          int mid = left + (right - left) / 2;

          if (hasSubstring_AdsId(items.get(mid), target)) {
              // Target item found
              property = items.get(mid);
              break;
          } else if (items.get(mid).getAdsID() < target) {
              left = mid + 1;  // Target is in the right half
          } else {
              right = mid - 1;  // Target is in the left half
          }
      }
    }

    void binarySearch_PropertyName(DynamicArray<Property> &items, const string &target, DynamicArray<Property> &property) {
      MergeSort ms;
      ms.mergeSort(items, 0, items.getSize()-1, MergeSort::compareNameAsc);

      DynamicArray<Property> copyOf = items;

      bool found = true;

      // Start Timer
      auto startTime = std::chrono::steady_clock::now();

      // Perform binary search
      while (found) {
        Property prop;

        binarySearchPropertyName(copyOf, target, prop);

        if (!prop.isEmpty()) {
          property.insertAtEnd(prop);
          copyOf.removeAt(copyOf.getIndex(prop));
        }
        else {
          found = false;
        }
      }

      // End the timer
      auto endTime = std::chrono::steady_clock::now();

      // Calculate the duration in seconds
      std::chrono::duration<double> duration = endTime - startTime;

      // Print the time spent
      std::cout << "Time spent for binary search: " << std::fixed << std::setprecision(4) << duration.count() << " seconds" << std::endl;
    }

    void binarySearch_AdsId(DynamicArray<Property> &items, const string &target, DynamicArray<Property> &property) {
      MergeSort ms;
      ms.mergeSort(items, 0, items.getSize()-1, MergeSort::compareAdsIdAsc);

      DynamicArray<Property> copyOf = items;

      bool found = true;

      // Start Timer
      auto startTime = std::chrono::steady_clock::now();

      // Perform binary search
      while (found) {
        Property prop;

        binarySearchAdsId(copyOf, target, prop);

        if (!prop.isEmpty()) {
          property.insertAtEnd(prop);
          copyOf.removeAt(copyOf.getIndex(prop));
        }
        else {
          found = false;
        }
      }

      // End the timer
      auto endTime = std::chrono::steady_clock::now();

      // Calculate the duration in seconds
      std::chrono::duration<double> duration = endTime - startTime;

      // Print the time spent
      std::cout << "Time spent for binary search: " << std::fixed << std::setprecision(4) << duration.count() << " seconds" << std::endl;
    }

    void binarySearchSingleResult(DynamicArray<Property> &items, const string &target, Property &prop) {
      // Sort the array in ascending order
      MergeSort ms;
      ms.mergeSort(items, 0, items.getSize()-1, MergeSort::compareNameAsc);

      // Start Timer
      auto startTime = std::chrono::steady_clock::now();

      binarySearchPropertyName(items, target, prop);

      // End the timer
      auto endTime = std::chrono::steady_clock::now();

      // Calculate the duration in seconds
      std::chrono::duration<double> duration = endTime - startTime;

      // Print the time spent
      std::cout << "Time spent for binary search: " << std::fixed << std::setprecision(4) << duration.count() << " seconds" << std::endl;
    }
};

#endif