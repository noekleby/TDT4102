//
//  deckClass.cpp
//  Øving 4
//
//  Created by Magnus Pedersen on 06.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "cardDeck.h"
#include <iostream>
#include "ctime"
#include "string.h"
using namespace std;

cardDeck::cardDeck()
{
	currentCardIndex = 0;
    int index = 0;
    for (int suit = 0; suit < 4; suit++)
    {
        for (int rank = 2; rank < 15; rank++)
        {
            cards[index] = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
            index++;
        }
    }
}

void cardDeck::swap(int a, int b)
{
	Card temp = cards[a];
	cards[a] = cards[b];
	cards[a] = temp;
	
}

void cardDeck::print()
{
	for (int i = 0; i < 52; i++)
	{
		cout << cards[i].toString() << endl;
	}
}

void cardDeck::printShort()
{
	for (int i = 0; i < 52; i++)
	{
		cout << cards[i].Card::toStringShort() << endl;;
	}
}


void cardDeck::shuffle()
{
    for (int i=0; i<1000;i++)
    {
        swap(rand()%52, rand()%52);
    }
}

Card cardDeck::drawCard()
{
	return cards[currentCardIndex++];//currentCardIndex hindrere tilbakelegging av kortet
}
