//
//  matrix.h
//  Øving 6
//
//  Created by Magnus Pedersen on 20.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_6__matrix__
#define ___ving_6__matrix__

#include <iostream>
using namespace std;
class Matrix
{
private:
    double **matrix = nullptr;
    unsigned int row = 0;
    unsigned int col = 0;
    bool valid = true;
public:
    Matrix();
    ~Matrix();
    void MatrixAllocater();
    //Matrix(int nRows, int nCols);
    void set(int row, int col, double value);
    double get(int row, int col)const;
    explicit Matrix(unsigned int nRows);
    Matrix(unsigned int nRows, unsigned int nCols);
    bool isValid()const;
    Matrix(const Matrix &rhs);
    
    Matrix operator+=(const Matrix& rhs);//Bruk matrix& neste gang så referanse returneres, ellers vil ikke vector.cpp virke(?)
    Matrix operator=(const Matrix& rhs);
    Matrix operator-=(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs);
    Matrix operator*(const Matrix& rhs);
    Matrix operator*=(const Matrix& rhs);
    
    friend ostream& operator<<(ostream& os, Matrix& rhs);
    Matrix(double index1, double index2,double index3,double index4);
    
    //Til vectorklassen:
    int getRows() const{return (this->row);};
    void invalidate() {valid = false;};
    int getColumns() const{return (this->col);};
};
#endif /* defined(___ving_6__matrix__) */
