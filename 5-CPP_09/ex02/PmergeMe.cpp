#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char* input) : _input(input) {}

PmergeMe::~PmergeMe() {}


void	PmergeMe::checkInput()
{
	for (char c : _input)
	{
		if (c != ' ' && !std::isdigit(c))
			throw std::runtime_error("Error: invalid input");
	}
}






void	PmergeMe::vectorParse()
{

}

void PmergeMe::vectorSort()
{
	// getTime(VECTOR, START);
	this->vectorParse();




	// getTime(VECTOR, END);
}





















void	PmergeMe::getTime(int container_type, int sorting_state)
{
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	long long micros = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();

	if (container_type == VECTOR)
	{
		if (sorting_state == START)
			_vector_time = micros;
		else if (sorting_state == END)
			_vector_time = micros - _vector_time;
	}
	else if (container_type == DEQUE)
	{
		if (sorting_state == START)
			_deque_time = micros;
		else if (sorting_state == END)
			_deque_time = micros - _deque_time;
	}
}

// void	PmergeMe::printResult()
// {

// 	std::cout << "Before: " <<

// 	std::cout << "After:  " <<

// 	std::cout << "Time to process a range of " << _elements_amount << " elements with std::vector : " << _vector_time << " us" << std::endl;
// 	std::cout << "Time to process a range of " << _elements_amount << " elements with std::deque  : " << _deque_time << " us" << std::endl;
// }
