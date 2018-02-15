//
//  struct.cpp
//  Øving 4
//
//  Created by Magnus Pedersen on 02.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "struct.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
using namespace std;
string toString(CardStruct card)
{
    string suit = suitToString(card.s);
    string rank = rankToString(card.r);
    return suit+"of"+rank;
}
string intToString(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}
string kortFarge (Suit s)
{
    switch (s)
    {
        case CLUBS:
            return "C";
            break;
        case DIAMONDS:
            return "D";
            break;
        case HEARTS:
            return "H";
            break;
        case SPADES:
            return "S";
            break;
        default:
            return 0;
            break;
    }
}
string tall (Rank r)
{
    switch (r)
    {
        case TWO:
            return "2";break;
        case THREE:
            return "3";break;
        case FOUR:
            return "4";break;
        case FIVE:
            return "5";break;
        case SIX:
            return "6";break;
        case SEVEN:
            return "7";break;
        case EIGHT:
            return "8";break;
        case NINE:
            return "9";break;
        case TEN:
            return "10";break;
        case JACK:
            return "11";break;
        case QUEEN:
            return "12";break;
        case KING:
            return "13";break;
        case ACE:
            return "14";break;
        default:
            return 0;break;
    }
}
string intToStringShort (CardStruct card)
{
    string str = suitToString(card.s);
    string color = str.substr(0,1);
    string ranking = intToString(card.r);
    return color+ranking;
    
}