/**
 * FILENAME: Property.h
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Property {
  private:
    string adsID;
    string propName;
    int completionYear;
    double monthlyRent;
    string location;
    string propertyType;
    int rooms;
    int parking;
    int bathroom;
    int size;
    string furnished;
    vector<string> facilities;
    vector<string> additionalFacilities;

  public:
    string getAdsID() const;
    void setAdsID(const string& adsID);

    string getPropName() const;
    void setPropName(const string& propName);

    int getCompletionYear() const;
    void setCompletionYear(int completionYear);

    double getMonthlyRent() const;
    void setMonthlyRent(double monthlyRent);

    string getLocation() const;
    void setLocation(const string& location);

    string getPropertyType() const;
    void setPropertyType(const string& propertyType);

    int getRooms() const;
    void setRooms(int rooms);

    int getParking() const;
    void setParking(int parking);

    int getBathroom() const;
    void setBathroom(int bathroom);

    int getSize() const;
    void setSize(int size);

    string getFurnished() const;
    void setFurnished(const string& furnished);

    vector<string> getFacilities() const;
    void setFacilities(const vector<string>& facilities);

    vector<string> getAdditionalFacilities() const;
    void setAdditionalFacilities(const vector<string>& additionalFacilities);
};