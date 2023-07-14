/**
 * WORK: BINARY SEARCH
*/
#include "BinarySearch.h"
#include "ReadCSV.h"
#include "FilterProperty.h"
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

        BinarySearch bs;

        DynamicArray<Property> property;

        /**Search based on property name*/
        bs.binarySearch_PropertyName(items, userInput, property);

        /**Search based on ads id*/
        // bs.binarySearch_AdsId(items, userInput, property);

        // Property prop;
        // bs.binarySearchSingleResult(items, userInput, prop);
        // property.insertAtEnd(prop);

        FilterProperty fp;
        fp.displayFilteredPropertyList(property);
    }
    
    return 0;
}
