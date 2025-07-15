#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <chrono>

enum containerTimer
{
	VECTOR,
	DEQUE,
	START,
	END
};

class PmergeMe
{
	private:
		std::string			_input;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_vector_time;
		double				_deque_time;
		int					_elements_amount;
		
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

	public:
		PmergeMe(char* input);
		~PmergeMe();

		void	checkInput();
		void	getTime(int container_type, int sorting_state);
		void	printResult();

		void	vectorSort();
		void	vectorParse();

		void	dequeSort();

};