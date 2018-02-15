//
//  playMastermind.cpp
//  Øving 3
//
//  Created by Magnus Pedersen on 02.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "playMastermind.h"
#include <iostream>
#include "tests.h"
using namespace std;
int checkCharactersAndPosition (char code[], char guess[], int SIZE)
{
    int occurences = 0;
    for (int i=0;i<SIZE; i++)
    {
        if (code[i]==guess[i])
        {
            occurences++;
        }
    }
    return occurences;
}
int checkCharacters(char code[], char guess[], int SIZE, int LETTERS)
{
    int riktige = 0;
    for (int i=0;i<LETTERS;i++)
    {
        if (countOccurencesOfCharacter(code, SIZE, 'A'+i)<countOccurencesOfCharacter(guess, SIZE, 'A'+i))
        {
            riktige+=countOccurencesOfCharacter(code, SIZE, 'A'+i);
        }
        else
        {
            riktige+=countOccurencesOfCharacter(guess, SIZE, 'A'+i);
        }
    }
    return riktige;
}
void playMastermind ()
{
    int riktigPlassert = 0;
    const int SIZE = 4;
    const int LETTERS = 6;
    char code[SIZE+1]={};
    char guess[SIZE+1]={};
    int forsok = 0;
    randomizeCString(code,SIZE, 'A', 'A'+LETTERS);
    //cout << code;
    while ((forsok < SIZE)&&(riktigPlassert < SIZE))
    {
        cout << "Gjett bokstaver: " << endl;
        readInputToCString(guess,SIZE, 'A', 'A'+LETTERS-1);
        riktigPlassert = checkCharactersAndPosition(code,guess,SIZE);
        
        
        cout << "Riktig plassert: " << riktigPlassert << endl;
        cout << "Riktige bokstaver: " << checkCharacters(code, guess, SIZE, LETTERS) << endl;
        forsok++;
        cout << "Du har " << (SIZE-forsok) << " forsøk igjen." << endl << endl;
    }
    if (forsok >= SIZE)
    {
        cout << "Beklager. Dette gikk ikke." << endl;
        cout << "Svaret var " << code << "." << endl;

    }
    else
    {
        int spillIgjen = 0;
        cout << "Gratulerer, du vant!" << endl;
        cout << "Press 1 for å spille på nytt, eller 0 for å avslutte: " << endl;
        cin >> spillIgjen;
        if (spillIgjen==1)
        {
            playMastermind();
        }
    }
}
