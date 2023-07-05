/**
 * FILENAME: Property.cpp
*/

#include "Property.h"
#include <iostream>

Property::Property(vector<std::string> attributes) {
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
}

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

string Property::getCompletionYear() const {
    return completionYear;
}

void Property::setCompletionYear(string completionYear) {
    this->completionYear = completionYear;
}

string Property::getMonthlyRent() const {
    return monthlyRent;
}

void Property::setMonthlyRent(string monthlyRent) {
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

string Property::getRooms() const {
    return rooms;
}

void Property::setRooms(string rooms) {
    this->rooms = rooms;
}

string Property::getParking() const {
    return parking;
}

void Property::setParking(string parking) {
    this->parking = parking;
}

string Property::getBathroom() const {
    return bathroom;
}

void Property::setBathroom(string bathroom) {
    this->bathroom = bathroom;
}

string Property::getSize() const {
    return size;
}

void Property::setSize(string size) {
    this->size = size;
}

string Property::getFurnished() const {
    return furnished;
}

void Property::setFurnished(const string& furnished) {
    this->furnished = furnished;
}

string Property::getFacilities() const {
    return facilities;
}

void Property::setFacilities(const string& facilities) {
    this->facilities = facilities;
}

string Property::getAdditionalFacilities() const {
    return additionalFacilities;
}

void Property::setAdditionalFacilities(const string& additionalFacilities) {
    this->additionalFacilities = additionalFacilities;
}

string Property::getRegion() const {
    return region;
}

void Property::setRegion(const string& region) {
    this->region = region;
}
