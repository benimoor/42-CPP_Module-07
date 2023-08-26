template <class T>
Array<T>::Array() : _n(0), _arr(new T[0]) {}

template <class T>
Array<T>::Array(unsigned int n)
{
	_n = n;
	_arr = new T[n];	
}

template <class T>
Array<T>::Array(const Array& other) : _n(other._n)
{
	_arr = new T[_n];

	for (unsigned int i = 0; i < _n; i++)
		_arr[i] = other._arr[i];	
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_n = other._n;
		delete [] _arr;
		_arr = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <class T>
Array<T>::~Array() { delete [] _arr; }

template <class T>
T&	Array<T>::operator[](unsigned int index) const
{
	if (index > _n)
		throw Array<T>::OutOfBoundsException();
	return *(_arr + index);
}

template <class T>
unsigned int	Array<T>::size() const { return _n; }

template <class T>
const char	*Array<T>::OutOfBoundsException::what() const throw() { return "Index is out of bounds!"; }