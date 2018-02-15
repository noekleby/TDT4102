//
//  oppg5.cpp
//  oppg2
//
//  Created by Magnus Pedersen on 16.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "oppg5.h"
#include <iostream>
#include <cmath>
using namespace std;

//oppg. 5
double internalSum(double a,double b,double c)
{
    double root = b*b-4*a*c;
    return root;
}
double positiveSquareroot (double x)
{
    if (x>0 || x==0)
    {
        double root = (sqrt(x));
        return root;
    }
    else
    {
        return -1;
    }
}
double polyRoots (double a,double b,double c)
{
    return positiveSquareroot(internalSum(a, b, c));
}
void abcFormula(double a, double b, double c)
{
	if (internalSum(a, b, c) >= 0)
    {
		cout << "x = " << (-b + polyRoots(a, b, c)) / (2 * a) << endl;
		if (polyRoots(a, b, c) != 0)
        {
			cout << "x = " << (-b - polyRoots(a, b, c)) / (2 * a) << endl;
		}
	}
	else
    {
		cout << "Har ingen løsning." << endl;
	}
}
void solveAndPrintRoots ()
{
    double a,b,c;
    cout << "Skriv inn a,b og c: " << endl;
    cin>>a>>b>>c;
    abcFormula(a,b,c);
}
