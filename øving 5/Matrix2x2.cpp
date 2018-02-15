//
//  matriseklasse.cpp
//  øving 5
//
//  Created by Magnus Pedersen on 12.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "Matrix2x2.h"
#include <iostream>
using namespace std;
void Matrix2x2::set(int row, int col, double value)
{
    lagringsplass[row][col] = value;
}
double Matrix2x2::get(int row, int col) const
{
    return lagringsplass[row][col];
}
void Matrix2x2::print()
{
    for (int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout << lagringsplass[i][j] << " ";
        }
        cout << endl;
    }
}
double Matrix2x2::det()const
{
    return (this->get(0,0)*this->get(1,1)-this->get(0,1)*this->get(1,0));
}
Matrix2x2 Matrix2x2::inverse()//ta inn matrise og sett til de forskjellige verdiene
{
	if (this->det() == 0) //Hvis determinanten er 0 eksisterer ikke matrisen
    {
        return Matrix2x2(0,0,0,0); //returnerer nullmatrisen
	}
	double det = 1 / this->det();
	for (int i = 0; i < 2; i++)
    {
		for (int j = 0; j < 2; j++)
        {
			if ((i + j) == 0)
				this->set(1, 1, det*this->get(i, j));//bytter første plass i matrisen til siste plass
			else if ((i + j) == 2)
				this->set(0, 0, det*this->get(i, j));//bytter siste plass i matrisen til første plass
			else
				this->set(i, j, -det*this->get(i, j));
		}
	}
	return *this;
}
Matrix2x2::Matrix2x2()
{
	lagringsplass[0][0] = 1;
	lagringsplass[0][1] = 0;
	lagringsplass[1][0] = 0;
	lagringsplass[1][1] = 1;
}
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
    lagringsplass[0][0] = a;
	lagringsplass[0][1] = b;
	lagringsplass[1][0] = c;
	lagringsplass[1][1] = d;
}
ostream& operator <<(ostream& out,  const Matrix2x2 & lagringsplass) //tar inn const så ikke operanden endres
{
    cout << lagringsplass.get(0,0) << "\t";
    cout << lagringsplass.get(0,1) << "\t";
    cout << lagringsplass.get(1,0) << "\t";
    cout << lagringsplass.get(1,1) << "\t";
    return out;
}
Matrix2x2 Matrix2x2::operator+=(Matrix2x2& rhs)
{
    this->set(0, 1, this->get(0, 1) + rhs.get(0, 1));
    this->set(0, 0, this->get(0, 0) + rhs.get(0, 0));
    this->set(1, 0, this->get(1, 0) + rhs.get(1, 0));
    this->set(1, 1, this->get(1, 1) + rhs.get(1, 1));
    return *this;
}
Matrix2x2 Matrix2x2::operator-=(Matrix2x2& rhs)
{
    this->set(0, 1, this->get(0, 1) - rhs.get(0, 1));
    this->set(0, 0, this->get(0, 0) - rhs.get(0, 0));
    this->set(1, 0, this->get(1, 0) - rhs.get(1, 0));
    this->set(1, 1, this->get(1, 1) - rhs.get(1, 1));
    return *this;
}
Matrix2x2 Matrix2x2::operator+(Matrix2x2& rhs)
{
    *this += rhs;
    return *this;
}
Matrix2x2 Matrix2x2::operator-(Matrix2x2& rhs)
{
    *this -= rhs;
    return *this;
}
Matrix2x2 Matrix2x2::operator*(Matrix2x2& rhs)
{
    Matrix2x2 matrix1, matrix2;
    double value1, value2;
    for (int m = 0; m < 2; m++) //matrise
    {
        for (int r = 0; r < 2; r++) //rad
        {
            for (int k = 0; k < 2; k++) //kolonne
            {
                value1 = this->get(r, m);
                value2 = rhs.get(m, k);
                if (m != 0) //matrise 2
                    matrix1.set(r, k, value1 * value2);
                else //matrise 1
                    matrix2.set(r, k, value1 * value2);
            }
        }
    }
    return matrix1 + matrix2;
}
Vector2 Matrix2x2::operator*(const Vector2& vector) const
{
	/*Vector2 v;
    v.set(0, this->get(0, 0)*vector.get(0) + this->get(0, 1)*vector.get(1));//x
	v.set(1, this->get(1, 0)*vector.get(0) + this->get(1, 1)*vector.get(1));//y
	return v;*/
    double x = this->get(0, 0)*vector.get(0);
    x+= this->get(0, 1)*vector.get(1);
    double y = this->get(1, 0)*vector.get(0);
    y+= this->get(1, 1)*vector.get(1);
    return Vector2(x, y);
}
Matrix2x2 Matrix2x2::operator*=(Matrix2x2& rhs)
{
    *this = *this * rhs;
    return *this;
}
