/**
 * FILENAME: Main.cpp
 */

#include <iostream>

#include "Asia_Pacific_Home.h"
#include "DynamicArray.h"
#include "Property.h"
#include "ReadCSV.h"
#include <string>
#include "DataConversion.h"

using namespace std;


int main()
{
    DynamicArray<Manager> managerList;
    Manager newManager("Jesus", "wong@gmail.com", "0987654321", "123123123", "Female", "2022-05-01", "Inactive");
    managerList.insertAtEnd(newManager);
    Asia_Pacific_Home APH;
    APH.manager_HomePage(newManager);
    return 0;
}