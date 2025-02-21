#include "Array.hpp"

/* Constructors & destructor */
template <class T>
Array<T>::Array() : _arraySize(0)
{
	// std::cout << "Array default constructor called" << std::endl;
	_array = nullptr;
}

template <class T>
Array<T>::Array(unsigned int n) : _arraySize(n)
{
	// std::cout << "Array 'unsigned int n' constructor called" << std::endl;
	_array = new T[n]();
}

template <class T>
Array<T>::~Array()
{
	// std::cout << "Array destructor called" << std::endl;
	if (_array != nullptr)
		delete[] _array;
}


/* Copy constructor & operator= */
template <class T>
Array<T>::Array(const Array& other) : _arraySize(other._arraySize)
{
	// std::cout << "Array copy constructor called" << std::endl;
	if (other._array == nullptr)
		this->_array = nullptr;
	else
		this->_array = new T[this->_arraySize];
	if (this->_array != nullptr)
		for (unsigned int i = 0; i < this->_arraySize; ++i)
			this->_array[i] = other._array[i];
}


template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
	// std::cout << "Array copy assignment= operator called" << std::endl;
	if (this == &other)
		return (*this);
	if (this->_array != nullptr)
		delete[] this->_array;
	if (other._array == nullptr)
		this->_array = nullptr;
	else
	{
		this->_arraySize = other._arraySize;
		this->_array = new T[this->_arraySize];
		for (unsigned int i = 0; i < this->_arraySize; ++i)
			this->_array[i] = other._array[i];
	}
	return (*this);
}


/* Assignment operators */
template <class T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _arraySize)
		throw (OutOfBoundsException());
	return (_array[index]);
}

/* Functions */
template <class T>
unsigned int Array<T>::size()
{
	return (this->_arraySize);
}


/* Exceptions */
template <class T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index going out of bounds");
}