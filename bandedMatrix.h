/*! \file
 *
 * the bandede matrix  class
 */
/*
/*
# Banded Matrix class header
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 4.18.18
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

/*! Stream insertion operator for `bandedMatrix`.
 *
 * \pre Stream insertion operator is defined for `T`.
 * \post the m_matrix if filled with the input
 * \return the modified input stream.
 *
 */
template<class T>
istream& operator>> (istream& in ,  bandedMatrix<T> & mat);

template <class T>
class bandedMatrix : public Matrix<T>
{ 
	private:

			/*! object getter []
		  *
		  * \pre 0 < i < size, will throw a
		  * a length Error otherwise
		  * \post none
		  * \return Will return the MyArray at index i.
		  */

	 		MyArray<T> & operator[](const int i) const;

	public:

			/*! initialize constructor.
		  * A new bandedMatrix is craeted with dimensions
		  * equel to "size"
		  * \pre size must be bigger then 0! Will throw a
		  * a length Error otherwise
		  * \post a bandedMatrix is born!
		 	*/

			bandedMatrix(const int size);

			/*! = assignment
		  * turns the CO bandedMatrix into RHS bandedMatrix
		  * \pre none
		  * \post none
		  */

			bandedMatrix<T> & operator= (const bandedMatrix<T> & rhs) ;

			/*! operaotr ()
			* returns value of m_matrix[i][j]
			* \pre 0 < i,j <size
			* \post none
			*/

			T operator()(const int i,const int j );

			/*! + operator
			* adds the sum of CO to rhs, retures a new Matrix 
			* with the calculated values
			* \pre size of CO must be equel to rhs, Will throw a
			* a length Error otherwise. "+" binary operator
			* must be defiend for T.
			* \post a matrix is born!
			*/

			Matrix<T> operator+(const Matrix<T> & rhs) const;

			/*! - operator
			* adds the sum of CO to rhs, retures a new Matrix 
			* with the calculated values
			* \pre size of CO must be equel to rhs, Will throw a
			* a length Error otherwise. "-" binary operator
			* must be defiend for T.
			* \post a matrix is born!
			*/

			Matrix<T> operator-(const Matrix<T> & rhs) const;

			/*! Matrix multiplication
			* caclualtes the multiplication of bandedMatrix and matrix, returens
			* a new matrix with the calculated values
			* \pre size of CO must be equel to rhs, Will throw a
			* a length Error otherwise. "*" binary operator
			* must be defiend for T.
			* \post a matrix is born!
			*/

			Matrix<T> operator*(const Matrix<T> & rhs) const;
		
			/*! Matrix - Vector  multiplication
		  * caclualtes the multiplication of a bandedMatrix with an Array
		  * and returens a new Vector with the calculated values
		  * \pre size of CO must be equel to rhs array size! Will throw a
		  * a length Error otherwise. "*" binary operator
		  * must be defiend for T.
		  * \post a Vector is born!
		  */

			MyArray<T> operator*(const MyArray<T> & rhs) const;

			/*! Matrix Scaler multiplication
		  * caclualtes the multiplication of a bandedMatrix with a scaler
		  * and modifies the CO m_matrix with calculation
		  * \pre "*" binary operator must be defiend for T.
		  * \post none
		  */

			void scalerMulti(const T scaler);

			/*! set size!
			*
			* \pre s must be postive
			* \post none
			*/

 			void setSize(const int size);

			/*! Matrix transpose calculator
			* Creates a new matrix with is a trasposed version of the CO
			* \pre none
			* \post a Matrix is born
			*/

			bandedMatrix<T> transpose();

	 		/*! Set Matrix
		  * changes the value of m_matrix[i][j] and m_matrix[j][i] to x
		  * \pre 0 < i,j <size
		  * \post modified m_matrix
		  */

			void setMatrix(const int i ,const int j, const T x);

			/*! Stream insertion operator for `bandedMatrix`.
			 *
			 * \pre Stream insertion operator is defined for `T`.
			 * \post The contents of the m_matrix are printed to the ouptut stream. Each
			 * array is printed on a new row.
			 * \return the modified output stream.
			 *
			 */
			friend ostream& operator<< <T> (ostream& out ,  bandedMatrix<T> & mat);

			/*! Stream insertion operator for `bandedMatrix`.
			 *
			 * \pre Stream insertion operator is defined for `T`.
			 * \post the m_matrix if filled with the input
			 * \return the modified input stream.
			 *
			 */

			friend istream& operator>> <T> (istream& in ,  bandedMatrix<T> & mat);

	
};


#include "bandedMatrix.hpp"
#endif