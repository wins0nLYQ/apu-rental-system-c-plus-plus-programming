#ifndef READCSV_H
#define READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Property.h"

class ReadCSV {
  public:
    std::vector<std::string> splitString(const std::string& input, char delimiter);
    std::vector<Property> readCSV(const string& filename);
    void printProperties(const vector<Property>& properties);
};

#endif