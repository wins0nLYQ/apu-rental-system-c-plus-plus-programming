#ifndef RENTAL_H
#define RENTAL_H

// #include <string>
// #include "Property.h"

using namespace std;

enum Status { Pending, Approved, Rejected, Active, Inactive };

std::string getStatusInString(Status status) {
    switch (status) {
        case Pending:
            return "Pending";
        case Approved:
            return "Approved";
        case Rejected:
            return "Rejected";
        case Active:
            return "Moved In";
        case Inactive:
            return "Moved Out";
        default:
            return "-";
    }
}

class Rental {
    private:
        Property property;
        string tenantEmail;
        string requestDateTime;
        Status applicationStatus;
        string remarks;

    public:
    Rental() {}

    Rental(const Property &property, const string &tenant, const string &requestDateTime, const Status &applicationStatus, const string &remarks) 
    {
        // default constructor, sets all member variables to empty strings or 0's.
        this->property = property;
        this->tenantEmail = tenant;
        this->requestDateTime = requestDateTime;
        this->applicationStatus = applicationStatus;
        this->remarks = remarks;
    }

    Property getProperty() const {
        return this->property;
    }

    void setProperty(const Property &property) {
        this->property = property;
    }

    string getTenantEmail() const {
        return this->tenantEmail;
    }

    void setRentTenantEmail(string &tenant) {
        this->tenantEmail = tenant;
    }

    string getRequestDateTime() const {
        return requestDateTime;
    }

    void setRequestDateTime(const string& newRequestDateTime) {
        requestDateTime = newRequestDateTime;
    }

    Status getApplicationStatus() const {
        return applicationStatus;
    }

    void setApplicationStatus(const Status& newApplicationStatus) {
        applicationStatus = newApplicationStatus;
    }

    string getRemarks() const {
        return remarks;
    }

    void setRemarks(const string& newRemarks) {
        remarks = newRemarks;
    }

    // Equality comparison operator
    bool operator==(const Rental& other) const {
        return this->property == other.getProperty() &&
               this->tenantEmail == other.getTenantEmail();
    }

    // string getPaymentStatus() const {
    //     return paymentStatus;
    // }

    // void setPaymentStatus(const string& newPaymentStatus) {
    //     paymentStatus = newPaymentStatus;
    // }

    // string getMoveInDate() const {
    //     return moveInDate;
    // }
    
    // void setMoveInDate(const string& newMoveInDate) {
    //     moveInDate = newMoveInDate;
    // }

    // string getMoveOutDate() const {
    //     return moveOutDate;
    // }

    // void setMoveOutDate(const string& newMoveOutDate) {
    //     this->moveOutDate = newMoveOutDate;
    // }
};

#endif