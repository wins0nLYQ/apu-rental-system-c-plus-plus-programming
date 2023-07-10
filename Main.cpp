/**
 * FILENAME: Main.cpp
 */

#include <iostream>

#include "Asia_Pacific_Home.h"
#include "DynamicArray.h"
#include "Property.h"
#include "ReadCSV.h"
#include <string>

using namespace std;

int main()
{
    // Asia_Pacific_Home APH;
    // APH.homePage();

    // DynamicArray<Tenant> tenantList;

    // Tenant newTenant("Wong Hau", "hello@gmail.com", "01234567890", "123123123", "Male", "2022-09-01", "hello");
    // tenantList.insertAtEnd(newTenant);

    // Tenant newTenant2("Hello", "Wuuha@gmail.com", "0987654321", "123123123", "Female", "2022-05-01", "hi");
    // tenantList.insertAtEnd(newTenant2);

    // Tenant tent = tenantList.get(0);
    // cout << tent.getName() << endl;



    DynamicArray<Property> propList;
    ReadCSV read;
    propList = read.readCSV("mudah-apartment-kl-selangor.csv");

    Property property = propList.get(0);

    cout << property.getAdsID() << endl;



    // DynamicArray<string> testList;
    // testList.insertAtEnd("Hello");
    // testList.insertAtEnd("Hello 2");

    // for (int i = 0; i < testList.getSize(); ++i)
    // {
    //     cout << testList.get(i) << endl;
    // }
    return 0;
}
