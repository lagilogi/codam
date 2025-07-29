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

typedef std::vector<indexedPair> pairVector;


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
		void				getTime(int container_type, int sorting_state);
		void				printResult();
		std::vector<int>	getJacobsthalSequence(int vectorSize);
		indexedPair			createIndexedPair(int num1, int num2, int pair_index);
		
		
		void				vectorParse();
		void				vectorSorting();
		// std::vector<int>	vectorSortElements(std::vector<int>& numbers);
		// std::vector<int>	vectorSortElements(std::vector<int>& numbers, pairVector& pairs);
		// void				vectorInsert(std::vector<int>& big_numbers, pairVector& number_pair, pairVector& previous_pairs, pairVector& updated_pairs, int index);

		std::vector<int> vectorSortElements(std::vector<int>& numbers);
		void vectorInsert(std::vector<int>& result, const std::vector<indexedPair>& mirrored_pairs, const std::vector<int>& jacobsthal_sequence);



		void				vectorIncrementOriginalIndex(pairVector& number_pairs, size_t index);

		void				dequeSort();

};
