#ifndef TENANT_H
#define TENANT_H

/**
 * FILENAME: Tenant.h
 */

#include "string"
#include "User.h"
#include "DoublyCircularLinkedList.h"
#include "Property.h"
#include "Rental.h"
#include "DynamicArray.h"
#include "DataValidation.h"
#include "DataConversion.h"
#include <ctime>

using namespace std;

class Tenant : public User
{
private:
    string lastLoginDate;
    DoublyCircularLinkedList<Rental> *rentalHistory;

public:
    Tenant() {}

    Tenant(const string &_name, const string &_email, const string &_phoneNo,
           const string &_identificationNo, const string &_gender, const string &_password,
           const string &_dateOfBirth, const string &_lastLoginDate)
        : User(_name, _email, _phoneNo, _identificationNo, _gender, _password, _dateOfBirth, "Tenant"),
          lastLoginDate(_lastLoginDate) {}

    string getLastLoginDate() const
    {
        return lastLoginDate;
    }

    void setLastLoginDate(const string &lastLoginDate)
    {
        this->lastLoginDate = lastLoginDate;
    }

    bool registration(DynamicArray<Tenant> &tenantList, DynamicArray<string> &existingEmail)
    {
        // Implementation of tenant registration logic
        DataValidation dv;
        string name, email, phoneNo, identificationNo, gender, password, dateOfBirth, lastLoginDate;
        cout << "[ADD NEW USER ACCOUNT]" << endl;
        cout << "Enter '-1' to back to previous page." << endl;
        cout << endl;

        cout << "Name: ";
        getline(cin >> ws, name);
        cout << endl;

        if (name == "-1")
        {
            return false;
        }

        cout << "Email: ";
        getline(cin >> ws, email);
        cout << endl;

        if (email == "-1")
        {
            return false;
        }

        while (dv.isEmailValid(email) == false || isEmailExists(existingEmail, email) == true)
        {
            if (dv.isEmailValid(email) == false)
            {
                cout << "Invalid email! Please try again: ";
                getline(cin >> ws, email);
                cout << endl;
                if (email == "-1")
                {
                    return false;
                }
            }
            else if (isEmailExists(existingEmail, email) == true)
            {
                cout << "Email exist! Please try another one: ";
                getline(cin >> ws, email);
                cout << endl;
                if (email == "-1")
                {
                    return false;
                }
            }
        }

        cout << "Phone Number: ";
        getline(cin >> ws, phoneNo);
        cout << endl;

        if (phoneNo == "-1")
        {
            return false;
        }

        while (dv.isValidPhoneNumber(phoneNo) == false)
        {
            cout << "Phone number should be 10-11 digits! Please try again: ";
            getline(cin >> ws, phoneNo);
            cout << endl;
            if (phoneNo == "-1")
            {
                return false;
            }
        }

        cout << "Identification No: ";
        getline(cin >> ws, identificationNo);
        cout << endl;

        if (identificationNo == "-1")
        {
            return false;
        }

        while (dv.isValidID(identificationNo) == false)
        {
            cout << "ID number should be 6-15 characters! Please try again: ";
            getline(cin >> ws, identificationNo);
            cout << endl;
            if (identificationNo == "-1")
            {
                return false;
            }
        }

        cout << "Gender (1 - MALE; 2 - FEMALE): ";
        getline(cin >> ws, gender);
        cout << endl;

        if (gender == "-1")
        {
            return false;
        }

        while (gender != "1" && gender != "2")
        {
            cout << "Invalid input! Please try again (1 - MALE; 2 - FEMALE): ";
            getline(cin >> ws, gender);
            cout << endl;
            if (gender == "-1")
            {
                return false;
            }
        }
        if (gender == "1")
        {
            gender = "Male";
        }
        else
        {
            gender = "Female";
        }

        cout << "Password: " << endl;
        cout << "- Minimum length of 8 characters." << endl;
        cout << "- At least one UPPERCASE." << endl;
        cout << "- At least one lowercase." << endl;
        cout << "- At least one digit." << endl;
        cout << "- At least one special character." << endl;
        cout << ">>> ";
        getline(cin >> ws, password);
        cout << endl;

        if (password == "-1")
        {
            return false;
        }

        while (dv.isValidPassword(password) == false)
        {
            cout << "Invalid password! Please try again: ";
            getline(cin >> ws, password);
            cout << endl;
            if (password == "-1")
            {
                return false;
            }
        }

        cout << "Date of Birth (YYYY-MM-DD): ";
        getline(cin >> ws, dateOfBirth);
        cout << endl;

        if (dateOfBirth == "-1")
        {
            return false;
        }

        while (dv.isValidDateOfBirth(dateOfBirth) == false)
        {
            cout << "Invalid date of birth! Please try again (YYYY-MM-DD): ";
            getline(cin >> ws, dateOfBirth);
            cout << endl;
            if (dateOfBirth == "-1")
            {
                return false;
            }
        }

        DataConversion dc;
        string loginDate = dc.getTodayDate();
        Tenant newTenant(name, email, phoneNo, identificationNo, gender, password, dateOfBirth, loginDate);
        tenantList.insertAtEnd(newTenant);

        cout << "User account created successfully!" << endl;

        cout << "Name: " << newTenant.getName() << endl;
        cout << "Email: " << newTenant.getEmail() << endl;
        cout << "Phone Number: " << newTenant.getPhoneNo() << endl;
        cout << "Identification No: " << newTenant.getIdentificationNo() << endl;
        cout << "Gender: " << newTenant.getGender() << endl;
        cout << "Date of Birth: " << newTenant.getDateOfBirth() << endl;
        cout << "---------------------------\n";

        cout << "You may proceed the login page and login with your account." << endl;
        cout << "Input any key to back >> ";
        string userInput;
        getline(cin >> ws, userInput);
        cout << endl;

        return true;
    }

    bool isEmailExists(DynamicArray<string> &existingEmail, const string &email)
    {
        // Admin admin;
        DataConversion dc;
        if (dc.toLowercase(email) == "admin@gmail.com")
        {
            return true;
        }

        int userNum = existingEmail.getSize();
        for (int i = 0; i < userNum; ++i)
        {
            if (dc.toLowercase(existingEmail.get(i)) == dc.toLowercase(email))
            {
                return true;
            }
        }
        return false;
    }

    void addRentalRequest(Property &propertySelected, DoublyCircularLinkedList<Rental> &rentalHistory)
    {
        for (int count = 0; count < rentalHistory.getSize(); count++)
        {
            if (rentalHistory.get(count).getProperty() == propertySelected)
            {
                cout << endl
                     << "You have already sent a rental request for this property." << endl
                     << endl;
                return;
            }
        }

        DataConversion dc;
        Rental request(propertySelected, this->getEmail(), dc.getTodayDate(), Status::Pending, "");

        rentalHistory.insertAtEnd(request);

        cout << endl
             << "[RENT REQUEST HAS SENT]" << endl;
    }

    void extractSpecificStatusRequest(Status stat, Status stat2, DoublyCircularLinkedList<Rental> &tenantRentalHistory)
    {
        int total = 0;
        Rental rental;

        for (int count = 0; count < tenantRentalHistory.getSize(); count++)
        {
            if (tenantRentalHistory.get(count).getApplicationStatus() == stat ||
                tenantRentalHistory.get(count).getApplicationStatus() == stat2)
            {
                total++;
            }
        }

        Rental eachReq = tenantRentalHistory.getFirst();

        while (true)
        {
            if (eachReq.getApplicationStatus() == stat || eachReq.getApplicationStatus() == stat2)
            {
                rental = eachReq;
                break;
            }

            eachReq = tenantRentalHistory.nextItem();
        }

        int propIndex = 1;
        string statStr = getStatusInString(stat);

        while (true)
        {
            cout << endl
                 << "[RENTAL REQUEST: " << statStr << "]" << endl;

            cout << "NO: " << propIndex << " OUT OF " << total << endl;

            displaySingleProperty(rental.getProperty());

            cout << "Request Date: " << rental.getRequestDateTime() << endl;
            cout << "Application Status: " << getStatusInString(rental.getApplicationStatus()) << endl;
            cout << "Remarks: " << rental.getRemarks() << endl;

            cout << "---------------------------------------" << endl;

            // switch (stat) {
            //     case Approved:
            //         cout << "Options: (N)ext, (P)revious, (D)elete, (Q)uit, (T)ransaction" << endl;
            //         cout << ">> ";
            //         break;
            //     default:
            //         cout << "Options: (N)ext, (P)revious, (D)elete, (Q)uit" << endl;
            //         cout << ">> ";
            //         break;
            // }

            cout << "Options: (N)ext, (P)revious, (Q)uit" << endl;
            cout << ">> ";

            string choice;
            getline(cin >> ws, choice);

            if (choice == "N" || choice == "n")
            {
                if (propIndex < total)
                {
                    rental = tenantRentalHistory.nextItem();

                    while (true)
                    {
                        if (rental.getApplicationStatus() == stat)
                        {
                            propIndex++;
                            break;
                        }

                        rental = tenantRentalHistory.nextItem();
                    }
                }
                else
                {
                    cout << "No more items. Reached the last rental history." << endl
                         << endl;
                }
            }
            else if (choice == "P" || choice == "p")
            {
                if (propIndex > 1)
                {
                    rental = tenantRentalHistory.prevItem();

                    while (true)
                    {
                        if (rental.getApplicationStatus() == stat)
                        {
                            propIndex--;
                            break;
                        }

                        rental = tenantRentalHistory.prevItem();
                    }
                }
                else
                {
                    cout << endl
                         << "This is the first rental history." << endl
                         << endl;
                }
            }
            // else if (choice == "D" || choice == "d") {
            //     while (true) {
            //         cout << "Are you sure to remove the current rental history from the list? (Y/N)" << endl;
            //         cout << ">> ";
            //         string option;
            //         getline(cin >> ws, option);

            //         if (option == "Y" || option == "y") {
            //             rental = tenantRentalHistory.removeCurrent();
            //             cout << endl << "Rental history has been removed." << endl << endl;
            //             break;
            //         }
            //         else if (option == "N" || option == "n") {
            //             cout << endl << "Rental request remove unsuccessful" << endl << endl;
            //             break;
            //         }
            //         else {
            //             cout << endl << "Invalid Option. Please Try Again..." << endl << endl;
            //         }
            //     }
            // }
            // else if (choice == "T" || choice == "t") {
            //     if (rental.getApplicationStatus() == 1) {
            //         cout << endl << "Going to payment page..." << endl << endl;

            //         if(rentalPayment(rental, rentalHistory.getIndex())) {
            //             cout << "Payment successful!" << endl << endl;
            //             break;
            //         }
            //         else {
            //             cout << "Payment Unsuccess!" << endl << endl;
            //         }
            //     }
            //     else {
            //         cout << "This application is not approved..." << endl;
            //     }
            // }
            else if (choice == "Q" || choice == "q")
            {
                break;
            }
            else
            {
                cout << endl
                     << "Invalid input! Please try again..." << endl;
            }
        }
    }

    bool rentalPayment(Property &property)
    {
        // Implementation of rental payment logic
        bool paidSuccessfully = false;

        while (true)
        {
            cout << endl;
            cout << endl;
            cout << "[PAYMENT PAGE]" << endl;
            cout << "---------------------------------------" << endl;
            cout << "Property Information" << endl;
            cout << "---------------------------------------" << endl;
            displaySingleProperty(property);

            cout << "Enter 'P' to proceed payment (0 to Back): " << endl;
            cout << ">> ";

            string userInput;
            getline(cin >> ws, userInput);

            if (userInput == "P" || userInput == "p")
            {
                paidSuccessfully = paymentInterface();
                break;
            }
            else if (userInput == "0")
            {
                cout << endl
                     << "Payment Cancelled... Returning Back!" << endl
                     << endl;
                break;
            }
            else
            {
                cout << endl
                     << "Invalid Option... Please try again!" << endl
                     << endl;
            }
        }

        return paidSuccessfully;
    }

    bool paymentInterface()
    {
        // Implementation of payment interface logic
        DataConversion dc;

        bool paymentStatus = false;

        while (true)
        {
            cout << endl
                 << "Enter Card No. [16-Digits] (-1 to Cancel): ";
            string cardNo;
            getline(cin >> ws, cardNo);

            if (cardNo == "-1")
            {
                break;
            }
            else if (cardNo.size() == 16 && dc.isInteger(cardNo))
            {
                cout << endl
                     << "Enter Card Holder Name (-1 to Cancel): ";
                string holderName;
                getline(cin >> ws, holderName);

                if (holderName == "-1")
                {
                    break;
                }
                else
                {
                    while (true)
                    {
                        cout << endl
                             << "Enter CVV [3-Digits] (-1 to Cancel): ";
                        string cvv;
                        getline(cin >> ws, cvv);

                        if (cvv == "-1")
                        {
                            break;
                        }
                        else if (cvv.size() == 3 && dc.isInteger(cvv))
                        {
                            while (true)
                            {
                                cout << endl
                                     << "Card Expiry Date: " << endl;
                                cout << ">> Month [1-12] (-1 to Cancel): ";
                                string expiryMonth;
                                getline(cin >> ws, expiryMonth);

                                if (expiryMonth == "-1")
                                {
                                    break;
                                }
                                else if (dc.isInteger(expiryMonth))
                                {
                                    int cardMonth = stoi(expiryMonth);

                                    if (cardMonth > 0 && cardMonth < 13)
                                    {
                                        while (true)
                                        {
                                            cout << endl
                                                 << ">> Year [2023 - 2028] (-1 to Cancel): ";
                                            string expiryYear;
                                            getline(cin >> ws, expiryYear);

                                            if (expiryYear == "-1")
                                            {
                                                cout << endl
                                                     << "Payment Cancelled... Returning Back!" << endl;
                                                paymentStatus = true;
                                                break;
                                            }
                                            else if (dc.isInteger(expiryYear))
                                            {
                                                int cardYear = stoi(expiryYear);

                                                if (expiryYear.size() == 4)
                                                {
                                                    tm date = {0};

                                                    date.tm_year = cardYear - 1900;
                                                    date.tm_mon = cardMonth - 1;
                                                    date.tm_mday = 1;

                                                    time_t cardDate = mktime(&date);

                                                    if (dc.comapreDate(cardDate, dc.todayDateInTimeT()) == 1)
                                                    {
                                                        paymentStatus = true;
                                                    }
                                                    else
                                                    {
                                                        cout << endl
                                                             << "The card is expired... Please user another card" << endl;
                                                    }

                                                    break;
                                                }
                                                else
                                                {
                                                    cout << endl
                                                         << "Invalid Expiry Year... Please Try Again!" << endl;
                                                }
                                            }
                                            else
                                            {
                                                cout << endl
                                                     << "Invalid Year... Please Try Again!" << endl;
                                            }
                                        }

                                        break;
                                    }
                                    else
                                    {
                                        cout << endl
                                             << "Invalid Expiry Date... Please Try Again!" << endl;
                                    }
                                }
                                else
                                {
                                    cout << endl
                                         << "Invalid Expiry Date... Please Try Again!" << endl;
                                }
                            }

                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Invalid CVV... Please Try Again!" << endl;
                        }
                    }

                    break;
                }

                break;
            }
            else
            {
                cout << endl
                     << "Invalid Card...Please Try Again!" << endl;
            }
        }

        return paymentStatus;
    }

    string rentalRequestSummary(DoublyCircularLinkedList<Rental> &tenantRequestRental)
    {
        Status stat;
        int pending = 0, approved = 0, rejected = 0;
        // Implementation of rental request summary logic
        for (int count = 0; count < tenantRequestRental.getSize(); count++)
        {
            stat = tenantRequestRental.get(count).getApplicationStatus();

            switch (stat)
            {
            case Pending:
                pending++;
                break;
            case Approved:
                approved++;
                break;
            case Rejected:
                rejected++;
                break;
            case Active:
                approved++;
                break;
            case Refunded:
                rejected++;
                break;
            default:
                break;
            }
        }

        cout << "[Summary of Rental History]" << endl;
        cout << " 1. Pending: " << pending << endl;
        cout << " 2. Approved: " << approved << endl;
        cout << " 3. Rejected: " << rejected << endl;
        cout << "------------------------------" << endl
             << endl;
        cout << "Please select an option (-1 to Back): " << endl;
        cout << ">> ";

        string userInput;
        getline(cin >> ws, userInput);

        return userInput;
    }

    void displaySingleProperty(const Property &property)
    {
        cout << "Ads ID: " << property.getAdsID() << endl;
        cout << "Property Name: " << property.getPropName() << endl;
        cout << "Completion Year: " << property.getCompletionYear() << endl;
        cout << "Monthly Rent: " << property.getMonthlyRent() << endl;
        cout << "Location: " << property.getLocation() << endl;
        cout << "Property Type: " << property.getPropertyType() << endl;
        cout << "Rooms: " << property.getRooms() << endl;
        cout << "Parking: " << property.getParking() << endl;
        cout << "Bathroom: " << property.getBathroom() << endl;
        cout << "Size: " << property.getSize() << endl;
        cout << "Furnished: " << property.getFurnished() << endl;
        cout << "Facilities: " << property.getFacilities() << endl;
        cout << "Additional Facilities: " << property.getAdditionalFacilities() << endl;
        cout << "Region: " << property.getRegion() << endl;
        cout << "---------------------------------------\n";
    }

    Tenant login(const string &email, DynamicArray<Tenant> &tenantList)
    {
        Tenant loginTenant;
        DataConversion dc;
        for (int i = 0; i < tenantList.getSize(); ++i)
        {
            Tenant tenant;
            tenant = tenantList.get(i);
            if (dc.toLowercase(tenant.getEmail()) == dc.toLowercase(email))
            {
                loginTenant.setName(tenant.getName());
                loginTenant.setEmail(tenant.getEmail());
                loginTenant.setPhoneNo(tenant.getPhoneNo());
                loginTenant.setIdentificationNo(tenant.getIdentificationNo());
                loginTenant.setGender(tenant.getGender());
                loginTenant.setDateOfBirth(tenant.getDateOfBirth());
                loginTenant.setLastLoginDate(tenant.getLastLoginDate());
                loginTenant.setPassword(tenant.getPassword());
                loginTenant.setLastLoginDate(dc.getTodayDate());
                loginTenant.setRole(tenant.getRole());

                tenantList.set(i, loginTenant);
            }
        }

        return loginTenant;
    }

    void resetPassword(DynamicArray<Tenant> &tenantList)
    {
        DataValidation dv;
        string currentPassword = this->getPassword();
        string newPassword;
        string confirmPassword;

        // Loop until the user enters correct current password or "-1" to exit
        string enteredPassword;
        while (true)
        {
            cout << "Enter current password (Enter -1 to exit): ";
            getline(cin >> ws, enteredPassword);
            cout << endl;

            if (enteredPassword == "-1")
            {
                return;
            }

            if (enteredPassword == currentPassword)
            {
                break;
            }
            else
            {
                cout << "Incorrect current password. Please try again." << endl
                     << endl;
            }
        }

        // Prompt user for new password and confirm
        while (true)
        {
            cout << "[ENTER NEW PASSWORD] (Enter -1 to exit)" << endl;
            cout << "- Minimum length of 8 characters." << endl;
            cout << "- At least one UPPERCASE." << endl;
            cout << "- At least one lowercase." << endl;
            cout << "- At least one digit." << endl;
            cout << "- At least one special character." << endl;
            cout << ">>> ";
            getline(cin >> ws, newPassword);
            cout << endl;

            if (newPassword == "-1")
            {
                return;
            }

            if (dv.isValidPassword(newPassword))
            {
                cout << "Re-enter new password to confirm: ";
                getline(cin >> ws, confirmPassword);
                cout << endl;

                if (newPassword != confirmPassword)
                {
                    cout << "Passwords do not match. Please try again." << endl
                         << endl;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << "Invalid password! Please try again." << endl
                     << endl;
            }
        }

        // Update the password
        for (int count = 0; count < tenantList.getSize(); count++)
        {
            Tenant &tempTenant = tenantList.get(count);
            if (tempTenant.getEmail() == this->getEmail())
            {
                tempTenant.setPassword(newPassword);
                this->setPassword(newPassword);
                tenantList.set(count, tempTenant);
                break;
            }
        }
        cout << "Password successfully changed." << endl;
    }
};

#endif