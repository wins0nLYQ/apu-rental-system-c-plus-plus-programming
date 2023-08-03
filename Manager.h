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
// #include <vector>
// #include "DataConversion.h"
#include "Tenant.h"
#include "FilterProperty.h"
#include <unordered_map> //is a container that stores elements formed by a combination of key value and a mapped value. 
                        //It uses a hash table internally for its implementation, and searching for elements in it is very efficient.
#include <queue> // is a container adapter that provides constant time lookup of the largest (by default) element.


using namespace std;

class Manager : public User {
private:
    string status;

public:
    Manager(){}

    Manager(const std::string& _name, const std::string& _email, const std::string& _phoneNo,
                const std::string& _identificationNo, const std::string& _gender,
                const std::string& _dateOfBirth, const std::string& _status)
            : User(_name, _email, _phoneNo, _identificationNo, _gender, "abc@123", _dateOfBirth, "Manager"),
            status(_status) {
    }

    string getStatus() const {
        return status;
    }

    void setStatus(const string& status) {
        this->status = status;
    }

    void displayRegisteredTenant() {
        // Implementation of displaying registered tenants logic
    }

    void searchTenant() {
        // Implementation of tenant search logic
    }

    void displayTenantStatus() {
        // Implementation of displaying tenant status logic
    }

    void deleteTenant() {
        // Implementation of tenant deletion logic
    }

    void displayFavoriteProperty() {
        // Implementation of displaying favorite properties logic
    }

    void generate_TopFavProp_Report() {
        // Implementation of generating top favorite properties report logic
    }

    void displayRentingRequest() {
        // Implementation of displaying renting requests logic
    }

    void acceptTenancy() {
        // Implementation of accepting tenancy logic
    }

    void rejectTenancy() {
        // Implementation of rejecting tenancy logic
    }

    void displayPaymentStatus() {
        // Implementation of displaying payment status logic
    }

    Manager login(const std::string& email, DynamicArray<Manager>& managerList) {
        Manager loginManager; DataConversion dc;
        for(int i = 0; i < managerList.getSize(); ++i) {
            Manager manager;
            manager = managerList.get(i);
            if(dc.toLowercase(manager.getEmail()) == dc.toLowercase(email)) {
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
        } return loginManager;
    }

    void getAllFavouriteList(DynamicArray<Tenant> tenantList, DynamicArray<Property> &allFavouriteProperty) {
            for (int count = 0; count < tenantList.getSize(); count++) {
                Tenant tenant = tenantList.get(count);
                for (int count2 = 0; count2 < tenant.getFavoriteProperty().getSize(); count2++) {
                    allFavouriteProperty.insertAtEnd(tenant.getFavoriteProperty().get(count2));   
                }
            } 
    }



    void printTopFavouriteProperties(DynamicArray<Property> allFavouriteList) {
            // Create an unordered_map to store property names and their corresponding properties and counts
            std::unordered_map<std::string, std::pair<Property, int>> propertyFrequency;

            // Iterate through the list of favorite properties
            for(int i = 0; i < allFavouriteList.getSize(); i++) {
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
            auto compare = [](const std::pair<std::string, std::pair<Property, int>>& a, const std::pair<std::string, std::pair<Property, int>>& b) {
                // Properties with higher counts are considered smaller
                // If counts are equal, properties with lexicographically smaller names are considered smaller
                return a.second.second < b.second.second || (a.second.second == b.second.second && a.first < b.first);
            };

            // Create a priority queue to store the top 10 properties
            // The queue contains pairs of property name and a pair of Property and count
            // The property with the highest count (and smallest name if counts are equal) is always at the top
            std::priority_queue<std::pair<std::string, std::pair<Property, int>>, std::vector<std::pair<std::string, std::pair<Property, int>>>, decltype(compare)> topFavourites(compare);

        while (true) {
            // Iterate through the map of property counts
            for (const auto& pair : propertyFrequency) {
                // Add each property to the priority queue
                topFavourites.push(pair);
                // If the queue has more than 10 properties, remove the one with the lowest count (and largest name if counts are equal)
                if (topFavourites.size() > 10) {
                    topFavourites.pop();
                }
            }
            cout << "[TOP 10 FAVOURITE PROPERTY PAGE]" << endl;
            for (int rank = 10; !topFavourites.empty(); --rank) {
                // Get the property at the top of the queue
                auto top = topFavourites.top();
                // Print the property's rank, name, and count
                std::cout << "\t" << "\t" << "[TOP " << 11 - rank << "]\n";
                std::cout << "-----------------------------------------\n";
                std::cout << "Property Name : " << top.first << "\n";
                std::cout << "Favorited Amount : " << top.second.second << "\n";
                std::cout << "-----------------------------------------\n";
                // Remove the property from the queue
                topFavourites.pop();
            }
            std::cout << "Options: (G)enerate Report, (Q)uit\n>>";
            cout << ">>";
            string userInput;
            getline(cin >> ws, userInput);
            cout << endl;

            if (userInput == "G" || userInput == "g") {
                FilterProperty property;
                cout << "[TOP 10 FAVOURITE PROPERTY REPORT PAGE]" << endl;
                for (const auto& pair : propertyFrequency) {
                    std::cout << "---------------------------\n";
                    property.displaySingleProperty(pair.second.first);
                }   
                cout << "Enter any key to continue to go back: ";
                string userInput;
                getline(cin >> ws, userInput);
                cout << endl;
            } else if (userInput == "Q" || userInput == "q"){

                break;
            }else {
                cout << "Invalid input. Please try again." << endl;
            }
        }
    }







};

#endif