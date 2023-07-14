/**
 * WORK: PREVIOUS VERSION
*/

// #include "DynamicArray.h"
// #include "Property.h"
// #include "ReadCSV.h"
// #include "MergeSort.h"
// #include <algorithm>

// using namespace std;

// bool hasSubstring(Property prop, const string& target) {
//     string str = prop.getPropName();
//     return str.find(target) != string::npos;
// }

// int binarySearchSubstring(DynamicArray<Property> &items, const string& target) {

//     int left = 0;
//     int right = items.getSize() - 1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;

//         if (hasSubstring(items.get(mid), target)) {
//             return mid;  // Target item found
//         } else if (items.get(mid).getPropName() < target) {
//             left = mid + 1;  // Target is in the right half
//         } else {
//             right = mid - 1;  // Target is in the left half
//         }
//     }

//     return -1;  // Target item not found
// }

// int main() {
//     DynamicArray<Property> items;

//     ReadCSV read;
//     read.readCSV("mudah-apartment-kl-selangor.csv", items);

//     MergeSort ms;
//     ms.mergeSort(items, 0, items.getSize()-1, MergeSort::compareNameAsc);

//     string target = "The Hipster";

//     int found = binarySearchSubstring(items, target);

//     std::cout << items.get(found).getAdsID() 
//               << endl
//               << items.get(found).getPropName()
//               << endl;

//     return 0;
// }


/**
 * WORK: LATEST VERSION
*/
#include "BinarySearch.h"
#include "ReadCSV.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    DynamicArray<Property> items;

    ReadCSV read;
    read.readCSV("mudah-apartment-kl-selangor.csv", items);

    while (true) {
        string userInput;
        cout << "What are you searching for: ";
        getline(cin >> ws, userInput);

        Property property;
        BinarySearch bs;
        bs.binarySearch(items, userInput, property);

        cout << "Result: " << endl
            << "Ads ID: " << property.getAdsID() << endl
            << "Property Name: " << property.getPropName() << endl
            << endl;
    }
    
    return 0;
}
