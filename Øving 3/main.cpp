//
//  main.cpp
//  Øving 3
//
//  Created by Magnus Pedersen on 28.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "main.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main ()
{
    srand( static_cast<unsigned int>(time(NULL)));
    //randomWithLimits(2, 20);
    //randomCharWithLimits('c', 'e');
    //testPart4();
    playMastermind();
    return 0;
}
