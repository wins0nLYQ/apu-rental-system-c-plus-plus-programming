#include <iostream>
#include <algorithm>
#include <chrono>
#include <cmath>
#include "ReadCSV.h"
#include "Property.h" // Include the header file for the Property class
#include "BubbleSort.h"

int main()
{
    ReadCSV read;

    // Step 1: Read the CSV file and store the properties in a DynamicArray
    DynamicArray<Property> properties;
    read.readCSV("mudah-apartment-kl-selangor.csv", properties);

    BubbleSort bubbleSort;

    auto startTime = chrono::steady_clock::now();

    // Step 2: Sort the properties using bubble sort
    bubbleSort.bubbleSortPropertyName(properties);

    auto endTime = chrono::steady_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

    cout << "Bubble sort completed in " << elapsedTime << " milliseconds." << endl;

    int pageSize = 5;    // Number of properties to display per page
    int currentPage = 0; // Current page index

    while (true)
    {
        int startIdx = currentPage * pageSize;
        int endIdx = startIdx + pageSize;

        cout << "[Page " << currentPage + 1 << "]" << endl;
        cout << "---------------------------\n";

        for (int i = startIdx; i < endIdx && i < properties.getSize(); ++i)
        {
            Property property = properties.get(i);
            cout << "Name: " << property.getPropName() << endl;
            cout << "Ads ID: " << property.getAdsID() << endl;
            // Print other attributes...
            cout << "---------------------------\n";
        }

        cout << "Options: (N)ext page, (Q)uit" << endl;
        cout << ">> ";

        string userInput;
        getline(cin >> ws, userInput);
        cout << endl;

        if (userInput == "N" || userInput == "n")
        {
            if (endIdx < properties.getSize())
            {
                currentPage++;
            }
            else
            {
                cout << "No more properties. Reached the last page." << endl;
            }
        }
        else if (userInput == "Q" || userInput == "q")
        {
            break; // Exit the loop
        }
        else
        {
            cout << "Invalid input. Please try again." << endl;
        }
    }

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <chrono>
// #include <cmath>
// #include "ReadCSV.h"
// #include "Property.h" // Include the header file for the Property class
// #include "BubbleSort.h"

// using namespace std;

// int main()
// {
//     ReadCSV read;
//     DynamicArray<Property> properties;
//     // Step 1: Read the CSV file and store the properties in a DynamicArray
//     read.readCSV("mudah-apartment-kl-selangor.csv", properties);

//     BubbleSort bubbleSort;

//     auto startTime = chrono::steady_clock::now();

//     cout << "START" << endl;

//     // Step 2: Take only five rows from the properties array
//     DynamicArray<Property> selectedProperties = properties;
//     int numProperties = min(10, properties.getSize());
//     // int numProperties = properties.getSize();
//     for (int i = 0; i < numProperties ; i++)
//     {
//         selectedProperties.insertAtEnd(properties.get(i));
//     }

//     // Step 3: Sort the selected properties using bubble sort
//     bubbleSort.bubbleSortPropertyName(selectedProperties);

//     auto endTime = chrono::steady_clock::now();
//     auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

//     cout << "Bubble sort completed in " << elapsedTime << " milliseconds." << endl;

//     int pageSize = 10;   // Number of properties to display per page
//     int currentPage = 0; // Current page index

//     while (true)
//     {
//         int startIdx = currentPage * pageSize;
//         int endIdx = startIdx + pageSize;

//         cout << "[Page " << currentPage + 1 << "]" << endl;
//         cout << "---------------------------\n";

//         for (int i = startIdx; i < endIdx && i < selectedProperties.getSize(); ++i)
//         {
//             Property property = selectedProperties.get(i);
//             cout << "Name: " << property.getPropName() << endl;
//             cout << "Ads ID: " << property.getAdsID() << endl;
//             // Print other attributes...
//             cout << "---------------------------\n";
//         }

//         cout << "Options: (N)ext page, (Q)uit" << endl;
//         cout << ">> ";

//         string userInput;
//         getline(cin >> ws, userInput);
//         cout << endl;

//         if (userInput == "N" || userInput == "n")
//         {
//             if (endIdx < selectedProperties.getSize())
//             {
//                 currentPage++;
//             }
//             else
//             {
//                 cout << "No more properties. Reached the last page." << endl;
//             }
//         }
//         else if (userInput == "Q" || userInput == "q")
//         {
//             break; // Exit the loop
//         }
//         else
//         {
//             cout << "Invalid input. Please try again." << endl;
//         }
//     }

//     return 0;
// }
