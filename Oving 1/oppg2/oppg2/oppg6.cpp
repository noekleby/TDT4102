//
//  oppg6.cpp
//  oppg2
//
//  Created by Magnus Pedersen on 16.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "oppg6.h"
#include <iostream>
using namespace std;
void calculateLoanPayments()
{
    cout << "Skriv inn lån: " << endl;
    double laan = getAndReturnDouble();
    cout << "Skriv inn rente: " << endl;
    double rente = getAndReturnDouble();
    double restlaan = laan;
    cout << "År \t" << "Innbetaling \t" << "Gjenstående lån \t" << endl;
    for (int i=0; i<=10;i++)
    {
        double innbetaling = (laan/10)+(rente/100)*restlaan;
        restlaan-=(laan/10);
        cout << i << "\t\t" << innbetaling << "\t\t\t\t\t" << restlaan << endl;
    }
}