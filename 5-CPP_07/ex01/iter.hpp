#pragma once

#include <iostream>

template<typename T>
void	printer(T value)
{
	std::cout << "Value: " << value << std::endl;
}

template<typename T, typename F>
void	iter(T* array, int arrSize, F function)
{
	for (int i = 0; i < arrSize; ++i)
	{
		function(array[i]);
	}
}
