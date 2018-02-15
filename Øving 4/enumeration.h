//
//  enumeration.h
//  Øving 4
//
//  Created by Magnus Pedersen on 02.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_4__enumeration__
#define ___ving_4__enumeration__
#include <iostream>
#include <string.h>
using namespace std;
enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
string suitToString(Suit c);
string rankToString(Rank c);
#endif /* defined(___ving_4__enumeration__) */
