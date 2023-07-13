#ifndef RENTAL_H
#define RENTAL_H

#include <string>

using namespace std;

class Rental {
    private:
        string adsID;
        string tenantEmail;
        string requestDateTime;
        string applicationStatus;
        string paymentStatus;
        string remarks;

    public:
        string getAdsID() const {
        return adsID;
    }

    void setAdsID(const string& newAdsID) {
        adsID = newAdsID;
    }

    string getTenantEmail() const {
        return tenantEmail;
    }

    void setTenantEmail(const string& newTenantEmail) {
        tenantEmail = newTenantEmail;
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