#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <string>
#include <iostream>
#include <stdexcept>

template <class T>
class DynamicArray
{
private:
    T *objectArray;
    int size;
    int capacity;

public:
    DynamicArray() : size(0), capacity(5)
    {
        objectArray = new T[capacity];
    }

    ~DynamicArray()
    {
        delete[] objectArray;
    }

    void insertAtBeginning(const T &object)
    {
        insertAtIndex(object, 0);
    }

    void insertAtEnd(const T &object)
    {
        insertAtIndex(object, size);
    }

    void insertAtIndex(const T &object, int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Invalid index");
        }

        if (size == capacity)
        {
            capacity *= 2;
            T *newArray = new T[capacity];
            for (int i = 0; i < index; ++i)
            {
                newArray[i] = objectArray[i];
            }
            newArray[index] = object;
            for (int i = index; i < size; ++i)
            {
                newArray[i + 1] = objectArray[i];
            }
            delete[] objectArray;
            objectArray = newArray;
            size++;
        }
        else
        {
            for (int i = size - 1; i >= index; --i)
            {
                objectArray[i + 1] = objectArray[i];
            }
            objectArray[index] = object;
            size++;
        }
    }

    // bool isEmailExists(const std::string& email) {
    //     for (int i = 0; i < size; ++i) {
    //         if (objectArray[i].getEmail() == email) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    int getSize() const
    {
        return size;
    }

    T &get(int index)
    {
        if (index >= 0 && index < size)
        {
            return objectArray[index];
        }
        else
        {
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
