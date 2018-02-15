//
//  utilities.cpp
//  Øving 3
//
//  Created by Magnus Pedersen on 28.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "utilities.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "tests.h"
using namespace std;
int randomWithLimits(double boundLow, double boundHigh)
{
    srand( static_cast<unsigned int>(time(NULL)));
    double difference = boundHigh-boundLow;
    int tall=rand()%(int)difference+static_cast<int>(boundLow);
    //cout << tall;
    return tall;
}
char randomCharWithLimits(char a, char b)
{
    int difference = (int)a-(int)b;
    int bokstav=(char)((rand()%difference)+(int)a);
    //cout << (char)bokstav;
    return (char)bokstav;
}
/* CALL BY VALUE 
 2a)    V0: 5
*/