/*
# Diagnoal Matrix function implments 
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 4.18.18
*/
template <typename T>   
diagMatrix<T>::diagMatrix(const int size)
{
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	this -> m_size =size;
	this -> m_matrix.setSize(1);
	this -> m_matrix[0].setSize(size);		
}

template <typename T>   
Matrix<T> diagMatrix<T>::operator+(const Matrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(rhs);

	for (int i = 0 ; i < theSize ; i++)
		retVal[i][i] = this ->m_matrix[0][i]+rhs.getMatrix()[i][i];
	
	return retVal;
}

template <typename T>   
Matrix<T> diagMatrix<T>::operator-(const Matrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(rhs);

	for (int i = 0 ; i < theSize ; i++)
		retVal[i][i] = this ->m_matrix[0][i]-rhs.getMatrix()[i][i];
	
	return retVal;
}

template <typename T>   
Matrix<T> diagMatrix<T>::operator*(const Matrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	Matrix<T> retVal(rhs);

	for (int i = 0 ; i < theSize ; i++)
		retVal[i][i] = this ->m_matrix[0][i]*rhs.getMatrix()[i][i];
	
	return retVal;
}


template <typename T>   
MyArray<T> diagMatrix<T>::operator*(const MyArray<T> & rhs) const
{
	int theSize = this -> m_size;
	MyArray<T> retVal(theSize);
	for (int i = 0 ; i < theSize ; i++)
		retVal[i] = this->m_matrix[0][i] * rhs[i] ;

	return retVal;
}



template <typename T>   
diagMatrix<T> & diagMatrix<T>::operator= (const diagMatrix<T> & rhs) 
{
	this -> clear();
	this -> m_size = rhs.getSize();
	for (int i = 0 ; i < rhs.getSize() ; i++)
		this->m_matrix[0][i]=rhs.m_matrix[0][i];
	return *this;
}

template <typename T>   
void  diagMatrix<T>::scalerMulti(const T scaler)
{
	int theSize = this -> m_size;
	for (int i = 0 ; i < theSize ; i++)
		this->m_matrix[0][i] = this->m_matrix[0][i] * scaler ;
	return;
}


template <typename T>   
MyArray<T> & diagMatrix<T>::operator[](const int i) const
{
	if (i < 0 || i >= this -> m_size) 
		throw std::length_error("i must be 0 < i <size"); 	
	return this -> m_matrix[0];
}



template <typename T>   
void diagMatrix<T>::setSize(const int size)
{
	this -> clear();
	this -> m_matrix[0].setSize(size);
	return;
}

template <typename T>   
diagMatrix<T> diagMatrix<T>::transpose() 
{
	
	diagMatrix<T> retVal(*this);

	return retVal;

}


template <typename T>   
T diagMatrix<T>::operator()(const int i,const int j)
{
	if (i != j )
		return 0;
	return this->m_matrix[0][i];
}


template <typename T>   
void diagMatrix<T>::switchRows (const int i, const int j) 
{
	if (i < 0 || i >=this-> m_size || j < 0 || j >=this-> m_size )
		throw std::length_error("i,j must be 0 < i,j < size"); 
	T temp;
	temp = this->m_matrix[0][i];
	this->m_matrix[0][i] = this->m_matrix [0][j];
	this->m_matrix[0][j] =temp;
	return;
} 

template <typename T>   
void diagMatrix<T>::setMatrix(const int i ,const int j, const T x)
{
	if (i < 0 || i >=this-> m_size || j < 0 || j >=this-> m_size )
		throw std::length_error("i,j must be 0 < i,j < size"); 
	if (i == j)
		this->m_matrix[0][i] = x;
	else if (x != 0)
		throw std::length_error("Diagonial matrix must have value zero for i !=j "); 
}


template <typename T>   
ostream& operator<<(ostream& out ,  diagMatrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
	{
		for (int j = 0 ; j < mat.m_size ; j++)
		{
			if ( i!=j )
				out << "0 ";
			else
				out << mat.m_matrix[0][i] << " ";
		}
		out << endl;
	}
	return out;
}

template <typename T>   
istream& operator>>(istream& in ,  diagMatrix<T> & mat)
{
	for (int i = 0 ; i < mat.m_size ; i++)
		in >> mat.m_matrix[0][i];
	return in;
}
