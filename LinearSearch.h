#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Property.h"
#include <chrono>

using namespace std;

class LinearSearch {
    public:
    LinearSearch(){}

    DynamicArray<Property> searchByPropertyName(DynamicArray<Property>& arr, const string& target) {
        // Start Timer
        auto startTime = std::chrono::steady_clock::now();

        DynamicArray<Property> filteredList;
        for(int i = 0; i < arr.getSize(); ++i) {
            Property property = arr.get(i);
            string name = property.getPropName();
            if(name.find(target) != std::string::npos) {
                    filteredList.insertAtEnd(property);
            }
        }

        // End the timer
        auto endTime = std::chrono::steady_clock::now();

        // Calculate the duration in seconds
        std::chrono::duration<double> duration = endTime - startTime;

        // Print the time spent
        std::cout << "Time spent for linear search: " << std::fixed << std::setprecision(4) << duration.count() << " seconds" << std::endl;
        return filteredList; 
    }

    DynamicArray<Property> searchByAdsID(DynamicArray<Property>& arr, const string& target) {
        // Start Timer
        auto startTime = std::chrono::steady_clock::now();

        DynamicArray<Property> filteredList;

        for(int i = 0; i < arr.getSize(); ++i) {
            Property property = arr.get(i);
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
        std::cout << "Time spent for linear search: " << std::fixed << std::setprecision(4) << duration.count() << " seconds" << std::endl;
        return filteredList; 
    }


};




#endif