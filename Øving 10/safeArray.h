//
//  safeArray.h
//  Øving 10
//
//  Created by Magnus Pedersen on 28.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_10__safeArray__
#define ___ving_10__safeArray__

#include <iostream>
template<class T>
class safeArray
{
private:
    T *arr= nullptr;
    unsigned int arrLength = 0;
    unsigned int maxsize = 0;
public:
    safeArray(unsigned int arrLength);
    ~safeArray();
    safeArray& operator=(const safeArray &rhs);
    unsigned int getSize();
    const T& operator[](int)const;
    T& operator[](const int n);
    void resize(int capacity);
};
#endif /* defined(___ving_10__safeArray__) */
