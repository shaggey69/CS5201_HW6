#include <iostream>
#include <fstream>
#include "diagMatrix.h"

using namespace std;

int main()
{
	diagMatrix<int> diagTest(5);
	diagTest[0][0] = 1;
	diagTest[1][1] = 2;
	diagTest[2][2] = 3;
	diagTest[3][3] = 4;
	diagTest[4][4] = 5;
	cout << diagTest;

	return 0;
}







/*
int main(int argc, char *argv[])
{
	int dimNum = 0;
	Matrix< double> my_matrix;
	Matrix< double> my_tranMatrix;
	MyArray< double> my_arary, answears_array, answears_array2;
	Gauss< double> my_gauss;
	double temp = 0;
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
			my_matrix.setSize(dimNum);
			for (int i = 0 ; i < dimNum ; i++)
				for (int j = 0 ; j < dimNum ; j++)
				{
					in >> temp;
					my_matrix[i][j] = temp;
				}

			my_arary.setSize(dimNum);
			for (int i = 0 ; i < dimNum ; i++)
			{
				in >> temp;
				my_arary[i] = temp;
			}
	
			answears_array.setSize(dimNum);
			answears_array2.setSize(dimNum);
			my_tranMatrix.setSize(dimNum);

			answears_array = my_gauss(my_matrix,my_arary);
			my_tranMatrix = my_matrix * my_matrix.transpose();
			answears_array2 = my_matrix*answears_array;


			//output
			cout << setprecision(8);
			cout << my_tranMatrix << endl;
			cout << answears_array<< endl;
			cout << answears_array2;

		}
	}
	return 0;
}
*/