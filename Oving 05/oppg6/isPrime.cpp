//
//  isPrime.cpp
//  oving 0.5
//
//  Created by Magnus Pedersen on 09.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "isPrime.h"
#include <iostream>
using namespace std;
bool isPrime(int n)
{
    bool primeness = true;
    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            primeness = false;
            break;
        }
    }
    return primeness;
}
int main()
{
    cout << isPrime(28)<< endl;
    return 0;
}