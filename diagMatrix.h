#ifndef DIAGMATRIX_H
#define DIAGMATRIX_H


template <class T>
class diagMatrix : public Matrix
{
	diagMatrix(const int size);
	diagMatrix<T> operator+(const Matrix<T> & rhs) const;
	diagMatrix<T> operator-(const Matrix<T> & rhs) const;
	diagMatrix<T> operator*(const Matrix<T> & rhs) const;
};




#include "diagMatrix.hpp"
#endif