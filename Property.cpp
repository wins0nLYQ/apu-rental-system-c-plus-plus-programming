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

string Property::getAdsID() const {
    return adsID;
}

void Property::setAdsID(const string& adsID) {
    this->adsID = adsID;
}

string Property::getPropName() const {
    return propName;
}

void Property::setPropName(const string& propName) {
    this->propName = propName;
}

int Property::getCompletionYear() const {
    return completionYear;
}

void Property::setCompletionYear(int completionYear) {
    this->completionYear = completionYear;
}

double Property::getMonthlyRent() const {
    return monthlyRent;
}

void Property::setMonthlyRent(double monthlyRent) {
    this->monthlyRent = monthlyRent;
}

string Property::getLocation() const {
    return location;
}

void Property::setLocation(const string& location) {
    this->location = location;
}

string Property::getPropertyType() const {
    return propertyType;
}

void Property::setPropertyType(const string& propertyType) {
    this->propertyType = propertyType;
}

int Property::getRooms() const {
    return rooms;
}

void Property::setRooms(int rooms) {
    this->rooms = rooms;
}

int Property::getParking() const {
    return parking;
}

void Property::setParking(int parking) {
    this->parking = parking;
}

int Property::getBathroom() const {
    return bathroom;
}

void Property::setBathroom(int bathroom) {
    this->bathroom = bathroom;
}

int Property::getSize() const {
    return size;
}

void Property::setSize(int size) {
    this->size = size;
}

string Property::getFurnished() const {
    return furnished;
}

void Property::setFurnished(const string& furnished) {
    this->furnished = furnished;
}

vector<string> Property::getFacilities() const {
    return facilities;
}

void Property::setFacilities(const vector<string>& facilities) {
    this->facilities = facilities;
}

vector<string> Property::getAdditionalFacilities() const {
    return additionalFacilities;
}

void Property::setAdditionalFacilities(const vector<string>& additionalFacilities) {
    this->additionalFacilities = additionalFacilities;
}
