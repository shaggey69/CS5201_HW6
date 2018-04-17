/*! \file
 *
 * the  class
 */
/*
header function for  Bell Curve class
By: Ari Sherman
Class: CS5201 HW #6
Date: 4.18.18
*/

#ifndef DEEPDEC_H
#define DEEPDEC_H
#include "myArray.h"
#include "symMatrix.h"
#include <stdexcept>


/*!
 * the Bell Curve calculation class
 *
*/
#include <cmath>

template <typename T>
class deepDec
{
	public:

	/*! Operator () calculator!
	* \s
  * \pre T must have the "*" binary operator defiend for it
  * \post none
  *	\return the bell curve value for given "Num"
  */
	MyArray<T> operator()(const symMatrix<T> mat,const MyArray<T> arr) const;
};

#include "deepdec.hpp"
#endif