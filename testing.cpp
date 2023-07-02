#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Property {
    string ads_id;
    string prop_name;
    string completion_year;
    string monthly_rent;
    string location;
    string property_type;
    string rooms;
    string parking;
    string bathroom;
    string size;
    string furnished;
    string facilities;
    string additional_facilities;
    string region;
};

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

vector<Property> readCSV(const string& filename) {
    vector<Property> properties;
    ifstream file(filename);

    if (!file) {
        cerr << "Failed to open the file: " << filename << endl;
        return properties;
    }

    // string line;
    // getline(file, line); // Skip header line

    // while (getline(file, line)) {
    //     istringstream iss(line);
    //     string token;
    //     Property property;

    //     getline(iss, property.ads_id, ',');
    //     getline(iss, property.prop_name, ',');
    //     getline(iss, property.completion_year, ',');
    //     getline(iss, property.monthly_rent, ',');
    //     getline(iss, property.location, ',');
    //     getline(iss, property.property_type, ',');
    //     getline(iss, property.rooms, ',');
    //     getline(iss, property.parking, ',');
    //     getline(iss, property.bathroom, ',');
    //     getline(iss, property.size, ',');
    //     getline(iss, property.furnished, ',');

    //     string facility;
    //     getline(iss, facility, '\"');
    //     getline(iss, facility, '\"');
    //     property.facilities = facility;

    //     string additional_facilities;
    //     getline(iss, additional_facilities, '\"');
    //     getline(iss, additional_facilities, '\"');
    //     property.additional_facilities = additional_facilities;

    //     getline(iss, property.region, ',');

    //     properties.push_back(property);
    // }

    std::string line;
    std::getline(file, line); // Read the header line (optional)

    int i = 0;
    while (std::getline(file, line)) {
      std::vector<std::string> attributes = splitString(line, ','); // Split attributes based on comma delimiter
      char targetChar = '\"';
      std::string newItem = "";

      Property property;

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

      property.ads_id = attributes[0];
      property.prop_name = attributes[1];
      property.completion_year = attributes[2];
      property.monthly_rent = attributes[3];
      property.location = attributes[4];
      property.property_type = attributes[5];
      property.rooms = attributes[6];
      property.parking = attributes[7];
      property.bathroom = attributes[8];
      property.size  = attributes[9];
      property.furnished  = attributes[10];
      property.facilities  = attributes[11];
      property.additional_facilities  = attributes[12];
      property.region  = attributes[13];

      properties.push_back(property);
    }

    file.close();
    return properties;
}

void printProperties(const vector<Property>& properties) {
    int count = 0;
    for (const auto& property : properties) {
        cout << "ads_id: " << property.ads_id << endl;
        cout << "prop_name: " << property.prop_name << endl;
        cout << "completion_year: " << property.completion_year << endl;
        cout << "monthly_rent: " << property.monthly_rent << endl;
        cout << "location: " << property.location << endl;
        cout << "property_type: " << property.property_type << endl;
        cout << "rooms: " << property.rooms << endl;
        cout << "parking: " << property.parking << endl;
        cout << "bathroom: " << property.bathroom << endl;
        cout << "size: " << property.size << endl;
        cout << "furnished: " << property.furnished << endl;
        cout << "facilities: " << property.facilities << endl;
        cout << "additional_facilities: " << property.additional_facilities << endl;
        cout << "region: " << property.region << endl;

        cout << "-----------------------------------" << endl;
        
        count++;
        if (count >= 5) {
            break;
        }
    }
}

int main() {
    vector<Property> properties = readCSV("mudah-apartment-kl-selangor.csv");
    printProperties(properties);
    return 0;
}
