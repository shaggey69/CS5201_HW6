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

template <class T>
class symMatrix : public Matrix<T>
{ 
	public:

		symMatrix(const int size);
		symMatrix<T> & operator= (const symMatrix<T> & rhs) ;

		/*
		diagMatrix<T> operator+(const diagMatrix<T> & rhs) const;
		diagMatrix<T> operator-(const diagMatrix<T> & rhs) const;
		diagMatrix<T> operator*(const diagMatrix<T> & rhs) const;
 		MyArray<T> operator*(const MyArray<T> & rhs) const;
 		void scalerMulti(const T scaler);
 		void setSize(const int size);
 		diagMatrix<T> transpose() ;
		friend ostream& operator<< <T> (ostream& out ,  diagMatrix<T> & mat);
		MyArray<T> & operator[](const int i) const;
		void switchRows (const int i, const int j) ; 
		*/

};




#include "symMatrix.hpp"
#endif