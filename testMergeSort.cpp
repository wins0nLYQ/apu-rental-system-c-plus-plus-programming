#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "DynamicArray.h"
#include "Property.h"
#include "ReadCSV.h"
#include "DataConversion.h"
#include "DataValidation.h"
#include "MergeSort.h"
#include "FilterProperty.h"

using namespace std;

int main() {
    ReadCSV csvReader;
    Property propertyObj;
    MergeSort mergeSortObj;
    DynamicArray<Property> properties;
    
    csvReader.readCSV("mudah-apartment-kl-selangor.csv", properties);
    // Define the comparison function based on the user's choice
    std::function<bool(const Property&, const Property&)> compareFunction;

    std::cout << "Sort Properties by:" << std::endl;
    std::cout << "1. Monthly Rent" << std::endl;
    std::cout << "2. Location" << std::endl;
    std::cout << "3. Size" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    
    string choice;
    getline(cin >> ws, choice);

    DataValidation validator;
    if (validator.isNumber(choice)) {
        int decision = stoi(choice);
        if(decision > 0 && decision < 4){
            cout << " " << endl;
            std::cout << "Sort in:" << std::endl;
            std::cout << "1. Ascending Order" << std::endl;
            std::cout << "2. Descending Order" << std::endl;
            std::cout << "3. Back" << std::endl;
            std::cout << "Enter your choice (1-3): ";

            string orderChoice;
            getline(cin >> ws, orderChoice);

            if (validator.isNumber(orderChoice)) {
                int orderDecision = stoi(orderChoice);

                // Sort properties based on user's choice
                switch (decision) {
                    case 1:
                        if (orderDecision == 1) {
                            cout << " " << endl;
                            cout << "Sorting based on Monthly Rent in ascending order" << std::endl;
                            compareFunction = MergeSort::compareMonthlyRentAsc;
                        } else if (orderDecision == 2) {
                            cout << " " << endl;
                            cout << "Sorting based on Monthly Rent in descending order" << std::endl;
                            compareFunction = MergeSort::compareMonthlyRentDesc;
                        } else if (orderDecision == 3) {
                            // Go back to the first selection
                            cout << " " << endl;
                            return main();
                        } else {
                            cout << " " << endl;
                            std::cout << "Invalid input. Please try again." << std::endl;
                            return main();
                        }
                        break;
                    case 2:
                        if (orderDecision == 1) {
                            cout << " " << endl;
                            std::cout << "Sorting based on Location in ascending order" << std::endl;
                            compareFunction = MergeSort::compareLocationAsc;
                        } else if (orderDecision == 2) {
                            cout << " " << endl;
                            std::cout << "Sorting based on Location in descending order" << std::endl;
                            compareFunction = MergeSort::compareLocationDesc;
                        } else if (orderDecision == 3) {
                            // Go back to the first selection
                            cout << " " << endl;
                            return main();
                        } else {
                            cout << " " << endl;
                            std::cout << "Invalid input. Please try again." << std::endl;
                            return main();
                        }
                        break;
                    case 3:
                        if (orderDecision == 1) {
                            cout << " " << endl;
                            std::cout << "Sorting based on Size in ascending order" << std::endl;
                            compareFunction = MergeSort::compareSizeAsc;
                        } else if (orderDecision == 2) {
                            cout << " " << endl;
                            std::cout << "Sorting based on Size in descending order" << std::endl;
                            compareFunction = MergeSort::compareSizeDesc;
                        } else if (orderDecision == 3) {
                            // Go back to the first selection
                            cout << " " << endl;
                            return main();
                        } else {
                            cout << " " << endl;
                            std::cout << "Invalid input. Please try again." << std::endl;
                            return main();
                        }
                        break;
                    default:
                        std::cout << "Invalid input. Please try again." << std::endl;
                        cout << " " << endl;
                        return main();
                }
                // Sort properties based on the user's choice using merge sort
                mergeSortObj.mergeSort(properties, 0, properties.getSize() - 1, compareFunction);
                // Calculate the time spent for merge sort
                mergeSortObj.calculateMergeSortTime(properties, compareFunction);

                // Display the sorted properties using the displayFilteredPropertyList() function from Property.h
                FilterProperty fp;
                fp.displayFilteredPropertyList(properties);
            } else {
                std::cout << "Invalid input. Please try again." << std::endl;
                cout << " " << endl;
                return main();
            }
        }else {
            std::cout << "Invalid input. Please try again." << std::endl;
            cout << " " << endl;
            return main();
        } 
    } else {
        std::cout << "Invalid input. Please try again." << std::endl;
        cout << " " << endl;
        return main();
    }

    return 0;
}
