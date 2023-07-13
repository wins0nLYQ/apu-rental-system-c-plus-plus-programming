#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <cmath>
#include "DataValidation.h"
#include "Asia_Pacific_Home.h"
#include "Property.h"
#include "DataConverstion.h"
#include "ReadCSV.h"
#include "DynamicArray.h"
#include "Property.h"
using namespace std;

class BubbleSort
{

public:
    // Bubble Sort algorithm
    Property property;
    void bubbleSortPropertyName(DynamicArray<Property> &properties)
    {

        int length = properties.getSize();

        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                if (properties.get(j).getPropName() > properties.get(j + 1).getPropName())
                {
                    // Swap properties[j] and properties[j+1]
                    Property temp = properties.get(j);
                    properties.get(j) = properties.get(j + 1);
                    properties.get(j + 1) = temp;
                }
            }
        }
    }

    int main()
    {
        DynamicArray<Property> properties;
        ReadCSV read;
        properties = read.readCSV("mudah-apartment-kl-selangor.csv");
        property.bubbleSortPropertyName(properties);
    }
};
#endif