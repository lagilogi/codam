#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <exception>

template<typename T>
typename T::iterator	easyfind(T data, int num)
{
	if (typeid(typename T::value_type) != typeid(int))
		throw std::runtime_error("Invalid datatype in container!")
	auto it = std::find(data.begin(), data.end(), num);
	if (*it == num)
		return (it);
	throw std::runtime_error("Num not found in data!");
}
