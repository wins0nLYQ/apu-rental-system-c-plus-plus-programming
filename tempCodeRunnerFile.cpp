
#include "DynamicArray.h"
#include "Property.h"
#include "Asia_Pacific_Home.h"
#include "MergeSort.h"
#include "FilterProperty.h"
#include <algorithm>

using namespace std;

bool hasSubstring(Property prop, const string& target) {
    string str = prop.getPropName();
    return str.find(target) != string::npos;
}

bool binarySearchSubstring(DynamicArray<Property> items, const string& target) {
    DynamicArray<Property> foundList;

    int left = 0;
    int right = items.getSize() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (hasSubstring(items.get(mid), target)) {
            foundList.insertAtEnd(items.get(mid));  // Target item found
        } else if (items.get(mid).getPropName() < target) {
            left = mid + 1;  // Target is in the right half
        } else {
            right = mid - 1;  // Target is in the left half
        }
    }

    return false;  // Target item not found
}

bool compareByName(const Property& prop1, const Property& prop2) {
    return prop1.getPropName() < prop2.getPropName();
}

// Sorting method for DynamicArray<Property> based on property name
void sortByPropertyName(DynamicArray<Property>& propList) {
    std::sort(0, propList.getSize()-1, compareByName);
}

int main() {
    Asia_Pacific_Home APH;

    DynamicArray<Property> items = APH.getPropertyList();
    sortByPropertyName(items);

    FilterProperty fp;
    fp.displayFilteredPropertyList(items);

    // string target = "The";

    // bool found = binarySearchSubstring(items, target);

    // if (found) {
    //     cout << "Item found!" << endl;
    // } else {
    //     cout << "Item not found." << endl;
    // }

    return 0;
}
