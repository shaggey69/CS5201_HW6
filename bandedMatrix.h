/*
# Banded Matrix class header
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 18.4.18
*/
#ifndef BANDEDMATRIX_H
#define BANDEDMATRIX_H
#include "matrix.h"
using namespace std;

template <typename T>
class bandedMatrix;

/*! Stream insertion operator for `bandedMatrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post The contents of the m_matrix are printed to the ouptut stream. Each
 * array is printed on a new row.
 * \return the modified output stream.
 *
 */
template<class T>
ostream& operator<< (ostream& out ,  bandedMatrix<T> & mat);
template<class T>
istream& operator>> (istream& in ,  bandedMatrix<T> & mat);

template <class T>
class bandedMatrix : public Matrix<T>
{ 
	private:
	 		MyArray<T> & operator[](const int i) const;
	 		//void switchRows (const int i, const int j) ; 
	public:
			bandedMatrix(const int size);
			bandedMatrix<T> & operator= (const bandedMatrix<T> & rhs) ;
			T operator()(const int i,const int j );
			Matrix<T> operator+(const Matrix<T> & rhs) const;
			Matrix<T> operator-(const Matrix<T> & rhs) const;
			Matrix<T> operator*(const Matrix<T> & rhs) const;
			MyArray<T> operator*(const MyArray<T> & rhs) const;
			void scalerMulti(const T scaler);
 			void setSize(const int size);
			bandedMatrix<T> transpose();
			void setMatrix(const int i ,const int j, const T x);
			friend ostream& operator<< <T> (ostream& out ,  bandedMatrix<T> & mat);
			friend istream& operator>> <T> (istream& in ,  bandedMatrix<T> & mat);

	
};




#include "bandedMatrix.hpp"
#endif