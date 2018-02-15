//
//  matriseklasse.h
//  øving 5
//
//  Created by Magnus Pedersen on 12.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_5__matriseklasse__
#define ___ving_5__matriseklasse__

#include <iostream>
#include "Vector2.h"
using namespace std;
class Vector2;
class Matrix2x2
{
private:
    double lagringsplass[2][2];
public:
    Matrix2x2();
    Matrix2x2(double a, double b, double c, double d);
    void set(int row, int col, double value);
    void print();
    double get(int row, int col)const;
    Matrix2x2 operator+=(Matrix2x2& rhs);
    Matrix2x2 operator-=(Matrix2x2& rhs);
    Matrix2x2 operator+(Matrix2x2& rhs);
    Matrix2x2 operator-(Matrix2x2& rhs);
    double det() const;
    Matrix2x2 inverse();
    Matrix2x2 operator*(Matrix2x2& rhs);
    Matrix2x2 operator*=(Matrix2x2& rhs);
    Vector2 operator*(const Vector2& vector) const;
};
std::ostream& operator<<(std::ostream& out, const Matrix2x2 & lagringsplass);
#endif /* defined(___ving_5__matriseklasse__) */
