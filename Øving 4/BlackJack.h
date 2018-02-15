//
//  BlackJack.h
//  Øving 4
//
//  Created by Magnus Pedersen on 06.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_4__BlackJack__
#define ___ving_4__BlackJack__

#include <iostream>
#include "cardDeck.h"
class Blackjack
{
private:
    cardDeck deck;
public:
    int getCardValue(Card *card);
	bool isAce(Card *card);
	int getPlayerCardValue(Card *card);
	int getDealerCardValue(Card *DealerCard, int value);
	bool askPlayerDrawCard();
	void playGame();
    void drawCard();
};

#endif /* defined(___ving_4__BlackJack__) */
