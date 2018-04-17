/*
# Diagnoal Matrix class header
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 18.4.18
*/
#ifndef DIAGMATRIX_H
#define DIAGMATRIX_H
#include "matrix.h"
using namespace std;

template <typename T>
class diagMatrix;

/*! Stream insertion operator for `diagMatrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the m_matrix are printed to the ouptut stream. Each
 * array is printed on a new row.
 * \return the modified output stream.
 *
 */
template<class T>
ostream& operator<< (ostream& out ,  diagMatrix<T> & mat);
template<class T>
istream& operator>> (istream& in ,  diagMatrix<T> & mat);

template <class T>
class diagMatrix : public Matrix<T>
{ 
	private:
	 		MyArray<T> & operator[](const int i) const;
	public:
		diagMatrix(const int size);
		diagMatrix<T> & operator= (const diagMatrix<T> & rhs) ;
		Matrix<T> operator+(const Matrix<T> & rhs) const;
		Matrix<T> operator-(const Matrix<T> & rhs) const;
		Matrix<T> operator*(const Matrix<T> & rhs) const;
 		MyArray<T> operator*(const MyArray<T> & rhs) const;
 		void scalerMulti(const T scaler);
 		void setSize(const int size);
 		diagMatrix<T> transpose() ;
 		T operator()(const int i,const int j );
 		void setMatrix(const int i ,const int j, const T x);
		friend ostream& operator<< <T> (ostream& out ,  diagMatrix<T> & mat);
		friend istream& operator>> <T> (istream& in ,  diagMatrix<T> & mat);
		void switchRows (const int i, const int j) ; 

};




#include "diagMatrix.hpp"
#endif