#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <iostream>
#include <vector>
#include "DynamicArray.h"

using namespace std;

class LinearSearch {
public:
    template<typename T, typename Compare>
    DynamicArray<T> searchPropertyName(const DynamicArray<T>& arr, const string& target, function<bool(const T&, const string&)> comp) {
        DynamicArray<T> filteredList;
        for (int i = 0; i < arr.getSize(); ++i) {
            if (comp(arr.get(i), target)) {
                filteredList.insertAtEnd(arr.get(i));
            }
        }
        return filteredList; 
    }

    static bool comparePropertyName(const Property& prop, const string& target) {
        string name = prop.getPropName();
        return name.find(target) != std::string::npos;
    }
};




#endif