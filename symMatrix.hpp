/*
# Symmatric Matrix function implments 
# By: Ari Sherman
# Class: CS5201 HW #6
# Date: 4.18.18
*/
template <typename T>   
symMatrix<T>::symMatrix(const int size)
{
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	this -> m_size =size;

	if (size/2 == 0)
		int actuelSize = size/2;
	else
		actuelSize = size/2+1;

	this -> m_matrix.setSize(actuelSize);
	for (int i = 0 ; i < actuelSize ; i++)
	{
		m_matrix[i].setSize(size);
	}
}


template <typename T>   
diagMatrix<T> & diagMatrix<T>::operator= (const diagMatrix<T> & rhs) 
{
	this -> clear();
	this -> m_size = rhs.getSize();
	for (int i = 0 ; i < rhs.getSize()/2 ; i++)
		for (int j = 0 ; j < rhs.getSize()/2 ; j++)
		{}
	return *this;
}

/*
template <typename T>   
diagMatrix<T> diagMatrix<T>::operator+(const diagMatrix<T> & rhs) const
{
	cout << "all good" << endl;
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	diagMatrix<T> retVal(theSize);

	for (int i = 0 ; i < theSize ; i++)
		retVal[0][i] = this ->m_matrix[0][i]+rhs.m_matrix[0][i];
	
	return retVal;
}

template <typename T>   
diagMatrix<T> diagMatrix<T>::operator-(const diagMatrix<T> & rhs) const
{
	int theSize = this -> m_size;
	if (rhs.getSize() != theSize) 
		throw std::length_error("matrix must be of equel length"); 

	diagMatrix<T> retVal(theSize);
	for (int i = 0 ; i < theSize ; i++)
		retVal[0][i] = this ->m_matrix[0][i]-rhs.m_matrix[0][i];
	
	return retVal;
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
MyArray<T> diagMatrix<T>::operator*(const MyArray<T> & rhs) const
{
	int theSize = this -> m_size;
	MyArray<T> retVal(theSize);
	for (int i = 0 ; i < theSize ; i++)
		retVal[i] = this->m_matrix[0][i] * rhs[i] ;

	return retVal;
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
	int theSize = this -> m_size;
	if (i < 0 || i >= theSize) 
		throw std::length_error("i must be 0 < i < size");
	return this ->m_matrix[0];
}



template <typename T>   
void diagMatrix<T>::setSize(const int size)
{
	this -> m_matrix[0].setSize(size);
	return;
}

template <typename T>   
diagMatrix<T> diagMatrix<T>::transpose() 
{
	cout << "in?" << endl;
	int theSize = this -> m_size;
	diagMatrix<T> retVal(theSize);
	for (int i = 0 ; i < theSize ; i++)
		retVal[0][i] = this->m_matrix[0][theSize-i-1] ;
	return retVal;

}


template <typename T>   
void diagMatrix<T>::switchRows (const int i, const int j) 
{
	if (i < 0 || i >=this-> m_size || j < 0 || j >=this-> m_size )
		throw std::length_error("matrix must be of equel length"); 
	T temp;
	temp = this->m_matrix[0][i];
	this->m_matrix[0][i] = this->m_matrix [0][j];
	this->m_matrix[0][j] =temp;
	return;
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
*/