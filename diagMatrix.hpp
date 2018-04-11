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
		retVal[i][i]= this ->m_matrix[0][i]+rhs.m_matrix[i][i];
	
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
		retVal[i][i]= this ->m_matrix[0][i]-rhs.m_matrix[i][i];
	
	return retVal;
}

template <typename T>   
MyArray<T> & diagMatrix<T>::operator[](const int i) const
{
	int theSize = this -> m_size;
	if (i < 0 || i >= theSize) 
		throw std::length_error("i must be 0 < i < size");
	return this ->m_matrix[0];
}


template <typename T>   
diagMatrix<T> diagMatrix<T>::operator*(const diagMatrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length");

	diagMatrix<T> retVal(theSize);
		for (int i = 0 ; i < theSize ; i++)
			retVal[0][i] = this ->m_matrix[0][i]*rhs.m_matrix[0][i];

	return retVal;
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
