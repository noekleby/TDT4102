//
//  Tall i boks.cpp
//  ovingsforelesning1
//
//  Created by Magnus Pedersen on 17.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "Tall i boks.h"
#include <iostream>

using namespace std;

int main ()
{
    int a,b,c,d,e = 0;
    int *p = nullptr;
    
    char input;
    
    cout << "which variable do you want to use? " << endl;
    cin >> input;
    
    switch (input)
    {
        case 'a':
        {
            p = &a;
            break;
        }
        case 'b':
        {
            p = &b;
            break;
        }
        case 'c':
        {
            p = &c;
            break;
        }
        case 'd':
        {
            p = &d;
            break;
        }
        case 'e':
        {
            p = &e;
            break;
        }
        default:
        {
            cout << "Some error occured" << endl;
        }
    }
    cout << "Enter a number: " << endl;
    cin >> *p;
    
    cout << " a: " << a << " b: " << b << " c: " << c << " d: " << d << " e: " << e << endl;
    return 0;
}
