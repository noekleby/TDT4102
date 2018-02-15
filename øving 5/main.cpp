//
//  main.cpp
//  øving 5
//
//  Created by Magnus Pedersen on 12.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "main.h"
#include <iostream>
//#include "curses.h"
using namespace std;
int main ()
{
    //system("color 18"); fungerer ikke i xcode
    //oppg. 1c
    /*Matrix2x2 c;
    c.set(0, 0, 2);
    cout << c.get(0, 0) << endl;
    c.print();*/
    
    //oppg 2c
    /*double a []={1,2,3,4}; double b [] = {4, 3, 2, 1}; double c []= {1.0, 3.0, 1.5, 2.0};
    Matrix2x2 A = Matrix2x2(a);
    Matrix2x2 B = Matrix2x2(b);
    Matrix2x2 C = Matrix2x2(c);
    A += B;
    A -= B;
    cout << B << endl;
    cout << A << endl;*/
    
    //oppg 2e
    /*double a []={1,2,3,4}; double b [] = {4, 3, 2, 1}; double c []= {1.0, 3.0, 1.5, 2.0};
    Matrix2x2 A = Matrix2x2(a);
    Matrix2x2 B = Matrix2x2(b);
    Matrix2x2 C = Matrix2x2(c);
    Matrix2x2 D = A + B;
    cout << (D*B-A+C) << endl;*/
    
    double vector[2];
    cout << "I. ax + by = p " << endl << "II. cx + dy = q " << endl;
    cout << "Vennligst fyll inn a,b,c,d, p og q. Trykk enter mellom hver inntasting: " << endl;
    double a,b,c,d;
    cin>> a >> b >> c >> d;
   
    for (int j=0;j<2;j++)
    {
        cin >> vector[j];
    }
    Matrix2x2 mat = Matrix2x2(a,b,c,d);
     cout << "A \n" << mat  <<endl;
    Matrix2x2 matinverse = mat.inverse();
    Vector2 vec = Vector2(vector[0], vector[1]);
    Vector2 losning = matinverse * vec;//løser for x,y
    cout << "A^-1\n" << matinverse << endl;
    cout << "B\n" << vec << endl;
    cout << "Løsning: " << endl << losning << endl;
    return 0;
}
