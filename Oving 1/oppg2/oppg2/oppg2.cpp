//
//  oppg2.cpp
//  oppg2
//
//  Created by Magnus Pedersen on 15.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "oppg2.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
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
void getAndPrintMoreSums ()
{
    int sum = 0;
    int tall = 1;
    cout << "Vennligst tast inn tall, eller velg 0 for å avslutte:" << endl;
    while (tall != 0)
    {
        tall = getAndReturnInteger();
        sum += tall;
    }
    cout << "Summen ble: " << sum << endl;
}
//2b): Vi vet ikke hvor lenge brukeren ønsker å taste inn tall, og dermed heller ikke hvor lenge løkka skal kjøre. Derfor er det hensiktsmessig med en while-løkke som kjører så lenge betingelsen er false.
double getAndReturnDouble ()
{
    double tall = 0;
    cin >> tall;
    return tall;

}
void fromNOKtilEuro()
{
    double euro = 0;
    cout << "Vennligst tast inn antall NOK: " << endl;
    double nok = getAndReturnDouble();
    if (nok < 0)
    {
        fromNOKtilEuro();
    }
    else
    {
        euro = (nok/7.84);
        cout << setprecision(2) << fixed<< "Euro: " << euro << endl;
    }
}
void gangeTabell()
{
    int bredde;
    int hoyde;
    cout << "Skriv inn bredde: " << endl;
    cin >> bredde;
    cout << "Skriv inn høyde: " << endl;
    cin >> hoyde;
    for (int i=1; i<=hoyde; i++)
    {
        for (int j=1; j<=bredde; j++)
        {
            cout << "    " << (j*i);
        }
        cout << endl;
    }
}
//2e: Bruker getAndReturnDouble fordi konverteringen skal skje med desimaltall ifølge oppgaveteksten, og ikke heltall som i integer, hvor man bare runder av. Bruker returtypen void fordi vi bare trenger å returnere noe til skjerm.
//3a)
void sekundKonvertering ()
{
    int tid,time,sekunder,min;
    cout << "Vennligst skriv inn antall sekunder: " << endl;
    cin >> tid;
    time=tid/3600;
    tid=tid%3600;
    min=tid/60;
    tid=tid%60;
    sekunder=tid;
    cout << "Tiden er: " << time << " timer, " << min << " minutter, " << sekunder << " sekunder." << endl;
}
void regning ()
{
    double pris;
    cout << " Skriv inn sum på regningen: " << endl;
    cin >> pris;
    double prisMVA = pris*1.0875;
    int tips = prisMVA*0.18;
    cout << setprecision(2) << fixed << endl;
    cout << "Pris: " <<pris << " | MVA: " << (pris*0.0875) << " | Tips: " << tips << " | Totalpris: " << (prisMVA+tips) << endl;
    
}
//Oppg 4
void parelleroddetall()
{
    cout << " Skriv inn tall: " << endl;
    int tall = getAndReturnInteger();
    if (tall%2==0)
    {
        cout << "Tallet er et partall." << endl;
    }
    else
    {
        cout << "Tallet er et oddetall." << endl;
    }
}
void storsteTall()
{
    cout << "Skriv inn to tall: " << endl;
    int tall1 = getAndReturnInteger();
    int tall2 = getAndReturnInteger();
    if (tall1 < tall2)
    {
        cout << tall2 << " er større enn " << tall1 << endl;
    }
    else if (tall1 > tall2)
    {
        cout << tall1 << " er større enn " << tall2 << endl;
    }
    else
    {
        cout << "Tallene er like store" << endl;
    }
}

// Brukeren kan ikke selv skrive inn tallene ved en annen spørsmålsstilling. Da tar funksjonen heller inn tallene som argumenter til funksjonen istedet.
int main ()
{
    int quit = 11;
    while (quit != 0)
    {
        cout << "Velg funksjon: " << endl
        << "0) Avslutt " << endl
        << "1) Summer to tall " << endl
        << "2) Summer flere tall " << endl
        << "3) Konverter NOK til EURO. " << endl
        << "4) Lag gangetabell. " << endl
        << "5) Konverter sekunder. " << endl
        << "6) Finn totalsum til regning. " << endl
        << "7) Sjekk om tall er partall eller ikke. " << endl
        << "8) Sjekk hvilket tall som er størst. " << endl
        << "9) Løs andregradsuttrykk. " << endl
        << "10) Kalkuler lån. " << endl
        << "Angi valg (0-10): " << endl;
        cin >> quit;
        switch (quit)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                getAndPrintSum();
                break;
            }
            case 2:
            {
                getAndPrintMoreSums();
                break;
            }
            case 3:
            {
                fromNOKtilEuro();
                break;
            }
            case 4:
            {
                gangeTabell();
                break;
            }
            case 5:
            {
                sekundKonvertering();
                break;
            }
            case 6:
            {
                regning();
                break;
            }
            case 7:
            {
                parelleroddetall();
                break;
            }
            case 8:
            {
                storsteTall();
                break;
            }
            case 9:
            {
                solveAndPrintRoots();
                break;
            }
            case 10:
            {
                calculateLoanPayments();
                break;
            }
        }
    }
}