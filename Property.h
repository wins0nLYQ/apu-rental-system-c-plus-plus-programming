#ifndef PROPERTY_H
#define PROPERTY_H

/**
 * FILENAME: Property.h
 */

#include <string>
#include <vector>
#include <iostream>

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
  Property(vector<std::string> attributes)
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
    this->size  = attributes[9];
    this->furnished  = attributes[10];
    this->facilities  = attributes[11];
    this->additionalFacilities  = attributes[12];
    this->region  = attributes[13];
  };

  string getAdsID() const {
    return adsID;
  };
  void setAdsID(const string &adsID)
  {
    this->adsID = adsID;
  };

  string getPropName() const
  {
    return propName;
  };
  void setPropName(const string &propName)
  {
    this->propName = propName;
  };

  string getCompletionYear() const
  {
    return completionYear;
  };
  void setCompletionYear(string completionYear)
  {
    this->completionYear = completionYear;
  };

  string getMonthlyRent() const
  {
    return monthlyRent;
  };
  void setMonthlyRent(string monthlyRent)
  {
    this->monthlyRent = monthlyRent;
  };

  string getLocation() const
  {
    return location;
  };
  void setLocation(const string &location)
  {
    this->location = location;
  };

  string getPropertyType() const
  {
    return propertyType;
  };
  void setPropertyType(const string &propertyType)
  {
    this->propertyType = propertyType;
  };

  string getRooms() const
  {
    return rooms;
  };
  void setRooms(string rooms)
  {
    this->rooms = rooms;
  };

  string getParking() const
  {
    return parking;
  };
  void setParking(string parking)
  {
    this->parking = parking;
  };

  string getBathroom() const
  {
    return bathroom;
  };
  void setBathroom(string bathroom)
  {
    this->bathroom = bathroom;
  };

  string getSize() const
  {
    return size;
  };
  void setSize(string size)
  {
    this->size = size;
  };

  string getFurnished() const
  {
    return furnished;
  };
  void setFurnished(const string &furnished)
  {
    this->furnished = furnished;
  };

  string getFacilities() const
  {
    return facilities;
  };
  void setFacilities(const string &facilities)
  {
    this->facilities = facilities;
  };

  string getAdditionalFacilities() const
  {
    return additionalFacilities;
  };
  void setAdditionalFacilities(const string &additionalFacilities)
  {
    this->additionalFacilities = additionalFacilities;
  };

  string getRegion() const
  {
    return region;
  };
  void setRegion(const string &region)
  {
    this->region = region;
  };
};

#endif