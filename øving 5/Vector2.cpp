//
//  Vector2.cpp
//  øving 5
//
//  Created by Magnus Pedersen on 12.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "Vector2.h"
#include <iostream>
#include <cmath>
using namespace std;
void Vector2::set(int index, double value)
{
    vec[index]= value;
}
double Vector2::get(int index)const
{
    return vec[index];
}
double Vector2::dot(const Vector2 &rightHandSide) const
{
    return (this->get(0)*rightHandSide.get(0)) + (this->get(1)*rightHandSide.get(1));
}
double Vector2::lengthSquared() const
{
    return this->dot(*this);    //multipliserer vektoren med seg selv
}
double Vector2::length() const
{
    return sqrt(this->lengthSquared());
}
Vector2::Vector2(double x, double y)
{
    vec[0]=x;
    vec[1]=y;
}
/*Vector2 Vector2::operator*(Matrix2x2& matrise)
{
    Vector2 produkt;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; i < 2; j++)
        {
            produkt.set(i, produkt.get(i)+(this->get(i)*matrise.get(i, j)));
        }
    }
    return produkt;
}*/
ostream& operator <<(ostream& out, const Vector2 & vec)
{
    cout << vec.get(0) << " | " << vec.get(1) << endl;
    return out;
}
/*Vector2 Vector2::operator*(Matrix2x2& matrise)
{
	Vector2 v;
    v.set(0, this->get(0)*matrise.get(0,0) + this->get(0)*matrise.get(0,1));
	v.set(1, this->get(1)*matrise.get(1,0) + this->get(1)*matrise.get(1,1));
	return v;
}*/
