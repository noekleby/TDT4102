//
//  struct.h
//  Øving 4
//
//  Created by Magnus Pedersen on 02.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_4__struct__
#define ___ving_4__struct__
#include <iostream>
#include "enumeration.h"
struct CardStruct {Suit s; Rank r;};
string intToStringShort (struct CardStruct);
string toString(struct CardStruct);
string kortFarge (Suit s);
string tall (Rank r);
string intToString(int number);
#endif /* defined(___ving_4__struct__) */
