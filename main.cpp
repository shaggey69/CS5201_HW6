/*
# main function 
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 4.18.18
*/

#include <iostream>
#include <fstream>
#include "symMatrix.h"
#include "diagMatrix.h"
#include "bandedMatrix.h"
#include "myArray.h"

using namespace std;

int main(int argc, char *argv[])
{
	int dimNum = 0;
	Matrix<double> mySymMatrix(dimNum);
	MyArray<double> my_array;

	ifstream in;

	if (argc < 2)
    cout << endl << "not enough inputs :(" << endl ;
  else  if (argc > 2)    
    cout << endl << "too many inputs :(" << endl ;
  else
  {
  	in.open(argv[1]);
		argc = 0;
		if (!in) 
    	cout << endl << "invailed file :("  << endl;
		else
		{
			in >> dimNum;

			mySymMatrix.setSize(dimNum);
			in >> mySymMatrix;

			my_array.setSize(dimNum);
			for (int i = 0 ; i < dimNum ; i++)
				in >> my_array[i];



		}
	}



	return 0;
}
