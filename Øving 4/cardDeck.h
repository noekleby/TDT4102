//
//  deckClass.h
//  Øving 4
//
//  Created by Magnus Pedersen on 06.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_4__deckClass__
#define ___ving_4__deckClass__

#include <iostream>
#include "klasser.h"
class cardDeck
{
public:
	cardDeck();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();
private:
	void swap(int a, int b);
	Card cards[52];
	int currentCardIndex = 0;
    
};

#endif /* defined(___ving_4__deckClass__) */
