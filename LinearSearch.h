#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Property.h"
#include <chrono>
#include "DataConversion.h"

using namespace std;

class LinearSearch {
    public:
    LinearSearch(){}

    DynamicArray<Property> searchByPropertyName(DynamicArray<Property>& propertyList, const string& target) {
        DataConversion dc;

        // Dynamic Array to Store Matched Property Objects
        DynamicArray<Property> filteredList;

        string formattedTarget = dc.toLowercase(target);

        // Start Timer
        auto startTime = std::chrono::steady_clock::now();
        
        // Searching Process
        for(int i = 0; i < propertyList.getSize(); ++i) {
            Property property = propertyList.get(i);
            string name = dc.toLowercase(property.getPropName());
            if(name.find(formattedTarget) != std::string::npos) {
                    filteredList.insertAtEnd(property);
            }
        }

        // End the timer
        auto endTime = std::chrono::steady_clock::now();

        // Calculate the duration in seconds
        std::chrono::duration<double> duration = endTime - startTime;

        // Print the time spent
        std::cout << "Time spent for linear search: " << duration.count() << " seconds" << std::endl;
        return filteredList; 
    }

    DynamicArray<Property> searchByAdsID(DynamicArray<Property>& propertyList, const string& target) {
        // Start Timer
        auto startTime = std::chrono::steady_clock::now();

        DynamicArray<Property> filteredList;

        for(int i = 0; i < propertyList.getSize(); ++i) {
            Property property = propertyList.get(i);
            string adsID = property.getAdsID();
            if(adsID.find(target) != std::string::npos) {
                    filteredList.insertAtEnd(property);
            }
        }
        
        // End the timer
        auto endTime = std::chrono::steady_clock::now();

        // Calculate the duration in seconds
        std::chrono::duration<double> duration = endTime - startTime;

        // Print the time spent
        std::cout << "Time spent for linear search: " << duration.count() << " seconds" << std::endl;
        return filteredList; 
    }
};




#endif