#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "DynamicArray.h"
#include "Property.h"
#include "MergeSort.h"
#include "DataConversion.h"

class BinarySearch 
{
  private:
    MergeSort ms;
    DataConversion dc;
    DynamicArray<Property> propertyList;
    
  public:
    BinarySearch(DynamicArray<Property> &propList){
      for (int count = 0; count < propList.getSize(); count++) {
        propertyList.insertAtEnd(propList.get(count));
      }
    };

    Property binarySearchPropertyName(DynamicArray<Property> &items, const string& target) {
      int left = 0;
      int right = items.getSize() - 1;

      while (left <= right) {
          int mid = left + (right - left) / 2;

          if (hasSubstring_PropName(items.get(mid), target)) {
              // Target item found
              return items.get(mid);
          } else if (dc.toLowercase(items.get(mid).getPropName()) < target) {
              left = mid + 1;  // Target is in the right half
          } else {
              right = mid - 1;  // Target is in the left half
          }
      }

      Property prop;
      return prop;
    }

    DynamicArray<Property> binarySearch_PropertyName(const string &target) {
      ms.mergeSort(propertyList, 0, propertyList.getSize()-1, MergeSort::compareNameAsc);

      DynamicArray<Property> property;
      
      bool found = true;

      // Start Timer
      auto startTime = std::chrono::steady_clock::now();

      // Perform binary search
      while (found) {
        Property prop = binarySearchPropertyName(propertyList, dc.toLowercase(target));

        if (!prop.isEmpty()) {
          property.insertAtEnd(prop);
          propertyList.removeAt(propertyList.getIndex(prop));
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
      std::cout << "Time spent for binary search: " << duration.count() << " seconds" << std::endl;

      return property;
    }

    Property binarySearchAdsId(DynamicArray<Property> &items, const string& target) {
      int left = 0;
      int right = items.getSize() - 1;

      while (left <= right) {
          int mid = left + (right - left) / 2;

          if (hasSubstring_AdsId(items.get(mid), target)) {
              // Target item found
              return items.get(mid);
          } else if (items.get(mid).getAdsID() < target) {
              left = mid + 1;  // Target is in the right half
          } else {
              right = mid - 1;  // Target is in the left half
          }
      }

      Property prop;
      return prop;
    }

    DynamicArray<Property> binarySearch_AdsId(const string &target) {
      ms.mergeSort(propertyList, 0, propertyList.getSize()-1, MergeSort::compareAdsIdAsc);

      DynamicArray<Property> property;

      bool found = true;

      // Start Timer
      auto startTime = std::chrono::steady_clock::now();

      // Perform binary search
      while (found) {
        Property prop = binarySearchAdsId(propertyList, target);

        if (!prop.isEmpty()) {
          property.insertAtEnd(prop);
          propertyList.removeAt(propertyList.getIndex(prop));
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
      std::cout << "Time spent for binary search: " << duration.count() << " seconds" << std::endl;

      return property;
    }

    bool hasSubstring_PropName(Property& prop, const string& target) {
      string str = dc.toLowercase(prop.getPropName());
      return str.find(target) != string::npos;
    }

    bool hasSubstring_AdsId(Property prop, const string& target) {
      string str = prop.getAdsID();
      return str.find(target) != string::npos;
    }
};

#endif