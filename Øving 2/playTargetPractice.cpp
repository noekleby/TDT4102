//
//  playTargetPractice.cpp
//  Øving 2
//
//  Created by Magnus Pedersen on 23.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "playTargetPractice.h"
#include <iostream>
#include <ctime>
#include <stdlib.h> 
using namespace std;
void playTargetPractice()
{
    double absVelocity=0;
    int forsok=10;
    double radianer = 0;
    double skudd=0;
    srand( static_cast<unsigned int>(time(NULL)));
    double maal=rand()%100+50;
    double velocityX = 0;
	double velocityY = 0;
    double vinkel = 0;
    while(forsok>0 && skudd!=maal)
    {
        forsok--;
        cout << "Distanse til mål: " << maal << endl;
        cout << "Kanonkulens fart: " << endl;
        cin >> absVelocity;
        cout << "Kanonens vinkel: " << endl;
        cin >> vinkel;
        radianer = ((vinkel*3.14)/180);
        getVelocityVector(radianer, absVelocity, &velocityX, &velocityY);
		skudd = targetPractice(maal, velocityX, velocityY);
        if (skudd!=maal)
        {
            cout << "Sorry. Du var " << skudd << " meter fra målet." << endl;
            cout << "Du har " << forsok << " forsøk igjen." << endl;
            int iterasjoner = forsok;
            cout << "Trykk 0 for å avslutte, eller 1 for å fortsette: " << endl;
            cin >> forsok;
            if (forsok != 0)
            {
                forsok=iterasjoner;
            }
        }
        else
        {
            cout << "Gratulerer, du traff målet!" << endl;
            forsok=0;
            break;
        }
    }
    
}
