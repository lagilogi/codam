#include "easyfind.hpp"

int main()
{
	std::vector<int> vector = { 1,2,3,4,5,6,7,8,9,1000 };
	std::deque<int> deque = { 1,2,3,4,5 };
	std::array<int, 5> array = { 10,11,12,13,14 };
	std::list<int> list = { 6,7,8,9,10 };

	// Vector
	try
	{
		auto result = easyfind(vector, 10);
		std::cout << "vector: " << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "vector: " << e.what() << '\n';
	}

	// Deque
	try
	{
		auto result = easyfind(deque, 10);
		std::cout << "deque: " << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "deque: " << e.what() << '\n';
	}

	// Array
	try
	{
		auto result = easyfind(array, 10);
		std::cout << "array: " << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "array: " << e.what() << '\n';
	}

	// List
	try
	{
		auto result = easyfind(list, 10);
		std::cout << "list: " << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "list: " << e.what() << '\n';
	}
	return (0);
}
