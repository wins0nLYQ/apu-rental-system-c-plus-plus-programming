#ifndef PROPERTY_H
#define PROPERTY_H

/**
 * FILENAME: Property.h
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Property
{
private:
    string adsID;
    string propName;
    string completionYear;
    string monthlyRent;
    string location;
    string propertyType;
    string rooms;
    string parking;
    string bathroom;
    string size;
    string furnished;
    string facilities;
    string additionalFacilities;
    string region;

public:
    Property() {}

    Property(vector<string> attributes)
    {
        this->adsID = attributes[0];
        this->propName = attributes[1];
        this->completionYear = attributes[2];
        this->monthlyRent = attributes[3];
        this->location = attributes[4];
        this->propertyType = attributes[5];
        this->rooms = attributes[6];
        this->parking = attributes[7];
        this->bathroom = attributes[8];
        this->size = attributes[9];
        this->furnished = attributes[10];
        this->facilities = attributes[11];
        this->additionalFacilities = attributes[12];
        this->region = attributes[13];
    }

    string getAdsID() const
    {
        return adsID;
    }

    void setAdsID(const string &adsID)
    {
        this->adsID = adsID;
    }

    string getPropName() const
    {
        return propName;
    }

    void setPropName(const string &propName)
    {
        this->propName = propName;
    }

    string getCompletionYear() const
    {
        return completionYear;
    }

    void setCompletionYear(string completionYear)
    {
        this->completionYear = completionYear;
    }

    string getMonthlyRent() const
    {
        return monthlyRent;
    }

    void setMonthlyRent(string monthlyRent)
    {
        this->monthlyRent = monthlyRent;
    }

    string getLocation() const
    {
        return location;
    }

    void setLocation(const string &location)
    {
        this->location = location;
    }

    string getPropertyType() const
    {
        return propertyType;
    }

    void setPropertyType(const string &propertyType)
    {
        this->propertyType = propertyType;
    }

    string getRooms() const
    {
        return rooms;
    }

    void setRooms(string rooms)
    {
        this->rooms = rooms;
    }

    string getParking() const
    {
        return parking;
    }

    void setParking(string parking)
    {
        this->parking = parking;
    }

    string getBathroom() const
    {
        return bathroom;
    }

    void setBathroom(string bathroom)
    {
        this->bathroom = bathroom;
    }

    string getSize() const
    {
        return size;
    }

    void setSize(string size)
    {
        this->size = size;
    }

    string getFurnished() const
    {
        return furnished;
    }

    void setFurnished(const string &furnished)
    {
        this->furnished = furnished;
    }

    string getFacilities() const
    {
        return facilities;
    }

    void setFacilities(const string &facilities)
    {
        this->facilities = facilities;
    }

    string getAdditionalFacilities() const
    {
        return additionalFacilities;
    }

    void setAdditionalFacilities(const string &additionalFacilities)
    {
        this->additionalFacilities = additionalFacilities;
    }

    string getRegion() const
    {
        return region;
    }

    void setRegion(const string &region)
    {
        this->region = region;
    }

    DynamicArray<string> getAvailableLocation(DynamicArray<Property> &properties)
    {
        DynamicArray<string> locationList;

        for (int i = 0; i < properties.getSize(); i++)
        {
            Property x = properties.get(i);
            string location = x.getLocation();
            cout << location << endl;
            bool flag = false;
            for (int j = 0; j < locationList.getSize(); j++)
            {
                if (location == locationList.get(j))
                {
                    flag = true;
                }
            }

            if (!flag)
            {
                locationList.insertAtEnd(location);
            }
        }
        // sort(locationList.begin(), locationList.end());
        cout << locationList.get(0);
        return locationList;
    }

    DynamicArray<string> getAvailablePropertyType(DynamicArray<Property> &properties)
    {
        DynamicArray<string> propertyTypeList;

        for (int i = 0; i < properties.getSize(); ++i)
        {
            Property property = properties.get(i);
            string propertyType = property.getPropertyType();

            bool flag = false;
            for (int j = 0; j < propertyTypeList.getSize(); ++j)
            {
                if (propertyType == propertyTypeList.get(j))
                {
                    flag = true;
                }
            }

            if (!flag)
            {
                propertyTypeList.insertAtEnd(propertyType);
            }
        }
        // sort(propertyTypeList.begin(), propertyTypeList.end());
        return propertyTypeList;
    }

    vector<string> getAvailableFurnishedType(DynamicArray<Property> &properties)
    {
        std::vector<std::string> furnishedTypeList;

        for (int i = 0; i < properties.getSize(); ++i)
        {
            Property property = properties.get(i);
            std::string furnishedType = property.getFurnished();

            if (furnishedType != "")
            {
                // Check if the region is already in the vector
                if (find(furnishedTypeList.begin(), furnishedTypeList.end(), furnishedType) == furnishedTypeList.end())
                {
                    // Region is not found, add it to the vector
                    furnishedTypeList.push_back(furnishedType);
                }
            }
        }
        std::sort(furnishedTypeList.begin(), furnishedTypeList.end());
        return furnishedTypeList;
    }

    vector<string> getAvailableRegion(DynamicArray<Property> &properties)
    {
        vector<string> regionList;

        for (int i = 0; i < properties.getSize(); ++i)
        {
            Property property = properties.get(i);
            string region = property.getRegion();

            // Check if the region is already in the vector
            if (find(regionList.begin(), regionList.end(), region) == regionList.end())
            {
                // Region is not found, add it to the vector
                regionList.push_back(region);
            }
        }
        sort(regionList.begin(), regionList.end());
        return regionList;
    }

    void displayFilteredPropertyList(DynamicArray<Property> &filteredList)
    {
        int pageSize = 5;    // Number of items to display per page
        int currentPage = 0; // Current page index

        while (true)
        {
            int startIdx = currentPage * pageSize;
            int endIdx = startIdx + pageSize;

            cout << "[RESULT]" << endl;
            cout << "Page " << currentPage + 1 << " / " << ceil(static_cast<double>(filteredList.getSize()) / pageSize) << endl;
            cout << "---------------------------\n";

            for (int i = startIdx; i < endIdx && i < filteredList.getSize(); ++i)
            {
                Property property = filteredList.get(i);
                std::cout << "Ads ID: " << property.getAdsID() << std::endl;
                std::cout << "Property Name: " << property.getPropName() << std::endl;
                std::cout << "Completion Year: " << property.getCompletionYear() << std::endl;
                std::cout << "Monthly Rent: " << property.getMonthlyRent() << std::endl;
                std::cout << "Location: " << property.getLocation() << std::endl;
                std::cout << "Property Type: " << property.getPropertyType() << std::endl;
                std::cout << "Rooms: " << property.getRooms() << std::endl;
                std::cout << "Parking: " << property.getParking() << std::endl;
                std::cout << "Bathroom: " << property.getBathroom() << std::endl;
                std::cout << "Size: " << property.getSize() << std::endl;
                std::cout << "Furnished: " << property.getFurnished() << std::endl;
                std::cout << "Facilities: " << property.getFacilities() << std::endl;
                std::cout << "Additional Facilities: " << property.getAdditionalFacilities() << std::endl;
                std::cout << "Region: " << property.getRegion() << std::endl;
                std::cout << "---------------------------\n";
            }
            cout << "Options: (N)ext page, (P)revious page, (Q)uit" << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "N" || userInput == "n")
            {
                if (endIdx < filteredList.getSize())
                {
                    currentPage++;
                }
                else
                {
                    cout << "No more items. Reached the last page." << endl;
                }
            }
            else if (userInput == "P" || userInput == "p")
            {
                if (currentPage > 0)
                {
                    currentPage--;
                }
                else
                {
                    cout << "Already on the first page." << endl;
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
    }

    bool operator<(const Property &other) const
    {
        return this->propName < other.getPropName();
    }
};

#endif