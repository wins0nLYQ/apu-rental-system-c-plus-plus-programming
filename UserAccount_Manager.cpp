#include <iostream>
#include <string>

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

    bool isEmailExists(const string& email) {
        for (int i = 0; i < size; ++i) {
            if (objectArray[i].getEmail() == email) {
                return true;
            }
        }
        return false;
    }

    // void delete(int index) {
    //     if (index >= 0 && index < size) {
    //         for (int i = index; i < size - 1; ++i) {
    //             objectArray[i] = objectArray[i + 1];
    //         }
    //         --size;
    //     }
    // }

    void display(string userRole) {
        std::cout << endl;
        std::cout << userRole << " INFORMATION\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "[" << userRole << " " << (i + 1) << "]\n";
            std::cout << "Name: " << objectArray[i].getName() << std::endl;
            std::cout << "Email: " << objectArray[i].getEmail() << std::endl;
            std::cout << "Phone Number: " << objectArray[i].getPhoneNo() << std::endl;
            std::cout << "Identificatio No: " << objectArray[i].getIdentificationNo() << std::endl;
            std::cout << "Gender: " << objectArray[i].getGender() << std::endl;
            std::cout << "Date of Birth: " << objectArray[i].getDateOfBirth() << std::endl;

            if(userRole == "MANAGER") {
                std::cout << "Status: " << objectArray[i].getStatus() << std::endl;
            }
            std::cout << "---------------------------\n";
        }
    }
};