//
//  luke.cpp
//  ovingsforelesning 2
//
//  Created by Magnus Pedersen on 31.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "luke.h"
#include <iostream>
using namespace std;
void luke::init(const char * content)
{
    isOpened = false;
    contents = content;
    
}
void luke::open()
{
    if (isOpened)
    {
        cout << "This 'luke' was opened. It used to contain " << contents << endl;
    }
    else
    {
        isOpened = true;
        cout << "This 'luke' contains " << contents << endl;
    }
}