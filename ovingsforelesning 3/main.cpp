//
//  main.cpp
//  ovingsforelesning 3
//
//  Created by Magnus Pedersen on 07.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "main.h"
#include <iostream>
using namespace std;
int main ()
{
    Counter teller(974);
    cout << teller.getVal() << endl;
    teller.increment();
    cout << teller.getVal() << endl << endl;

    return 0;
}