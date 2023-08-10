#ifndef MANAGER_H
#define MANAGER_H

/**
 * FILENAME: Manager.h
 */

#include "string"
#include <iostream>
#include <utility>
#include "User.h"
#include "DynamicArray.h"
#include "DataConversion.h"
#include "Tenant.h"
#include "FilterProperty.h"
#include <unordered_map> //is a container that stores elements formed by a combination of key value and a mapped value.
                         // It uses a hash table internally for its implementation, and searching for elements in it is very efficient.
#include <queue>         // is a container adapter that provides constant time lookup of the largest (by default) element.

using namespace std;

class Manager : public User
{
private:
    string status;

public:
    Manager() {}

    Manager(const std::string &_name, const std::string &_email, const std::string &_phoneNo,
            const std::string &_identificationNo, const std::string &_gender,
            const std::string &_dateOfBirth, const std::string &_status)
        : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth, "Manager"),
          status(_status)
    {
    }

    string getStatus() const
    {
        return status;
    }

    void setStatus(const string &status)
    {
        this->status = status;
    }

    Manager login(const std::string &email, DynamicArray<Manager> &managerList)
    {
        Manager loginManager;
        DataConversion dc;
        for (int i = 0; i < managerList.getSize(); ++i)
        {
            Manager manager;
            manager = managerList.get(i);
            if (dc.toLowercase(manager.getEmail()) == dc.toLowercase(email))
            {
                loginManager.setName(manager.getName());
                loginManager.setEmail(manager.getEmail());
                loginManager.setPhoneNo(manager.getPhoneNo());
                loginManager.setIdentificationNo(manager.getIdentificationNo());
                loginManager.setGender(manager.getGender());
                loginManager.setDateOfBirth(manager.getDateOfBirth());
                loginManager.setPassword(manager.getPassword());
                loginManager.setStatus(manager.getStatus());
                loginManager.setRole(manager.getRole());
            }
        }
        return loginManager;
    }

    void printTopFavouriteProperties(DynamicArray<Property> allFavouriteList)
    {
        // Create an unordered_map to store property names and their corresponding properties and counts
        std::unordered_map<std::string, std::pair<Property, int>> propertyFrequency;

        // Iterate through the list of favorite properties
        for (int i = 0; i < allFavouriteList.getSize(); i++)
        {
            // Get the current property
            Property property = allFavouriteList.get(i);
            // Get the name of the property
            std::string propertyName = property.getPropName();
            // Increment the count for this property in the map and store the property
            propertyFrequency[propertyName].first = property;
            propertyFrequency[propertyName].second++;
        }

        // Define a comparison function for the priority queue
        // It compares pairs of property name and count
        auto compare = [](const std::pair<std::string, std::pair<Property, int>> &a, const std::pair<std::string, std::pair<Property, int>> &b)
        {
            // Properties with higher counts are considered smaller
            // If counts are equal, properties with lexicographically smaller names are considered smaller
            return a.second.second < b.second.second || (a.second.second == b.second.second && a.first < b.first);
        };

        // Create a priority queue to store the top 10 properties
        // The queue contains pairs of property name and a pair of Property and count
        // The property with the highest count (and smallest name if counts are equal) is always at the top
        std::priority_queue<std::pair<std::string, std::pair<Property, int>>, std::vector<std::pair<std::string, std::pair<Property, int>>>, decltype(compare)> topFavourites(compare);

        while (true)
        {
            // Iterate through the map of property counts
            for (const auto &pair : propertyFrequency)
            {
                // Add each property to the priority queue
                topFavourites.push(pair);
                // If the queue has more than 10 properties, remove the one with the lowest count (and largest name if counts are equal)
                if (topFavourites.size() > 10)
                {
                    topFavourites.pop();
                }
            }
            cout << "[TOP 10 FAVOURITE PROPERTY PAGE]" << endl;
            for (int rank = 10; !topFavourites.empty(); --rank)
            {
                // Get the property at the top of the queue
                auto top = topFavourites.top();
                // Print the property's rank, name, and count
                std::cout << "\t"
                          << "\t"
                          << "[TOP " << 11 - rank << "]\n";
                std::cout << "-----------------------------------------\n";
                std::cout << "Property Name : " << top.first << "\n";
                std::cout << "Favorited Amount : " << top.second.second << "\n";
                std::cout << "-----------------------------------------\n";
                // Remove the property from the queue
                topFavourites.pop();
            }
            std::cout << "Options: (G)enerate Report, (Q)uit\n>>";
            cout << "";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "G" || userInput == "g")
            {
                FilterProperty property;
                cout << "[TOP 10 FAVOURITE PROPERTY REPORT PAGE]" << endl;
                for (const auto &pair : propertyFrequency)
                {
                    std::cout << "---------------------------\n";
                    property.displaySingleProperty(pair.second.first);
                }
                cout << "Enter any key to continue to go back: ";
                string userInput;
                getline(cin >> ws, userInput);
                cout << endl;
            }
            else if (userInput == "Q" || userInput == "q")
            {

                break;
            }
            else
            {
                cout << "Invalid input. Please try again." << endl;
            }
        }
        cout << "Testing3" << endl;
    }

    // Call DoublyCircularLinkedList<Rental> rentalHistory from Asia Pacific Home and print all;
    void printAllRentHistory(DoublyCircularLinkedList<Rental> &allRentHistory)
    {
        while (true)
        {
            cout << "[ALL RENTAL HISTORY PAGE]" << endl;
            bool hasPending = false; // Flag to check if there are any pending requests
            for (int count = 0; count < allRentHistory.getSize(); count++)
            {
                Rental rental = allRentHistory.get(count);
                if (rental.getApplicationStatus() == Status::Pending)
                {
                    hasPending = true; // Found a pending request
                    cout << "-----------------------------------------\n";
                    cout << "NO: " << count + 1 << "\n";
                    cout << "Property ID : " << rental.getProperty().getAdsID() << "\n";
                    cout << "Property Name : " << rental.getProperty().getPropName() << "\n";
                    cout << "Tenant Email : " << rental.getTenantEmail() << "\n";
                    cout << "Request Date : " << rental.getRequestDateTime() << "\n";
                    cout << "Application Status : " << getStatusInString(rental.getApplicationStatus()) << "\n";
                    cout << "-----------------------------------------\n";
                }
            }
            if (!hasPending) // If no pending requests were found
            {
                cout << "No pending requests.\n";
                cout << endl;
                break; // Exit the loop and return from the function
            }
            cout << "Options: (A)pprove, (R)eject, (Q)uit\n>>";
            string userInput;
            getline(cin >> ws, userInput);

            if (userInput == "A" || userInput == "a")
            {
                cout << "Enter the number of the rental to approve: ";
                int rentalNumber;
                cin >> rentalNumber;
                cin.ignore(); // Clear newline character from input buffer

                if (rentalNumber > 0 && rentalNumber <= allRentHistory.getSize())
                {
                    Rental &rentalToApprove = allRentHistory.get(rentalNumber - 1);
                    rentalToApprove.setApplicationStatus(Status::Approved); // Set enum value
                    cout << "Rental " << rentalNumber << " has been approved.\n";
                    cout << endl;
                }
                else
                {
                    cout << "Invalid rental number. Please try again.\n";
                }
            }
            else if (userInput == "R" || userInput == "r")
            {
                cout << "Enter the number of the rental to reject: ";
                int rentalNumber;
                cin >> rentalNumber;
                cin.ignore(); // Clear newline character from input buffer

                if (rentalNumber > 0 && rentalNumber <= allRentHistory.getSize())
                {
                    Rental &rentalToReject = allRentHistory.get(rentalNumber - 1);
                    rentalToReject.setApplicationStatus(Status::Rejected); // Set enum value
                    cout << "Rental " << rentalNumber << " has been rejected.\n";
                    cout << endl;
                }
                else
                {
                    cout << "Invalid rental number. Please try again.\n";
                }
            }
            else if (userInput == "Q" || userInput == "q")
            {
                break; // Exit the loop and return from the function
            }
            else
            {
                cout << "Invalid input. Please try again.\n";
            }
        }
    }

    void printAllPayment(DoublyCircularLinkedList<Rental> &allRentHistory)
    {
        while (true)
        {
            bool paymentFound = false;

            cout << "[ALL PAYMENT HISTORY PAGE]" << endl;
            for (int count = 0; count < allRentHistory.getSize(); count++)
            {
                Rental rental = allRentHistory.get(count);
                if (rental.getApplicationStatus() == Status::Approved || rental.getApplicationStatus() == Status::Pending)
                {
                    paymentFound = true;
                    cout << "-----------------------------------------\n";
                    cout << "NO: " << count + 1 << "\n";
                    cout << "Property ID : " << rental.getProperty().getAdsID() << "\n";
                    cout << "Property Name : " << rental.getProperty().getPropName() << "\n";
                    cout << "Tenant Email : " << rental.getTenantEmail() << "\n";
                    cout << "Request/Payment Date : " << rental.getRequestDateTime() << "\n";
                    cout << "Application Status : " << getStatusInString(rental.getApplicationStatus()) << "\n";
                    DataConversion dataConversion;
                    long long paymentAmount = dataConversion.extractDigit(rental.getProperty().getMonthlyRent());
                    cout << "Payment Amount : RM " << paymentAmount * 3.5 << "\n"; // Calculated payment amount
                    cout << "-----------------------------------------\n";
                }
            }
            if (!paymentFound)
            {
                cout << "No payment found.\n\n";
                break;
            }
    
            cout << "Options: (U)pdate, (Q)uit\n>> ";
            string userInput;
            getline(cin >> ws, userInput);

            if (userInput == "U" || userInput == "u")
            {
                string rentalNumber_S;
                DataConversion dc;
                int rentalNumber;
                while (true)
                {
                    cout << "Enter the number of the rental to update: ";
                    getline(cin >> ws, rentalNumber_S);

                    if (dc.isInteger(rentalNumber_S))
                    {
                        rentalNumber = stoi(rentalNumber_S);
                        break;
                    }
                    else
                    {
                        cout << "Invalid input. Please try again.\n";
                    }
                }

                if (rentalNumber > 0 && rentalNumber <= allRentHistory.getSize())
                {
                    Rental &rentalToUpdate = allRentHistory.get(rentalNumber - 1);
                    if (rentalToUpdate.getApplicationStatus() == Status::Active || rentalToUpdate.getApplicationStatus() == Status::Refunded)
                    {
                        cout << "No action required for rental " << rentalNumber << ".\n\n";
                    }
                    else if (rentalToUpdate.getApplicationStatus() == Status::Approved)
                    {
                        cout << "Do you want to verify? (y/n): ";
                        string verifyChoice;
                        getline(cin >> ws, verifyChoice);
                        if (verifyChoice == "y" || verifyChoice == "Y")
                        {
                            rentalToUpdate.setApplicationStatus(Status::Active); // Set enum value to Verified
                            cout << "Rental " << rentalNumber << " has been verified.\n\n";
                        }
                    }
                    else if (rentalToUpdate.getApplicationStatus() == Status::Rejected)
                    {
                        cout << "Do you want to refund? (y/n): ";
                        string refundChoice;
                        getline(cin >> ws, refundChoice);
                        // cin.ignore();
                        if (refundChoice == "y" || refundChoice == "Y")
                        {
                            rentalToUpdate.setApplicationStatus(Status::Refunded); // Set enum value to Refunded
                            cout << "Rental " << rentalNumber << " has been refunded.\n\n";
                        }
                    }
                }
                else
                {
                    cout << "Invalid rental number. Please try again.\n";
                }
            }
            else if (userInput == "Q" || userInput == "q")
            {
                break; // Exit the loop and return from the function
            }
            else
            {
                cout << "Invalid input. Please try again.\n";
            }
        }
    }

    void resetPassword(DynamicArray<Manager> &managerList)
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

        cout << "HELLO" << endl;
        // Update the password
        for (int count = 0; count < managerList.getSize(); count++)
        {
            Manager &tempManager = managerList.get(count);
            if (tempManager.getEmail() == this->getEmail())
            {
                tempManager.setPassword(newPassword);
                this->setPassword(newPassword);
                managerList.set(count, tempManager);
                break;
            }
        }
        cout << "Password successfully changed." << endl;
    }
};

#endif