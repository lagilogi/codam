#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <ctime>
#include <chrono>
#include <sstream>

struct indexedPair
{
	int	big;
	int	small;
	int index;
};

enum containerTimer
{
	VECTOR,
	DEQUE,
	START,
	END
};

typedef std::vector<indexedPair> pairVector;
typedef std::deque<indexedPair> pairDeque;


class PmergeMe
{
	private:
		std::string			_input;

		std::vector<int>	_vector;
		std::vector<int>	_vector_sorted;
		double				_vector_time;

		std::deque<int>		_deque;
		std::deque<int>		_deque_sorted;
		double				_deque_time;


		int					_elements_amount;

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

	public:
		PmergeMe(char* input);
		~PmergeMe();

		void				checkInput();
		void				checkNumbers();
		void				getTime(int container_type, int sorting_state);
		void				printResult();
		std::vector<int>	getJacobsthalSequence(int pend_size);

		
		void				vectorParse();
		void				vectorSorting();
		std::vector<int>	vectorSortElements(std::vector<int>& numbers);
		void				vectorInsert(std::vector<int>& sorted_numbers, std::vector<indexedPair>& sorted_pairs, int leftover, int index);


		void				dequeSort();

};
