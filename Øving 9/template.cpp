//
//  template.cpp
//  Øving 9
//
//  Created by Magnus Pedersen on 24.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//
#include <random>
#include <ctime>
#include <algorithm>
#include <string>
#include "template.h"
template<typename T>
void shuffle (T* tabell, int storrelse )
{
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < storrelse; i++)
    {
        std::swap(tabell[rand()%storrelse], tabell[rand()%storrelse]);
    }
}
template<typename T>
T maximum (T t1, T t2)
{
    if (t1 < t2)
    {
        return t2;
    }
    else if(t1 > t2)
    {
        return t1;
    }
}
