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

template <class T>
class diagMatrix : public Matrix<T>
{ 
	public:
		diagMatrix(const int size);
		Matrix<T> operator+(const Matrix<T> & rhs) const;
		Matrix<T> operator-(const Matrix<T> & rhs) const;
		diagMatrix<T> operator*(const diagMatrix<T> & rhs) const;
		Matrix<T>& operator= (const Matrix<T> & rhs) ;
		MyArray<T> & operator[](const int i) const;
		friend ostream& operator<< <T> (ostream& out ,  diagMatrix<T> & mat);
};




#include "diagMatrix.hpp"
#endif