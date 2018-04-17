/*
# Banded Matrix function implments 
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 4.18.18
*/
template <typename T>   
bandedMatrix<T>::bandedMatrix(const int size)
{
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	this -> m_size =size;
	this -> m_matrix.setSize(3);
	this -> m_matrix[0].setSize(size); //down
	this -> m_matrix[1].setSize(size); //middle
	this -> m_matrix[2].setSize(size); //up
}

template <typename T>   
bandedMatrix<T> & bandedMatrix<T>::operator= (const bandedMatrix<T> & rhs) 
{
	this -> clear();
	this -> m_size = rhs.getSize();

	for (int i = 0 ; i < rhs.getSize()-1 ; i++)
	{
		this->m_matrix[0][i] = rhs[0][i];
		this->m_matrix[1][i] = rhs[1][i];
		this->m_matrix[2][i] = rhs[2][i];
	}
		this -> m_matrix[1][rhs.getSize()-1]= rhs[1][rhs.getSize()-1];
	return *this;
}

template <typename T>   
Matrix<T> bandedMatrix<T>::operator+(const Matrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(rhs);

	retVal[0][0]+=this -> m_matrix[1][0];
	retVal[0][1]+=this -> m_matrix[2][0];

	for (int i = 1 ; i < rhs.getSize()-1 ; i++)
	{
		retVal[i][i]+= this -> m_matrix[1][i];
		retVal[i][i-1]+= this -> m_matrix[0][i];
		retVal[i][i+1]+= this -> m_matrix[2][i];
	}

 	retVal[rhs.getSize()-1][rhs.getSize()-1] += 
 	this -> m_matrix[1][rhs.getSize()-1];
	retVal[rhs.getSize()-1][rhs.getSize()-2] += 
	this -> m_matrix[0][rhs.getSize()-1];
	return retVal;
}

template <typename T>   
Matrix<T> bandedMatrix<T>::operator-(const Matrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(rhs);

	retVal[0][0] = this -> m_matrix[1][0]-retVal[0][0];
	retVal[0][1] = this -> m_matrix[2][0]-retVal[0][1];

	for (int i = 1 ; i < rhs.getSize()-1 ; i++)
	{
		retVal[i][i] = this -> m_matrix[1][i]-retVal[i][i];
		retVal[i][i-1] = this -> m_matrix[0][i]-retVal[i][i-1];
		retVal[i][i+1] = this -> m_matrix[2][i]-retVal[i][i+1];
	}

 	retVal[rhs.getSize()-1][rhs.getSize()-1] =
 	this -> m_matrix[1][rhs.getSize()-1] -
 	retVal[rhs.getSize()-1][rhs.getSize()-1];

	retVal[rhs.getSize()-1][rhs.getSize()-2] = 
	this -> m_matrix[0][rhs.getSize()-1] - 
	retVal[rhs.getSize()-1][rhs.getSize()-2];
	return retVal;
}

template <typename T>   
Matrix<T> bandedMatrix<T>::operator*(const Matrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 
	T sum = 0;

	Matrix<T> retVal(theSize);

	for (int k = 0 ; k < theSize ; k++)
	{
		sum = this ->m_matrix[1][0] * rhs(0,k);
		sum += this ->m_matrix[2][0] * rhs(1,k);
		retVal[0][k] = sum;
		sum = 0;
	}

	for (int i = 1 ; i < theSize-1 ; i++)
		for (int j = 0 ; j < theSize ; j++)
		{ 
				sum = this ->m_matrix[0][i]*rhs(i-1,j);
				sum += this ->m_matrix[1][i]*rhs(i,j);
				sum += this ->m_matrix[2][i]*rhs(i+1,j);
			retVal[i][j] = sum;
			sum = 0;
		}	

	for (int k = 0 ; k < theSize ; k++)
	{
		sum = this ->m_matrix[0][theSize-1] * rhs(theSize-2,k);
		sum += this ->m_matrix[1][theSize-1] * rhs(theSize-1,k);
		retVal[theSize-1][k] = sum;
		sum = 0;
	}

	return retVal;
}

template <typename T>   
MyArray<T> bandedMatrix<T>::operator*(const MyArray<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 
	T sum = 0;

	MyArray<T> retVal(theSize);

	sum = this ->m_matrix[1][0] * rhs[0];
	sum += this ->m_matrix[2][0] * rhs[1];
	retVal[0] = sum;
	sum = 0;
	
	for (int i = 1 ; i < theSize-1 ; i++)
		{ 
				sum = this ->m_matrix[0][i]*rhs[i-1];
				sum += this ->m_matrix[1][i]*rhs[i];
				sum += this ->m_matrix[2][i]*rhs[i+1];
			retVal[i] = sum;
			sum = 0;
		}	


	sum = this ->m_matrix[0][theSize-1] * rhs[theSize-2];
	sum += this ->m_matrix[1][theSize-1] * rhs[theSize-1];
	retVal[theSize-1] = sum;

	return retVal;
}

template <typename T>   
void bandedMatrix<T>::scalerMulti(const T scaler)
{
	int theSize = this -> m_size;
	for (int i = 1 ; i < theSize-1 ; i++)
	{
		this -> m_matrix[0][i] *= scaler;
		this -> m_matrix[1][i] *= scaler;
		this -> m_matrix[2][i] *= scaler; 

	}
	this -> m_matrix[1][0]*= scaler;
	this -> m_matrix[2][0]*= scaler;

	this -> m_matrix[1][theSize-1]*= scaler;
	this -> m_matrix[0][theSize-1]*= scaler;

	return;
}

template <typename T>   
void bandedMatrix<T>::setSize(const int size)
{
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	this -> clear();
	this -> m_size =size;
	this -> m_matrix.setSize(3);
	this -> m_matrix[0].setSize(size); //down
	this -> m_matrix[1].setSize(size); //middle
	this -> m_matrix[2].setSize(size); //up

	return;
}

template <typename T>   
bandedMatrix<T> bandedMatrix<T>::transpose()
{
	bandedMatrix<T> retVal(*this);

	return retVal;
}

template <typename T>   
void bandedMatrix<T>::setMatrix(const int i ,const int j, const T x)
{
	if (i < 0 || i >=this-> m_size || j < 0 || j >=this-> m_size )
		throw std::length_error("i,j must be 0 < i,j < size"); 
	if ((i >j+1 || j>i+1) && x!=0)
		throw std::invalid_argument
	("can not change value to non zero at place in Banded Matrix");
	else if (i == j)
		this -> m_matrix[1][i] = x;
	else if (i == j+1)
		this -> m_matrix[2][i] = x;
	else
		this -> m_matrix[0][j] = x;
	return;
}


template <typename T>   
MyArray<T> & bandedMatrix<T>::operator[](const int i) const
{
	if (i < 0 || i >= this -> m_size) 
		throw std::length_error("i must be 0 < i <size"); 	
	return this -> m_matrix[i];
}

template <typename T>   
ostream& operator<<(ostream& out ,  bandedMatrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
	{
		for (int j = 0 ; j < mat.m_size ; j++)
		{
			if ( i == j )
				out << mat.m_matrix[1][i] << " ";
			else if (i == j+1)
				out << mat.m_matrix[2][i] << " ";
			else if (j == i+1)
				out << mat.m_matrix[0][j] << " ";
			else
				out << "0 " ;
		}
		out << endl;
	}

	return out;
}

template <typename T>   
istream& operator>>(istream& in ,  bandedMatrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
	{
		if (i == 0)
		{
			in >> mat.m_matrix[1][0];
			in >> mat.m_matrix[2][0];
		}
		else if (i == mat.m_size-1)
		{
			in >> mat.m_matrix[0][i];
			in >> mat.m_matrix[1][i];
		}
		else
		{
			in >> mat.m_matrix[0][i];
			in >> mat.m_matrix[1][i];
			in >> mat.m_matrix[2][i];
		}
	}
	return in;
}