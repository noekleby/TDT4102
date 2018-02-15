//
//  oppg2.cpp
//  Øving 7
//
//  Created by Magnus Pedersen on 05.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "oppg2.h"
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
void tegnstatistikk()
{
    int chars[26] = {0};
    char c;
    int totchars = 0;
    
    ifstream in("oppg1a.txt");
    if (!in)
    {
        cout << "Cannot open file.\n";
        exit(1);
    }
    while (in >> c)
    {
        c = tolower(c);
        if (isalpha(c)) //sjekker om c er en bokstav
        {
            chars[c - 'a']++;
            totchars++;
        }
    }
    cout << "Character statistics:" << endl << "----------------------------" << endl;
    cout << "Total number of characters: " << totchars << endl;
    
    for (int i = 0; i < 26; i++)
    {
        if (i % 4 == 0)
        {
            cout << endl;
        }
        cout << (char)(i + 'a') << ": " << chars[i] << "\t";
    }
    cout << endl;
    in.close();
}