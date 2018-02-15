//
//  matrix.cpp
//  Øving 6
//
//  Created by Magnus Pedersen on 20.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//
#include <iostream>
#include "matrix.h"
using namespace std;
void Matrix::MatrixAllocater() //allokerer minne
{
    matrix = new double * [row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new double [col];
    }
}
Matrix::~Matrix() //destruktøren
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete [] matrix;
    matrix = nullptr;
}
void Matrix::set(int row, int col, double value)
{
    this->matrix[row][col] = value;
}
double Matrix::get(int row, int col)const
{
    return (this->matrix[row][col]);
}
Matrix::Matrix(unsigned int nRows) //explicit
{
    MatrixAllocater();
    row = nRows;
    col = nRows;
    for (int i = 0; i < nRows; i++)
    {
        set(i,i,1); //identitetsmatrisen konstrueres
    }
}
Matrix::Matrix(unsigned int nRows, unsigned int nCols)
{
    this->row = nRows;
	this->col = nCols;
    MatrixAllocater();
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
Matrix Matrix::operator*(const Matrix &rhs)
{
    if (col != rhs.row || !this->isValid() || !rhs.isValid())
    {
        Matrix m(row,col);
        return m;
    }
    else if (this->col == rhs.row)
	{
		Matrix m(this->row, rhs.col);
        
		for (int i = 0; i<m.row; i++)
		{
			for (int j = 0; j<m.col; j++)
			{
				for (int k = 0; k<this->col; k++)
				{
					m.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
				}
			}
		}
		return m;
	}
	return *this;
}
Matrix Matrix::operator*=(const Matrix& rhs)
{
    Matrix newone = *this = *this * rhs;
    return newone;
}
Matrix Matrix::operator+(const Matrix& rhs)
{
    Matrix newone = *this;
    
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			newone.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
		}
	}
	return newone;

}
Matrix Matrix::operator-(const Matrix& rhs)
{
    Matrix newone = *this;
    
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			newone.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
		}
	}
	return newone;
}
Matrix Matrix::operator+=(const Matrix& rhs)
{
    if (this->row == rhs.row && this->col == rhs.col)
    {
        for (int i = 1; i <= this->row; i++)
        {
            for (int j = 1; j <= this->col; j++)
            {
                this->set(i, j, this->get(i, j) + rhs.get(i, j));
            }
        }
    }
    else
    {
        cout << "Udefinert matriseaddisjon.";
    }
    return *this;
}
Matrix Matrix::operator-=(const Matrix& rhs)
{
    if (this->row == rhs.row && this->col == rhs.col)
    {
        for (int i = 1; i <= this->row; i++)
        {
            for (int j = 1; j <= this->col; j++)
            {
                this->set(i, j, this->get(i, j) - rhs.get(i, j));
            }
        }
    }
    else
    {
        cout << "Udefinert matrisesubstraksjon.";
    }
    return *this;
}
/*Matrix Matrix::operator=(const Matrix &rhs)
{
    swap(col, rhs.col);
    swap(row, rhs.row);
    swap(matrix, rhs.matrix);
    return *this;
}*/
Matrix Matrix::operator=(const Matrix &rhs)
{
    if (this == &rhs)
	{
		return *this;
	}
	else
	{
		if (this->row != rhs.row || this->col != rhs.col)
		{
			this->~Matrix();
			this->row = rhs.row;
			this->col = rhs.col;
			this->MatrixAllocater();
		}
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				this->matrix[i][j] = rhs.matrix[i][j];
			}
		}
		return *this;
	}
}
bool Matrix::isValid() const//hvis matrix=nullptr så er bool = true
{
    if (matrix==nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/*Matrix::Matrix(const Matrix& rhs): row(rhs.row), col(rhs.col)//kopikonstruktøren med intialiseringsliste
{
    if (!rhs.isValid())
    {
        matrix = nullptr;
    }
    else
    {
        matrix = new double*[row*col];
        for (int i = 0; i < (row*col); i++)
        {
            matrix[i] = rhs.matrix[i];
        }
    }
}*/
Matrix::Matrix(const Matrix &rhs)//kopikonstruktør
{
	this->row = rhs.row;
	this->col = rhs.col;
	MatrixAllocater();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->matrix[i][j] = rhs.matrix[i][j];
		}
	}
}
ostream& operator<<(ostream& os, Matrix& matrix)
{
    int nRows = matrix.row;
    int nCols = matrix.col;
    if (matrix.isValid())
    {
        for (int row = 0; row < nRows; row++)
        {
            for (int col = 0; col < nCols; col++)
            {
                os << matrix.get(row, col) << "\t";
            }
            os << endl;
        }
    }
	return os;
}
Matrix::Matrix(double index1, double index2, double index3, double index4)
{
	row = 2;
	col = 2;
	matrix = new double*[2];
	for (int i = 0; i < 2; i++)
	{
		matrix[i] = new double[2];
	}
    
	this->matrix[0][0] = index1;
    
	this->matrix[0][1] = index2;
    
	this->matrix[1][0] = index3;
    
	this->matrix[1][1] = index4;
}