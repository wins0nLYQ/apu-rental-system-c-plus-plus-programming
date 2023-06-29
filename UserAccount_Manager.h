#ifndef USERACCOUNT_MANAGER_H
#define USERACCOUNT_MANAGER_H

#include <string>

template<class T>
class UserAccount_Manager {
private:
    T* objectArray;
    int size;
    int capacity;

public:
    UserAccount_Manager();
    ~UserAccount_Manager();

    void add(const T& object);
    bool isEmailExists(const std::string& email);
    void display(const std::string& userRole);
    void displayLatest(const std::string& userRole);
    int getSize() const;
    T& getManager(int index);
};

#endif