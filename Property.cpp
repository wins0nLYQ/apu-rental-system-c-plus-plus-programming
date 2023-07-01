/**
 * FILENAME: Property.cpp
*/

#include "Property.h"
#include <iostream>

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
