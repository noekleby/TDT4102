//
//  Vector.h
//  Øving 6
//
//  Created by Magnus Pedersen on 21.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_6__Vector__
#define ___ving_6__Vector__
#include "matrix.h"
#include <iostream>
class Matrix;
class Vector:public Matrix
{
public:
    Vector():Matrix(){}//lage konstruktør for vectoren
    Vector():Matrix()
    {
        for (int i = 0; i < cols; i++)
        {
            Vector(i) = set(0, 1);
        }
    }
    explicit Vector(unsigned int nRows);
    Vector(const Matrix & other);
    void set(unsigned int row, double value);
    double get(unsigned int row) const;
    
    double dot(const Vector &rhs) const;
    double lenghtSquared() const;
    double length() const;
};
#endif /* defined(___ving_6__Vector__) */
