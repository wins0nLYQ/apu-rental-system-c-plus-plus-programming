#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Property.h"

using namespace std;

class LinearSearch {
public:
    DynamicArray<Property> searchByPropertyName(DynamicArray<Property>& arr, const string& target) {
        DynamicArray<Property> filteredList;

        for(int i = 0; i < arr.getSize(); ++i) {
            Property property = arr.get(i);
            string name = property.getPropName();
            if(name.find(target) != std::string::npos) {
                    filteredList.insertAtEnd(property);
            }
        }

        return filteredList; 
    }

    DynamicArray<Property> searchByAdsID(DynamicArray<Property>& arr, const string& target) {
        DynamicArray<Property> filteredList;

        for(int i = 0; i < arr.getSize(); ++i) {
            Property property = arr.get(i);
            string adsID = property.getAdsID();
            if(adsID.find(target) != std::string::npos) {
                    filteredList.insertAtEnd(property);
            }
        }
        
        return filteredList; 
    }


};




#endif