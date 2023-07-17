#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include "Property.h"
#include "Tenant.h"

using namespace std;

class Rental {
    private:
        Property property;
        Tenant tenant;
        string requestDateTime;
        string applicationStatus;
        string paymentStatus;
        string remarks;

    public:
    Rental() {
        // default constructor, sets all member variables to empty strings or 0's.
    }

    Property getProperty() const {
        return this->property;
    }

    void setProperty(const Property &property) {
        this->property = property;
    }

    Tenant getTenant() const {
        return this->tenant;
    }

    void setRentTenant(const Tenant &tenant) {
        this->tenant = tenant;
    }

    string getRequestDateTime() const {
        return requestDateTime;
    }

    void setRequestDateTime(const string& newRequestDateTime) {
        requestDateTime = newRequestDateTime;
    }

    string getApplicationStatus() const {
        return applicationStatus;
    }

    void setApplicationStatus(const string& newApplicationStatus) {
        applicationStatus = newApplicationStatus;
    }

    string getPaymentStatus() const {
        return paymentStatus;
    }

    void setPaymentStatus(const string& newPaymentStatus) {
        paymentStatus = newPaymentStatus;
    }

    string getRemarks() const {
        return remarks;
    }

    void setRemarks(const string& newRemarks) {
        remarks = newRemarks;
    }
    
};

#endif