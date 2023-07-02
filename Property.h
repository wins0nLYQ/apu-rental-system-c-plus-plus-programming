#ifndef PROPERTY_H
#define PROPERTY_H

/**
 * FILENAME: Property.h
 */

#include <string>
#include <vector>

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
  Property(vector<std::string> attributes);

  string getAdsID() const;
  void setAdsID(const string &adsID);

  string getPropName() const;
  void setPropName(const string &propName);

  string getCompletionYear() const;
  void setCompletionYear(string completionYear);

  string getMonthlyRent() const;
  void setMonthlyRent(string monthlyRent);

  string getLocation() const;
  void setLocation(const string &location);

  string getPropertyType() const;
  void setPropertyType(const string &propertyType);

  string getRooms() const;
  void setRooms(string rooms);

  string getParking() const;
  void setParking(string parking);

  string getBathroom() const;
  void setBathroom(string bathroom);

  string getSize() const;
  void setSize(string size);

  string getFurnished() const;
  void setFurnished(const string &furnished);

  string getFacilities() const;
  void setFacilities(const string &facilities);

  string getAdditionalFacilities() const;
  void setAdditionalFacilities(const string &additionalFacilities);

  string getRegion() const;
  void setRegion(const string &region);
};

#endif