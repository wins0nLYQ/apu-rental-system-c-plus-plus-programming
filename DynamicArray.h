#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <string>
#include <iostream>
#include <stdexcept>

template <class T>
class DynamicArray
{
private:
    T *objectArray; // Pointer to the dynamic array
    int size;       // Current number of elements in the array
    int capacity;   // Current capacity of the array

public:
    // Constructor initializes the dynamic array with a default capacity
    DynamicArray() : size(0), capacity(5)
    {
        objectArray = new T[capacity];
    }

    // Destructor releases memory occupied by the dynamic array
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
            throw std::out_of_range("Invalid index");
        }
    }

    void set(int index, const T& object)
    {
        if (index >= 0 && index < size)
        {
            objectArray[index] = object;
        }
        else
        {
            throw std::out_of_range("Invalid index");
        }
    }

    void removeAt(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < size - 1; ++i)
            {
                objectArray[i] = objectArray[i + 1];
            }
            size--;
        }
        else
        {
            throw std::out_of_range("Invalid index");
        }
    }

    void removeAtBeginning()
    {
        removeAt(0);
    }

    void removeAtEnd()
    {
        removeAt(size - 1);
    }

    int getIndex(const T &object) {
        for (int i = 0; i < size; ++i) {
            if (objectArray[i] == object) {
                return i;
            }
        }

        return -1;
    }
};



#endif
