//
//  Vector.cpp
//  Øving 6
//
//  Created by Magnus Pedersen on 21.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "Vector.h"
#include <cmath>
using namespace std;
Vector::Vector(unsigned int nRows)//"identitetsmatrisen" til vektoren, e1
{
    Matrix(nRows,1);
    this->Matrix::set(0, 0, 1);
}
Vector::Vector(const Matrix & other) //konverteringskonstruktør for matrix
{
        if (Matrix::getColumns()!=1)//vil at antall kolonner i en vector er 1
        {
            Matrix::invalidate();
        }
}
void Vector::set(unsigned int row, double value)
{
    this->Matrix::set(row, 0, value);
}
double Vector::get(unsigned int row) const
{
    return (this->Matrix::get(row, 0));
}
double Vector::dot(const Vector &rhs) const
{
    double result = 0;
    if (this->getRows() == rhs.getRows())
    {
        for (int i = 0; i < Matrix::getRows(); i++)
        {
            result += this->Matrix::get(i, 0)*rhs.Matrix::get(i, 0);
        }
    }
    else
    {
        return nan("");
    }
    return result;
}
double Vector::lenghtSquared() const
{
    return this->dot(*this);
}
double Vector::length() const
{
    return sqrt(this->lenghtSquared());
}