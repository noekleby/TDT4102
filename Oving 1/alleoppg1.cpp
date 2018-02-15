//
//  alleoppg1.cpp
//  Oving 1
//
//  Created by Magnus Pedersen on 14.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "alleoppg1.h"
#include <iostream>
using namespace std;
void getAndPrintInteger()
{
    int tall = 0;
    cout << "Skriv inn et tall: " << endl;
    cin >> tall;
    cout << "Du skrev: " << tall << endl;
}
int getAndReturnInteger()
{
    int tall = 0;
    cin >> tall;
    return tall;
}
void getAndPrintSum()
{
    int sum;
    int tall1 = getAndReturnInteger();
    int tall2 = getAndReturnInteger();
    sum = tall1+tall2;
    cout << sum << endl;
}
int main ()
{
    getAndPrintInteger();
    //getAndReturnInteger();
    //getAndPrintSum();
    return 0;
}

/* Oppgave 1c:
 Siste funksjonenen returnerer en integer. Den første har returntypen void. Integer må brukes hvis vi ikke skal skrive ut til skjerm, men returnere. Integer-funksjonen returnerer et heltall, mens void ikke returnerer noe i det hele tatt.*/

/* Valgte å bruke getAndPrintSum pga. at den returnerer noe. Den kan kalles på uten at du skriver noe ut til skjerm. */




