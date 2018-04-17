/*
# Symmetric Matrix class header
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 18.4.18
*/
#ifndef SYMMATRIC_H
#define SYMMATRIC_H
#include "matrix.h"
using namespace std;

template <typename T>
class symMatrix;

/*! Stream insertion operator for `diagMatrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the m_matrix are printed to the ouptut stream. Each
 * array is printed on a new row.
 * \return the modified output stream.
 *
 */
template<class T>
ostream& operator<< (ostream& out ,  symMatrix<T> & mat);
template<class T>
istream& operator>> (istream& in ,  symMatrix<T> & mat);

template <class T>
class symMatrix : public Matrix<T>
{ 	
	private:
		MyArray<T> & operator[](const int i) const;
	public:

		symMatrix(const int size);
		symMatrix<T> & operator= (const symMatrix<T> & rhs) ;
		Matrix<T> operator+(const Matrix<T> & rhs) const;
		Matrix<T> operator-(const Matrix<T> & rhs) const;
		Matrix<T> operator*(const Matrix<T> & rhs) const;
		MyArray<T> operator*(const MyArray<T> & rhs) const;
		void scalerMulti(const T scaler);
		void setSize(const int size);
		symMatrix<T> transpose() ;
		void setMatrix(const int i ,const int j, const T x);
		void switchRows (const int i, const int j) ; 
		T operator()(const int i,const int j ) const;
		bool isDiagDom() const ;
		friend ostream& operator<< <T> (ostream& out ,  symMatrix<T> & mat);
		friend istream& operator>> <T> (istream& in ,  symMatrix<T> & mat);

};

#include "symMatrix.hpp"
#endif