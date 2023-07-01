#ifndef USERACCOUNT_MANAGER_H
#define USERACCOUNT_MANAGER_H

#include <string>
#include <iostream>
#include <stdexcept>

template<class T>
class UserAccount_Manager {
private:
    T* objectArray;
    int size;
    int capacity;

public:
    UserAccount_Manager() : size(0), capacity(5) {
        objectArray = new T[capacity];
    }

    ~UserAccount_Manager() {
        delete[] objectArray;
    }

    void add(const T& object) {
        if (size == capacity) {
            capacity *= 2;
            T* newArray = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = objectArray[i];
            }
            delete[] objectArray;
            objectArray = newArray;
        }
        objectArray[size++] = object;
    }

    bool isEmailExists(const std::string& email) {
        for (int i = 0; i < size; ++i) {
            if (objectArray[i].getEmail() == email) {
                return true;
            }
        }
        return false;
    }

    void display(const std::string& userRole) {
        std::cout << std::endl;
        std::cout << userRole << " INFORMATION\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "[" << userRole << " " << (i + 1) << "]\n";
            std::cout << "Name: " << objectArray[i].getName() << std::endl;
            std::cout << "Email: " << objectArray[i].getEmail() << std::endl;
            std::cout << "Phone Number: " << objectArray[i].getPhoneNo() << std::endl;
            std::cout << "Identification No: " << objectArray[i].getIdentificationNo() << std::endl;
            std::cout << "Gender: " << objectArray[i].getGender() << std::endl;
            std::cout << "Date of Birth: " << objectArray[i].getDateOfBirth() << std::endl;

            if (userRole == "MANAGER") {
                std::cout << "Status: " << objectArray[i].getStatus() << std::endl;
            }
            std::cout << "---------------------------\n";
        }
    }

    void displayLatest(const std::string& userRole) {
        std::cout << std::endl;

        if (size > 0) {
            int lastIndex = size - 1;
            std::cout << "[" << userRole << " " << size << "]\n";
            std::cout << "Name: " << objectArray[lastIndex].getName() << std::endl;
            std::cout << "Email: " << objectArray[lastIndex].getEmail() << std::endl;
            std::cout << "Phone Number: " << objectArray[lastIndex].getPhoneNo() << std::endl;
            std::cout << "Identification No: " << objectArray[lastIndex].getIdentificationNo() << std::endl;
            std::cout << "Gender: " << objectArray[lastIndex].getGender() << std::endl;
            std::cout << "Date of Birth: " << objectArray[lastIndex].getDateOfBirth() << std::endl;

            if (userRole == "MANAGER") {
                std::cout << "Status: " << objectArray[lastIndex].getStatus() << std::endl;
            }
            std::cout << "---------------------------\n";
        }
    }

    int getSize() const {
        return size;
    }

    T& getManager(int index) {
        if (index >= 0 && index < size) {
            return objectArray[index];
        } else {
            // Handle index out of bounds error
            throw std::out_of_range("Invalid index");
        }
    }
};

// void delete(int index) {
//     if (index >= 0 && index < size) {
//         for (int i = index; i < size - 1; ++i) {
//             objectArray[i] = objectArray[i + 1];
//         }
//         --size;
//     }
// }

#endif
