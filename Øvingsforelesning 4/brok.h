//
//  brok.h
//  Øvingsforelesning 4
//
//  Created by Magnus Pedersen on 14.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___vingsforelesning_4__brok__
#define ___vingsforelesning_4__brok__

#include <iostream>
class brok
{
private:
    int teller,nevner;
public:
    brok(int teller, int nevner):teller{teller},nevner{nevner} {}
    brok(int integer) : brok{integer, 1}
    {}
    brok() : brok {0,1}
    {}
    double kvotient()const{return static_cast<double>(teller)/nevner;}
    int tell()const{return teller;}
    int nevn()const{return nevner;}
    void set(int tell, int nevn)
    {
        this->tell = tell;
        this-> nevn = nevn;
    }
    void setTell(int tell)
    {
        this->tell = tell;
    }
    void setNevn(int nevn)
    {
        this-> nevn = nevn;
    }
};

#endif /* defined(___vingsforelesning_4__brok__) */
