//
//  Vector2.h
//  øving 5
//
//  Created by Magnus Pedersen on 12.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_5__Vector2__
#define ___ving_5__Vector2__

#include <iostream>
#include "Matrix2x2.h"
class Matrix2x2;
class Vector2
{
private:
    double vec[2];
public:
    Vector2();
    Vector2(double x, double y);
    void set(int index, double value);
    double get(int index)const;
    double dot(const Vector2 &rightHandSide) const;
    double lengthSquared() const;
    double length() const;
    //Vector2 operator*(Matrix2x2& matrise);
};
std::ostream& operator<<(std::ostream& out, const Vector2 & vec);
#endif /* defined(___ving_5__Vector2__) */
