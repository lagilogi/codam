#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <ctime>
#include <chrono>
#include <sstream>

#define DEBUG 0

struct indexedPair
{
	int	big;
	int	small;
	int index;
};

class PmergeMe
{
	private:
		char**				_input;

		std::vector<int>	_vector;
		std::vector<int>	_vector_sorted;
		double				_vector_time;

		std::deque<int>		_deque;
		std::deque<int>		_deque_sorted;
		double				_deque_time;

		time_t				_start;
		int					_elements_amount;

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

	public:
		PmergeMe(int argc, char** input);
		~PmergeMe();

		void				checkInput();
		void				printResult();
		std::vector<int>	getJacobsthalSequence(int pend_size);

		template<typename T>
		void	createPairs(const T& numbers, T& big_numbers, std::unordered_map<int, int>& pairs_map);

		template<typename T>
		T 		getJacobsthalSequence(int pend_size);

		template<typename T>
		void	debugPrint(std::unordered_map<int, int>& pairs_umap, T& numbers, T& sorted_numbers, T& big_numbers, int leftover);


		void				vectorParse();
		void				vectorSorting();
		std::vector<int>	vectorSortElements(std::vector<int>& numbers);
		void				vectorInsert(std::vector<int>& sorted_numbers, std::vector<indexedPair>& sorted_pairs, int leftover, int index);


		void				dequeParse();
		void				dequeSorting();
		std::deque<int>		dequeSortElements(std::deque<int>& numbers);
		void				dequeInsert(std::deque<int>& sorted_numbers, std::deque<indexedPair>& sorted_pairs, int leftover, int index);
};


template<typename T>
void	PmergeMe::createPairs(const T& numbers, T& big_numbers, std::unordered_map<int, int>& pairs_map)
{
	size_t i = 0;

	while (i + 1 < numbers.size())
	{
		if (numbers[i] > numbers[i + 1])
		{
			pairs_map[numbers[i]] = numbers[i + 1];
			big_numbers.push_back(numbers[i]);
		}
		else
		{
			pairs_map[numbers[i + 1]] = numbers[i];
			big_numbers.push_back(numbers[i + 1]);
		}
		i += 2;
	}
}


template<typename T>
T PmergeMe::getJacobsthalSequence(int pend_size)
{
	T sequence;
	int curr_num = 1;
	int prev_num = 1;
	int jacobsthal_num = 0;
	int num_to_add = 0;

	if (pend_size == 0)
		return (sequence);

	if (pend_size == 1)
	{
		sequence.push_back(1);
		return (sequence);
	}

	while (1)
	{
		jacobsthal_num = curr_num + (2 * prev_num);
		if (jacobsthal_num > pend_size)
			break ;
		num_to_add = jacobsthal_num;
		while (num_to_add > curr_num)
		{
			sequence.push_back(num_to_add - 1);
			num_to_add--;
		}
		prev_num = curr_num;
		curr_num = jacobsthal_num;
	}
	num_to_add = pend_size;
	while (num_to_add != curr_num)
	{
		sequence.push_back(num_to_add - 1);
		num_to_add--;
	}

	return (sequence);
}


template<typename T>
void	PmergeMe::debugPrint(std::unordered_map<int, int>& pairs_umap, T& numbers, T& sorted_numbers, T& big_numbers, int leftover)
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Initial list:  ";
	for (int element : numbers)
		std::cout << element << " ";
	std::cout << std::endl;

	std::cout << "\nUnordered map pairs from initial list:" << std::endl;
	std::cout << "Big pair:   ";
	for (auto element : pairs_umap)
	std::cout << element.first << " ";
	std::cout << std::endl;
	std::cout << "Small pair: ";
	for (auto element : pairs_umap)
		std::cout << element.second << " ";
	std::cout << std::endl;
	if (leftover != -1)
		std::cout << "Leftover:   " << leftover << std::endl;

	std::cout << "\nBig nums:       ";
	for (int element : big_numbers)
		std::cout << element << " ";
	std::cout << std::endl;

	std::cout << "\nSorted list:    ";
	for (int element : sorted_numbers)
		std::cout << element << " ";
	std::cout << std::endl;

	std::cout << "Nums to insert: ";
	for (int element : sorted_numbers)
		std::cout << pairs_umap[element] << " ";
	if (leftover != -1)
		std::cout << leftover;
	std::cout << std::endl;
	std::cout << "-----------------\n" << std::endl;
}
