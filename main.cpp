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
#include "deepdec.h"


using namespace std;

int main(int argc, char *argv[])
{
	int dimNum = 0;
	symMatrix<double> mySymMatrix(dimNum);
	MyArray<double> my_array;
	MyArray<double> my_ans;
	deepDec<double> my_steep;
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

			my_ans = my_steep(mySymMatrix,my_array);
			cout << endl << my_ans <<endl;


		}
	}



	return 0;
}
