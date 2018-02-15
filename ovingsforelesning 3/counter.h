//
//  counter.h
//  ovingsforelesning 3
//
//  Created by Magnus Pedersen on 07.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef __ovingsforelesning_3__counter__
#define __ovingsforelesning_3__counter__

#include <iostream>
class Counter
{
private:
    int val;
public:
    Counter():val(13){}
    int getVal() {return val;}
    void increment (){val++;}
    Counter(int value):val(value){}
};

#endif /* defined(__ovingsforelesning_3__counter__) */
