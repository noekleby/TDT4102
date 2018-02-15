//
//  klasser.cpp
//  Øving 4
//
//  Created by Magnus Pedersen on 03.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "klasser.h"
#include <iostream>
using namespace std;
void Card::initialize(Suit s, Rank r)
{
    this-> s = s;
    this-> r = r;
    invalid = false;
}
Suit Card::getSuit()
{
    return this->s;
}
Rank Card::getRank()
{
    return this->r;
}
string Card::toString()
{
    if (invalid == 1)
    {
        return "Not a valid card";
    }
    else
    {
        string suit = suitToString(s);
        string rank = rankToString(r);
        return rank + " of " + suit;
    }
}
string Card::toStringShort()
{
    if (invalid == 1)
    {
        return "Not a valid card";
    }
    else
    {
        string str = suitToString(s);
        string color = str.substr(0,1);
        string ranking = intToString(r);
        return color+ranking;
    }
}
Card::Card() //Card() og card(suit, rank) under må grønnes ut for å få skrevet ut kort fra toString
{
    invalid = true;
}
Card::Card(Suit s, Rank r)
{
    initialize(s,r);
}