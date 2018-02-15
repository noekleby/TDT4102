//
//  enumeration.cpp
//  Øving 4
//
//  Created by Magnus Pedersen on 02.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "enumeration.h"
#include <iostream>
#include <string.h>
using namespace std;
string suitToString(Suit c)
{
    switch (c)
    {
        case CLUBS:
            return "Clubs";
            break;
        case DIAMONDS:
            return "Diamonds";
            break;
        case HEARTS:
            return "Hearts";
            break;
        case SPADES:
            return "Spades";
            break;
        default:
            return 0;
            break;
    }
}
string rankToString(Rank c)
{
    switch (c)
    {
        case ACE:
            return "Ace";break;
        case TWO:
            return "Two";break;
        case THREE:
            return "Three";break;
        case FOUR:
            return "Four";break;
        case FIVE:
            return "Five";break;
        case SIX:
            return "Six";break;
        case SEVEN:
            return "Seven";break;
        case EIGHT:
            return "Eight";break;
        case NINE:
            return "Nine";break;
        case TEN:
            return "Ten";break;
        case JACK:
            return "Jack";break;
        case QUEEN:
            return "Queen";break;
        case KING:
            return "King";break;
        default:
            return 0;break;
    }
}
