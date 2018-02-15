//
//  safeArray.cpp
//  Øving 10
//
//  Created by Magnus Pedersen on 28.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "safeArray.h"
#include <stdexcept>
template<typename T>
safeArray<T>::safeArray(unsigned int arrLength)
{
    this->arr = new T[arrLength]();
}
template<typename T>
safeArray<T>::~safeArray()
{
    delete [] arr;
    arr = nullptr;
}
template<class T>
unsigned int safeArray<T>::getSize()
{
    return this->arrLength;
}
template<class T>
safeArray<T>& safeArray<T>::operator=(const safeArray &rhs)
{
    arrLength = rhs.getSize();
    delete[] arr;
    arr = new T[arrLength];
    for (int i = 0; i < arrLength; i++)
    {
        this->arr[i] = rhs.arr(i);
    }
    return *this;
}
template<class T>
safeArray<T>& safeArray<T>::operator[](const int n)
{
    if (!exists(arr(n)))
    {
        throw std::out_of_range("Dette gikk galt. You're out of bounds!");
    }
    return arr[n];
}
template<class T>
void safeArray<T>::resize(int capacity)
{
    maxsize = capacity;
    if (arrLength > capacity)
    {
        arrLength = capacity;
    }
    int * newdata = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        newdata[i] = arr[i];
    }
    for (int i = arrLength; i < capacity; i++)
    {
        newdata[i] = 0;
    }
    delete[] arr;
    arr = newdata;
}