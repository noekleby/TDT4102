//
//  main.cpp
//  Øving 7
//
//  Created by Magnus Pedersen on 03.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "main.h"
#include <cstring>
using namespace std;
int main ()
{
    //toFile();
    //fromFile();
    //tegnstatistikk();
    //ordstatistikk();
    Substitution game("plaintext.txt");
    game.play();
    //cout << game.plaintext << endl;
    //cout << game.ciphertext << endl;
    return 0;
}