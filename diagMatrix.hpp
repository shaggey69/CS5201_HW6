template <typename T>   
diagMatrix<T>::diagMatrix(const int size)
{
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	m_size = size;
	ptr_to_data = new T[m_size];
	for (int i = 0 ; i < m_size ; i++)
		for (int j = 0 ; j < m_size ; j++)
			if (i != j)
				m_matrix[i][j] = 0;
		
}

template <typename T>   
diagMatrix<T> diagMatrix<T>::operator+(const Matrix<T> & rhs)
{
	if (rhs.m_size != m_size) 
		throw std::length_error("matrix must be of equel length"); 

	diagMatrix<T> retVal(m_size);
	for (int i = 0 ; i < m_size ; i++)
		retVal[i][i]= m_matrix[i][i]+rhs.m_matrix[i][i];
	
	return retVal;
}

template <typename T>   
diagMatrix<T> diagMatrix<T>::operator-(const Matrix<T> & rhs)
{
	if (rhs.m_size != m_size) 
		throw std::length_error("matrix must be of equel length"); 

	diagMatrix<T> retVal(m_size);
	for (int i = 0 ; i < m_size ; i++)
		retVal[i][i]= m_matrix[i][i]-rhs.m_matrix[i][i];
	
	return retVal;
}

template <typename T>   
Matrix<T> Matrix<T>::operator*(const Matrix<T> & rhs) const
{
	if (rhs.m_size != m_size) 
		throw std::length_error("matrix must be of equel length"); 
	T sum = 0;
	Matrix<T> retVal(m_size);
	for (int i = 0 ; i < (m_size) ; i++)
		for (int j = 0 ; j < (m_size) ; j++)
		{ 
			for (int k = 0 ; k < (m_size) ; k++)
				sum += m_matrix[i][k]*rhs.m_matrix[k][j];
			retVal[i][j] = sum;
			sum = 0;
		}			
	return retVal;
}