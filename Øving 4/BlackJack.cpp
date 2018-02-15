//
//  BlackJack.cpp
//  Øving 4
//
//  Created by Magnus Pedersen on 06.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "BlackJack.h"
#include "string.h"
#include <iostream>
using namespace std;
int Blackjack::getCardValue(Card *card)
{
    Card c = *card;
    switch (c.getRank())
    {
        case ACE:
            return -1;break;
        case TWO:
            return 2;break;
        case THREE:
            return 3;break;
        case FOUR:
            return 4;break;
        case FIVE:
            return 5;break;
        case SIX:
            return 6;break;
        case SEVEN:
            return 7;break;
        case EIGHT:
            return 8;break;
        case NINE:
            return 9;break;
        case TEN:
            return 10;break;
        case JACK:
            return 11;break;
        case QUEEN:
            return 12;break;
        case KING:
            return 13;break;
        default:
            return 0;break;
    }
}
bool Blackjack::isAce(Card *card)
{
    Card c = *card;
    if (c.getRank()==ACE)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Blackjack::getPlayerCardValue(Card *card)
{
    int ess = 1;
    if (isAce(card))
    {
        cout << "Vennligst velg ønsket verdi for ess (1 eller 11): " << endl;
        cin >> ess;
        return ess;
    }
    else
    {
        return getCardValue(card);
    }
}
int Blackjack::getDealerCardValue(Card *DealerCard, int value)
{
    int kortverdi = getCardValue(DealerCard);
	if (kortverdi == -1)
	{
		if (value + 11 > 21)
		{
			return 1;
		}
		else
		{
			return 11;
		}
	}
	return kortverdi;
}
bool Blackjack::askPlayerDrawCard()
{
    string svar = "";
    cout << "Ønsker du et nytt kort? " << endl;
    cin >>  svar;
    if (svar == "ja")
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Blackjack::playGame()
{
    string svar = "";
	Blackjack deckOfCards;
    deckOfCards.deck.shuffle();
	cout << "Vil du spille blackjack? " << endl;
	cin >> svar;
    
	while (svar == "ja")
	{
        Card playerCard1 = deckOfCards.deck.drawCard();
        Card playerCard2 = deckOfCards.deck.drawCard();
        Card dealerCard1 = deckOfCards.deck.drawCard();
		Card dealerCard2 = deckOfCards.deck.drawCard();
        
		int PlayerPoints = 0;
        int DealerPoints= 0;
        
		cout << "Din starthånd: " << playerCard1.toString() << " og " << playerCard2.toString() << endl;
        
        PlayerPoints += getPlayerCardValue(&playerCard1) + getPlayerCardValue(&playerCard2);
        cout << "Totalpoeng: " << PlayerPoints << endl;
        cout << "Dealerens synlige kort: " << dealerCard1.toString() << endl << endl;
        
        while (askPlayerDrawCard())
		{
            Card playerCardTemp = deckOfCards.deck.drawCard();
			cout << "Du trakk: " << playerCardTemp.toString() << endl;
			PlayerPoints += getPlayerCardValue(&playerCardTemp);
			cout << "Totalpoeng: " << PlayerPoints << endl;
            if (PlayerPoints > 21)
			{
				break;
			}
		}
    DealerPoints += getDealerCardValue(&dealerCard1,0) + getDealerCardValue(&dealerCard2,getDealerCardValue(&dealerCard1,0));
        while (DealerPoints < 17)
		{
			Card DealerHandTemp = deckOfCards.deck.drawCard();
			DealerPoints += getDealerCardValue(&DealerHandTemp,DealerPoints);
		}
        if (DealerPoints > 21 && PlayerPoints > 21)
		{
			cout << "Dealer og spiller har over 21 poeng." << endl << endl;
		}
		else if ((DealerPoints > 21 || PlayerPoints > DealerPoints) && PlayerPoints < 22)
		{
			cout << "Du har vunnet med " << PlayerPoints << " mot " << DealerPoints << " poeng." << endl << endl;
		}
		else if (DealerPoints == PlayerPoints)
		{
			cout << "Uavgjort." << endl << endl;
		}
		else if ((DealerPoints > PlayerPoints && DealerPoints < 22) || PlayerPoints > 21)
		{
			cout << "Dealer vinner med " << DealerPoints << " poeng mot dine " << PlayerPoints << "." << endl << endl;
		}
        cout << "Vil du spille en gang til? " << endl;
		cin >> svar;
    }
}
