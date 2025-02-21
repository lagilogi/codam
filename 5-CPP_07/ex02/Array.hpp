#pragma once

#include <iostream>

template<class T>
class Array
{
	private:
		T* 				_array;
		unsigned int 	_arraySize;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);

		unsigned int size();

		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw() override;
		};
};

#include "Array.tpp"