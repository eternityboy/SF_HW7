#include <iostream>
#pragma once

class BadRange : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Error! Incorrect index";
    }
};

class BadLength: public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Error! Array length can't be less than zero";
    }
};

class IntArray {
private:
    int m_length{};
    int* m_data{};
public:
    IntArray() = default;
    IntArray(int length);
    ~IntArray();
    void showLength(); //Report the number of objects currently in the container
    void CreateArray(); //Provide access to the stored objects
    void showArray();
    void erase();
    void resize(int newLength);
    void insert(int value, int index); //Insert a new object into the container
    void remove(int index); //Remove an object from the container
    void insertAtTheBeginning(int value); //Insert a new object into the container
    void insertAtTheEnd(int value); //Insert a new object into the container
};
