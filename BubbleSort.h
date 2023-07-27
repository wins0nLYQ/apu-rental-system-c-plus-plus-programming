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
    // Property property;
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

                    // properties.replace(properties.get(j + 1), j);
                    // properties.replace(temp, j + 1);
                }
            }
        }
    }
};

#endif