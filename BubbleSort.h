#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <cmath>
#include <iostream>
#include <algorithm>
#include "Property.h"
#include "DataConversion.h"
#include "ReadCSV.h"
#include "DynamicArray.h"
using namespace std;

class BubbleSort
{

public:
    // Bubble Sort algorithm
    void bubbleSortPropertyName(DynamicArray<Property> &properties)
    {

        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                if (properties.get(j).getPropName() < properties.get(j + 1).getPropName())
                {
                    // Swap properties[j] and properties[j+1]
                    Property temp = properties.get(j);
                    properties.get(j) = properties.get(j + 1);
                    properties.get(j + 1) = temp;
                }
            }
        }
    }

    void bubbleSortByMonthlyRentDecending(DynamicArray<Property> &properties)
    {
        DataConversion dataConversion;
        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                long long rent1 = dataConversion.extractDigit(properties.get(j).getMonthlyRent());
                long long rent2 = dataConversion.extractDigit(properties.get(j + 1).getMonthlyRent());
                if (rent1 < rent2)
                {
                    std::swap(properties.get(j), properties.get(j + 1));
                }
            }
        }
    }

    void bubbleSortByLocationDecending(DynamicArray<Property> &properties)
    {
        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                if (properties.get(j).getLocation() < properties.get(j + 1).getLocation())
                {
                    std::swap(properties.get(j), properties.get(j + 1));
                }
            }
        }
    }

    void bubbleSortBySizeDecending(DynamicArray<Property> &properties)
    {
        DataConversion dataConversion;
        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                long long size1 = dataConversion.extractDigit(properties.get(j).getSize());
                long long size2 = dataConversion.extractDigit(properties.get(j + 1).getSize());
                if (size1 < size2)
                {
                    std::swap(properties.get(j), properties.get(j + 1));
                }
            }
        }
    }

    void bubbleSortByMonthlyRentAscending(DynamicArray<Property> &properties)
    {
        DataConversion dataConversion;
        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                long long rent1 = dataConversion.extractDigit(properties.get(j).getMonthlyRent());
                long long rent2 = dataConversion.extractDigit(properties.get(j + 1).getMonthlyRent());
                if (rent1 > rent2)
                {
                    std::swap(properties.get(j), properties.get(j + 1));
                }
            }
        }
    }

    void bubbleSortByLocationAscending(DynamicArray<Property> &properties)
    {
        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                if (properties.get(j).getLocation() > properties.get(j + 1).getLocation())
                {
                    std::swap(properties.get(j), properties.get(j + 1));
                }
            }
        }
    }

    void bubbleSortBySizeAscending(DynamicArray<Property> &properties)
    {
        DataConversion dataConversion;
        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                long long size1 = dataConversion.extractDigit(properties.get(j).getSize());
                long long size2 = dataConversion.extractDigit(properties.get(j + 1).getSize());
                if (size1 > size2)
                {
                    std::swap(properties.get(j), properties.get(j + 1));
                }
            }
        }
    }

    void calculateBubbleSortTime(DynamicArray<Property> &arr, void (BubbleSort::*sortFunction)(DynamicArray<Property> &))
    {
        // Create an instance of the BubbleSort class
        BubbleSort bubbleSortObj;

        // Start the timer
        auto startTime = std::chrono::steady_clock::now();

        // Perform bubble sort using the provided sort function
        (bubbleSortObj.*sortFunction)(arr);

        // End the timer
        auto endTime = std::chrono::steady_clock::now();

        // Calculate the duration in seconds
        std::chrono::duration<double> duration = endTime - startTime;

        // Print the time spent
        std::cout << "Time spent for bubble sort: " << duration.count() << " seconds" << std::endl;
    }
};

#endif