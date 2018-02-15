//
//  luke.h
//  ovingsforelesning 2
//
//  Created by Magnus Pedersen on 31.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//
#pragma once
#ifndef __ovingsforelesning_2__luke__
#define __ovingsforelesning_2__luke__

#include<string>
#include <iostream>
class luke {
private:
    bool isOpened;
    std::string contents;
    
public:
    void init(const char * contents);
    void open();
};

#endif /* defined(__ovingsforelesning_2__luke__) */
