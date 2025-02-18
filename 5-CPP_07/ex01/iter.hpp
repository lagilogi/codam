#pragma once

#include <iostream>

template<typename T> ///////////// Dit is een generic template
void	printer(T value) ///////// Mag dit??????
{
	std::cout << "Value: " << value << std::endl;
}

template<typename T>
void	iter(T* array, int arrSize, void(*function)(T))
{
	for (int i = 0; i < arrSize; ++i)
	{
		function(array[i]);
	}
}
