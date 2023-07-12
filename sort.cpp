#include <iostream>
#include <vector>
#include "Property.h"
#include "ReadCSV.h"
#include "MergeSort.h"

using namespace std;

int main() {
    ReadCSV reader;
    std::vector<Property> properties = reader.readCSV("mudah-apartment-kl-selangor.csv");

    std::cout << "Sort Properties by:" << std::endl;
    std::cout << "1. Monthly Rent" << std::endl;
    std::cout << "2. Location" << std::endl;
    std::cout << "3. Size" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    
    string choice;
    getline(cin >> ws, choice);

    DataValidation validator;
    Property propertyObj;
    if (validator.isNumber(choice)) {
        int decision = stoi(choice);
        cout << " " << endl;
        std::cout << "Sort in:" << std::endl;
        std::cout << "1. Ascending Order" << std::endl;
        std::cout << "2. Descending Order" << std::endl;
        std::cout << "Enter your choice (1-2): ";

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
                        // Sort by monthly rent in ascending order
                        properties = MergeSort::mergeSort(properties, MergeSort::compareMonthlyRentAsc);
                        double timeTaken = MergeSort::performMergeSort(properties, MergeSort::compareMonthlyRentAsc);
                        cout << "Time taken: " << timeTaken/1000 << " seconds" << endl;
                    } else if (orderDecision == 2) {
                        cout << " " << endl;
                        cout << "Sorting based on Monthly Rent in descending order" << std::endl;
                        // Sort by monthly rent in descending order
                        properties = MergeSort::mergeSort(properties, MergeSort::compareMonthlyRentDesc);
                        double timeTaken = MergeSort::performMergeSort(properties, MergeSort::compareMonthlyRentDesc);
                        cout << "Time taken: " << timeTaken/1000 << " seconds" << endl;
                    } else {
                        cout << " " << endl;
                        std::cout << "Invalid input. Please try again." << std::endl;
                        return 0;
                    }
                    break;
                case 2:
                    if (orderDecision == 1) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Monthly Rent in ascending order" << std::endl;
                        // Sort by location in ascending order
                        properties = MergeSort::mergeSort(properties, MergeSort::compareLocationAsc);
                    } else if (orderDecision == 2) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Monthly Rent in descending order" << std::endl;
                        // Sort by location in descending order
                        properties = MergeSort::mergeSort(properties, MergeSort::compareLocationDesc);
                    } else {
                        cout << " " << endl;
                        std::cout << "Invalid input. Please try again." << std::endl;
                        return 0;
                    }
                    break;
                case 3:
                    if (orderDecision == 1) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Size in ascending order" << std::endl;
                        // Sort by size in ascending order
                        properties = MergeSort::mergeSort(properties, MergeSort::compareSizeAsc);
                    } else if (orderDecision == 2) {
                        cout << " " << endl;
                        std::cout << "Sorting based on Size in descending order" << std::endl;
                        // Sort by size in descending order
                        properties = MergeSort::mergeSort(properties, MergeSort::compareSizeDesc);
                    } else {
                        cout << " " << endl;
                        std::cout << "Invalid input. Please try again." << std::endl;
                        return 0;
                    }
                    break;
                default:
                    std::cout << "Invalid input. Please try again." << std::endl;
                    cout << " " << endl;
                    return 0;
            }

            // Display the sorted properties using the displayFilteredPropertyList() function from Property.h
            propertyObj.displayFilteredPropertyList(properties);
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
            cout << " " << endl;
            return 0;
        }
    } else {
        std::cout << "Invalid input. Please try again." << std::endl;
        cout << " " << endl;
        return 0;
    }

    return 0;
}
