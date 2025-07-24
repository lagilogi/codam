#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <chrono>
#include <sstream>

struct indexedPair
{
	int	small;
	int	big;
	int	original_index;
};

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

		void				checkInput();
		void				getTime(int container_type, int sorting_state);
		void				printResult();
		std::vector<int>	getJacobsthalSequence(int vectorSize);
		indexedPair			createIndexedPair(int num1, int num2, int pair_index);
		
		
		void				vectorParse();
		void				vectorSorting();
		std::vector<int>	vectorSortElements(std::vector<int>& numbers);
		std::vector<int>	vectorSortElements(std::vector<int>& numbers, std::vector<indexedPair>& pairs);
		void				vectorInsert(std::vector<int>& big_numbers, std::vector<indexedPair>& number_pair, std::vector<indexedPair>& previous_pairs, int index);
		void				vectorIncrementOriginalIndex(std::vector<indexedPair>& number_pairs, size_t index);

		void				dequeSort();

};
