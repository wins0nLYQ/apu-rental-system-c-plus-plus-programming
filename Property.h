#ifndef PROPERTY_H
#define PROPERTY_H

/**
 * FILENAME: Property.h
 */

// #include <string>
#include <vector>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include "DataConversion.h"

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
        DataConversion dc;
        dc.sort(locationList);
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
        DataConversion dc;
        dc.sort(propertyTypeList);
        return propertyTypeList;
    }

    DynamicArray<string> getAvailableFurnishedType(DynamicArray<Property> &properties)
    {
        DynamicArray<string> furnishedTypeList;

        for (int i = 0; i < properties.getSize(); ++i)
        {
            Property property = properties.get(i);
            std::string furnishedType = property.getFurnished();

            bool flag = false;
            for (int j = 0; j < furnishedTypeList.getSize(); ++j)
            {
                if (furnishedType == furnishedTypeList.get(j))
                {
                    flag = true;
                }
            }

            if (!flag && furnishedType!="")
            {
                furnishedTypeList.insertAtEnd(furnishedType);
            }
        }
        // sort(furnishedTypeList.begin(), furnishedTypeList.end());
        DataConversion dc;
        dc.sort(furnishedTypeList);
        return furnishedTypeList;
    }

    DynamicArray<string> getAvailableRegion(DynamicArray<Property> &properties)
    {
        DynamicArray<string> regionList;

        for (int i = 0; i < properties.getSize(); ++i)
        {
            Property property = properties.get(i);
            string region = property.getRegion();

            // Check if the region is already in the vector
            bool flag = false;
            for (int j = 0; j < regionList.getSize(); ++j)
            {
                if (region == regionList.get(j))
                {
                    flag = true;
                }
            }

            if (!flag)
            {
                regionList.insertAtEnd(region);
            }
        }
        // sort(regionList.begin(), regionList.end());
        DataConversion dc;
        dc.sort(regionList);
        return regionList;
    }

    // Equality comparison operator
    bool operator==(const Property& other) const {
        return this->adsID == other.adsID && 
               this->propName == other.propName &&
               this->completionYear == other.completionYear &&
               this->monthlyRent == other.monthlyRent &&
               this->location == other.location &&
               this->propertyType == other.propertyType &&
               this->rooms == other.rooms &&
               this->parking == other.parking &&
               this->bathroom == other.bathroom &&
               this->size == other.size &&
               this->furnished == other.furnished &&
               this->facilities == other.facilities &&
               this->additionalFacilities == other.additionalFacilities &&
               this->region == other.region;
    }

    bool isEmpty() {
        return this->adsID == "" && 
               this->propName == "" &&
               this->completionYear == "" &&
               this->monthlyRent == "" &&
               this->location == "" &&
               this->propertyType == "" &&
               this->rooms == "" &&
               this->parking == "" &&
               this->bathroom == "" &&
               this->size == "" &&
               this->furnished == "" &&
               this->facilities == "" &&
               this->additionalFacilities == "" &&
               this->region == "";
    }

    void setEmpty() {
        this->adsID = "";
        this->propName = "";
        this->completionYear = "";
        this->monthlyRent = "";
        this->location = "";
        this->propertyType = "";
        this->rooms = "";
        this->parking = "";
        this->bathroom = "";
        this->size = "";
        this->furnished = "";
        this->facilities = "";
        this->additionalFacilities = "";
        this->region = "";
    }
};

#endif