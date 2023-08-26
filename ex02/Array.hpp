#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750

template <class T>

class Array
{
	T*				_arr;
	unsigned int	_n;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator = (const Array& other);
	~Array();

	T				&operator[](unsigned int index) const;
	unsigned int	size() const;

	class OutOfBoundsException : public std::exception
	{
		const char	*what() const throw();
	};
	
};

#include "./Array.tpp"

#endif