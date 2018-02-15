//
//  SimpleSet.h
//  Øving 9
//
//  Created by Magnus Pedersen on 25.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_9__SimpleSet__
#define ___ving_9__SimpleSet__

#include <iostream>
#include <algorithm>

template<typename T>
class SimpleSet{
public:
    /** Construct empty set **/
    SimpleSet(){currentSize = 0; data = new T(0); };
    /** Insert i into set, return true if the element was inserted, else false **/
    bool insert(T i)
    {
        if (exists(i))
        {
            resize(currentSize+1);
            data[currentSize-1]=i;
            return true;
        }
        else {return false;}
    };
    /** Returns true if i is in the set **/
    bool exists(T i)
    {
        if (find(i)){return true;}
        else {return false;}
    };
    /** Removes i from the set, return true if an element was removed **/
    bool remove(T i)
    {
        if (find(i))
        {
            data[find(i)]=
            resize(currentSize-1);
        }
    };
private:
    /** Dynamic array containing set elements **/
    T *data;
    /** Current number of elements **/
    T currentSize;
    /** Max capasity of data **/
    T maxSize;
    /** Returns the index where i may be found, else an invalid index. **/
    T find(T i);
    /** Resizes data, superflous elements are dropped. **/
    void resize(T n);
};
#endif /* defined(___ving_9__SimpleSet__) */
