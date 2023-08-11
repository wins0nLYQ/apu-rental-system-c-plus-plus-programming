#ifndef READCSV_H
#define READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DynamicArray.h"
#include "Property.h"

using namespace std;

class ReadCSV {
  public:
  // Function to split a string based on a delimiter
  std::vector<std::string> splitString(const std::string& input, char delimiter) {
      std::vector<std::string> tokens;
      std::istringstream iss(input);
      std::string token;
      while (std::getline(iss, token, delimiter)) {
          tokens.push_back(token);
      }
      return tokens;
  }

  void readCSV(const string& filename, DynamicArray<Property>& properties) {
      // DynamicArray<Property> properties;
      ifstream file(filename);

      if (!file) {
          cerr << "Failed to open the file: " << filename << endl;
          // return properties;
          return;
      }

      std::string line;
      std::getline(file, line); // Read the header line (optional)

      int i = 0;
      while (std::getline(file, line)) {
        std::vector<std::string> attributes = splitString(line, ','); // Split attributes based on comma delimiter
        char targetChar = '\"';
        std::string newItem = "";

        bool cont = false;

        for (int index = 0; index < attributes.size(); index++) {
          std::string item = attributes[index];

          int count = 0;

          if (item != "") {
            for (char c : item) {
              if (c == targetChar && count == 0) {
                cont = true;
              }
            }

            int last = 0;
            for (char c : item) {
              if (c == targetChar && last == item.length()-1) {
                cont = false;
                newItem = newItem + ", " + item.substr(1, item.length()-2);
                attributes[index] = newItem;
                newItem = "";
              }

              last++;
            }

            if (cont) {
              if (newItem != "") {
                newItem += ", ";
              }

              newItem += item.substr(1, item.length());
              attributes.erase(attributes.begin() + index);
              index--;
            }
          }
        }

        Property property = Property(attributes);

        properties.insertAtEnd(property);
      }

      file.close();
  }

  void printProperties(DynamicArray<Property> properties) {
      Property property;
      for (int i = 0; i < properties.getSize(); ++i) {
        cout << "Hello" << endl;
        property = properties.get(i);
        cout << "ads_id: " << property.getAdsID() << endl;
        cout << "prop_name: " << property.getPropName() << endl;
        cout << "completion_year: " << property.getCompletionYear() << endl;
        cout << "monthly_rent: " << property.getMonthlyRent() << endl;
        cout << "location: " << property.getLocation() << endl;
        cout << "property_type: " << property.getPropertyType() << endl;
        cout << "rooms: " << property.getRooms() << endl;
        cout << "parking: " << property.getParking() << endl;
        cout << "bathroom: " << property.getBathroom() << endl;
        cout << "size: " << property.getSize() << endl;
        cout << "furnished: " << property.getFurnished() << endl;
        cout << "facilities: " << property.getFacilities() << endl;
        cout << "additional_facilities: " << property.getAdditionalFacilities() << endl;
        cout << "region: " << property.getRegion() << endl;

        cout << "-----------------------------------" << endl;
      }
  }
};

#endif