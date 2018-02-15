//
//  oppg1.cpp
//  Øving 7
//
//  Created by Magnus Pedersen on 03.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "oppg1.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void toFile()
{
    ofstream fout;
    
    string temp;
    string s = "";
    
    fout.open("oppg1a.txt");
    if (fout.fail()) //sjekk om filen kan åpnes
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    else
    {
        while (cin >> temp)
        {
            if (temp.compare("quit")==0)
            {
                break; //avslutter programmet
            }
            s.append(temp).append("\n"); //\n lager ny linje i tekstfilen, append legger til på slutten
            fout << s;
            s.clear();
        }
    }
    fout.close();
}
void fromFile()
{
    string temp = "";
    string s;
    ifstream fin("oppg1a.txt"); //samme som open i toFile()
    ofstream fout("oppg1b.txt"); //Filen som nummereres
    if(fin.fail() || fout.fail())
    {
        cout << "File cannot be opened.\n";
        exit(1);
    }
    else
    {
        int i = 1;
        while (fin >> s)
        {
            fout << i << ". " << s << "\n";
            i++; //nummerer linjene
        }
    }
    fin.close();
    fout.close();
}