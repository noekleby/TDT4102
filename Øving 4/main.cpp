//
//  main.cpp
//  Øving 4
//
//  Created by Magnus Pedersen on 02.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "main.h"
#include <iostream>
#include "string.h"
#include "klasser.h"
#include "ctime"
using namespace std;
int main ()
{
    srand(static_cast<unsigned>(time(0)));
    //CardStruct c;
	//c.r = ACE;
	//c.s = CLUBS;
	//Card C = Card(CLUBS, TWO);
    
	//cout << C.toString() << endl;
	//cout << intToStringShort(C) << endl;
    
    /*Card p;
    Suit s = SPADES;
    Rank r = FOUR;
    cout << p.toString() << endl;*/
    /*cardDeck c;
    c.printShort();*/
    

   Blackjack e;
e.playGame();
    
    return 0;
}