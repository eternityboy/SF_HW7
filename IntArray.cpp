#include "IntArray.h"
#include <iostream>

IntArray::IntArray(int length) : m_length(length) {
    std::cout << "... Creating array" << std::endl;
    if (length < 0) {
        throw BadLength();
    }
    if (length > 0)
        m_data = new int[length]{};
}

IntArray::~IntArray() {
    delete[] m_data;
    std::cout << "Destruct array" << std::endl;
    // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
}

void IntArray::showLength() {
    std::cout << "... Array length is: " << m_length << std::endl;
}

void IntArray::showArray() {
    for (int size_t = 0; size_t < m_length; size_t++) {
        std::cout << m_data[size_t] << " ";
    }
    std::cout << std::endl;
}

void IntArray::CreateArray() {
    std::cout << "... Filling up an array" << std::endl;
    for (int size_t = 0; size_t < m_length; size_t++) {
        m_data[size_t] = size_t;
    }
    std::cout << "... Filling up finished" << std::endl;
}

void IntArray::erase() {
    std::cout << "... Erase all data in array" << std::endl;
    delete[] m_data;
    // We need to make sure we set m_data to nullptr here, otherwise it will be left pointing at deallocated memory!
    m_data = nullptr;
    m_length = 0;
}

void IntArray::resize(int newLength) {
    std::cout << "Old array size is " << m_length << ", and new array size is " << newLength << std::endl;

    // if the array is already the right length, we're done
    if (newLength == m_length) {
        std::cout << "... It's the same size. Nothing has been changed" << std::endl;
        return;
    }

    // If we are resizing to an empty array, do that and return
    if (newLength <= 0) {
        std::cout << "... Ooops... Wrong array size" << std::endl;
        erase();
        return;
    }

    // Now we can assume newLength is at least 1 element.
    // This algorithm works as follows: First we are going to allocate a new array.
    // Then we are going to copy elements from the existing array to the new array.
    // Once that is done, we can destroy the old array, and make m_data point to the new array.

    // First we have to allocate a new array
    int *data = new int[newLength];

    std::cout << "... m_length " << m_length << std::endl;

    // Then we have to figure out how many elements to copy from the existing array to the new array.
    // We want to copy as many elements as there are in the smaller of the two arrays.
    if (m_length > 0) {

        int elementsToCopy = (newLength > m_length) ? m_length : newLength;

        std::cout << "... elements to copy: " << elementsToCopy << std::endl;
        for (int size_t{0}; size_t < elementsToCopy; ++size_t) {
            data[size_t] = m_data[size_t];
        }
        std::cout << "... elements to create: " << newLength - m_length << std::endl;
        for (int size_t = m_length; size_t < newLength; size_t++) {
            data[size_t] = size_t;
        }
    }

    // Now we can delete the old array because we don't need it any more
    delete[] m_data;

    // And use the new array instead!
    // Note that this simply makes m_data point to the same address as the new array we dynamically allocated.
    // Because data was dynamically allocated, it won't be destroyed when it goes out of scope.
    m_data = data;
    m_length = newLength;
}

void IntArray::insert(int value, int index)
{
    std::cout << "... Adding new element " << value << " to the position " << index << std::endl;

    // Check if the index is outside of array length
    if (index < 0 || index > m_length)
    {
        throw BadRange();
    }

    // allocate a new array with +1 spot
    int* data = new int[m_length + 1];

    // fill new array until index with old data
    for (int size_t{0}; size_t < index; ++size_t)
    {
        data[size_t] = m_data[size_t];
    }

    // add new value to index
    data[index] = value;

    // fill new array after index to the end with old data
    for (int size_t = index; size_t < m_length; ++size_t)
    {
        data[size_t + 1] = m_data[size_t];
    }

    // Now we can delete the old array because we don't need it anymore
    delete[] m_data;

    // And use the new array instead! And update m_length as well.
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index)
{
    std::cout << "... Removing an element at index " << index << std::endl;

    // Check if the index is outside of array length
    if (index < 0 || index > m_length)
    {
        throw BadRange();
    }

    // If this is the last remaining element in the array, set the array to empty and bail out
    if (m_length == 1)
    {
        erase();
        return;
    }

    // allocate a new array with -1 spot
    int* data = new int[m_length - 1];

    // fill new array until index with old data
    for (int size_t{0}; size_t < index; ++size_t)
    {
        data[size_t] = m_data[size_t];
    }

    // fill new array after index to the end with old data
    for (int size_t{index + 1}; size_t < m_length; ++size_t)
    {
        data[size_t - 1] = m_data[size_t];
    }

    // Now we can delete the old array because we don't need it anymore
    delete[] m_data;

    // And use the new array instead! And update m_length as well.
    m_data = data;
    --m_length;
}

void IntArray::insertAtTheBeginning(int value)
{
    insert(value, 0);
}

void IntArray::insertAtTheEnd(int value)
{
    insert(value, m_length);
}