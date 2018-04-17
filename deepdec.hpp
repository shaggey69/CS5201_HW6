/*
header function for Bell Curve implmention
By: Ari Sherman
Class: CS5201 HW #4
Date: 3.12.18
*/
// operator ()
template <typename T>
MyArray<T> deepDec<T>::operator()(const symMatrix<T> a,const MyArray<T> f) const
{
	if (!a.isDiagDom())
		throw std::length_error("Matrix must be Diagonal Dominate!");
	
	MyArray<T> resi(a.getSize());
	MyArray<T> x (f);
	
	MyArray<T> temp = a*x;
	MyArray<T> temp3;
	T temp1 ;
	T temp2 ;


	resi = f - (temp);

	while (resi*resi > 0.00000001)
	{
		temp1 = resi*resi; 
		temp2 = a*resi*resi;
		T alfha =  temp1 / temp2;
		temp3 = resi*alfha;
		x = x + (temp3);
		temp = a*x;
		resi = f - (temp);
	} 
	return x;


}

