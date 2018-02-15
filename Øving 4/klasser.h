//
//  klasser.h
//  Øving 4
//
//  Created by Magnus Pedersen on 03.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_4__klasser__
#define ___ving_4__klasser__
#include <iostream>
#include "struct.h"
#include "enumeration.h"
class Card
{
private:
    Suit s;
    Rank r;
    bool invalid;
public:
    Card();
    Card(Suit s, Rank r);
    void initialize(Suit s, Rank r);
    Suit getSuit();
    Rank getRank();
    string toString();
    string toStringShort();
};
#endif /* defined(___ving_4__klasser__) */
