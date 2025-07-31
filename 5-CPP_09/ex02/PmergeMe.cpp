#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** input) : _input(input), _vector_time(0), _deque_time(0), _elements_amount(argc - 1) {}

PmergeMe::~PmergeMe() {}


void	PmergeMe::checkInput()
{
	if (_elements_amount == 0)
		throw std::runtime_error("Error: no numbers");
	if (_elements_amount == 1)
		throw std::runtime_error("Error: nothing to sort");

	std::vector<int>	numbers;
	std::string			num_str;
	long				num;

	// Check for invalid arguments
	for (int i = 1; i < _elements_amount + 1; ++i)
	{
		num_str = _input[i];
		for (char c : num_str)
			if (!std::isdigit(c))
				throw std::runtime_error("Error: invalid character in input");
		num = std::atol(_input[i]);
		if (num > __INT_MAX__)
			throw std::runtime_error("Error: number is too big");
		numbers.push_back(static_cast<int>(num));
	}

	// Check for duplicates
	for (size_t i = 0; i < numbers.size(); ++i)
		for (size_t j = i + 1; j < numbers.size(); ++j)
			if (numbers[i] == numbers[j])
				throw std::runtime_error("Error: duplicates found");

}


void	PmergeMe::printResult()
{
	std::cout << "Before: ";
	for (int ele : _vector)
		std::cout << ele << " ";
	std::cout << std::endl;

	std::cout << "After:  ";
	for (int ele : _vector_sorted)
		std::cout << ele << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _elements_amount << " elements with std::vector : " << _vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << _elements_amount << " elements with std::deque  : " << _deque_time << " us" << std::endl;
}



//////////////////////// VECTOR /////////////////////////////
void	PmergeMe::vectorSorting()
{
	auto start = std::chrono::high_resolution_clock::now();

	this->vectorParse();
	_vector_sorted = this->vectorSortElements(_vector);

	auto end = std::chrono::high_resolution_clock::now();
	_vector_time = std::chrono::duration<double, std::micro>(end - start).count();
}


void	PmergeMe::vectorParse()
{
	int	num;
	for (int i = 1; i < _elements_amount + 1; ++i)
	{
		num = std::atoi(_input[i]);
		_vector.push_back(num);
	}
}


std::vector<int> PmergeMe::vectorSortElements(std::vector<int>& numbers)
{
	if (numbers.size() <= 1)
		return (numbers);


	// step 1 - make pairs and put bigger numbers of its pair in a seperate vector
	std::unordered_map<int, int>	pairs_umap;
	std::vector<int>				big_numbers;
	int								leftover = -1;
	createPairs(numbers, big_numbers, pairs_umap);
	
	if (numbers.size() % 2 != 0)
		leftover = numbers.back();


	// step 2 - call self-function recursively to sort bigger numbers on deeper levels
	std::vector<int> sorted_numbers = vectorSortElements(big_numbers);


	if (DEBUG)
		debugPrint<std::vector<int>>(pairs_umap, numbers, sorted_numbers, big_numbers, leftover);

	std::vector<indexedPair>	sorted_pairs;
	if (pairs_umap.size() == 1)
	{
		sorted_numbers.insert(sorted_numbers.begin(), pairs_umap[big_numbers[0]]);
		if (leftover != -1)
			vectorInsert(sorted_numbers, sorted_pairs, leftover, 0);
		return (sorted_numbers);
	}


	// step 3 - create sorted pair vector for inserting correctly
	for (size_t i = 0; i < pairs_umap.size(); ++i)
	{
		indexedPair new_pair;
		new_pair.big = sorted_numbers[i];
		new_pair.small = pairs_umap[sorted_numbers[i]];
		new_pair.index = i;
		sorted_pairs.push_back(new_pair);
	}

	

	// step 4 - insert smaller numbers into bigger numbers list with jacobsthal sequence

	// step 4.1 - insert first small number immediately
	sorted_numbers.insert(sorted_numbers.begin(), sorted_pairs[0].small);
	size_t i = 1;
	while (i < sorted_pairs.size())
	{
		sorted_pairs[i].index++;
		i++;
	}

	// step 4.2 - insert rest according to jacobsthal sequence
	std::vector<int> jacobsthalSequence = getJacobsthalSequence<std::vector<int>>(sorted_pairs.size());

	for (int index : jacobsthalSequence)
		vectorInsert(sorted_numbers, sorted_pairs, -1, index);
	if (leftover != -1)
		vectorInsert(sorted_numbers, sorted_pairs, leftover, 0);


	// step 5 - return sorted vector
	return (sorted_numbers);
}


void PmergeMe::vectorInsert(std::vector<int>& sorted_numbers, std::vector<indexedPair>& sorted_pairs, int leftover, int index)
{
	int value;
	int right;
	if (leftover != -1)
	{
		value = leftover;
		right = static_cast<int>(sorted_numbers.size() - 1);
	}
	else
	{
		value = sorted_pairs[index].small;
		right = sorted_pairs[index].index;
	}
	int	left = 0;
	int	mid;

	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (value < sorted_numbers[mid])
			right = mid;
		else
			left = mid + 1;
	}
	if (value > sorted_numbers[left])
		sorted_numbers.insert(sorted_numbers.begin() + left + 1, value);
	else
		sorted_numbers.insert(sorted_numbers.begin() + left, value);
	size_t i = left + 1;
	while (i < sorted_pairs.size())
	{
		sorted_pairs[i].index++;
		i++;
	}
}
///////////////////// END OF VECTOR /////////////////////////


//////////////////////// DEQUE /////////////////////////////
void	PmergeMe::dequeParse()
{
	int	num;
	for (int i = 1; i < _elements_amount + 1; ++i)
	{
		num = std::atoi(_input[i]);
		_deque.push_back(num);
	}
}


std::deque<int> PmergeMe::dequeSortElements(std::deque<int>& numbers)
{
	if (numbers.size() <= 1)
		return (numbers);


	// step 1 - make pairs and put bigger numbers of its pair in a seperate deque
	std::unordered_map<int, int>	pairs_umap;
	std::deque<int>					big_numbers;
	int								leftover = -1;
	createPairs(numbers, big_numbers, pairs_umap);
	
	if (numbers.size() % 2 != 0)
		leftover = numbers.back();


	// step 2 - call self-function recursively to sort bigger numbers on deeper levels
	std::deque<int> sorted_numbers = dequeSortElements(big_numbers);

		if (DEBUG)
			debugPrint<std::deque<int>>(pairs_umap, numbers, sorted_numbers, big_numbers, leftover);

	std::deque<indexedPair>	sorted_pairs;
	if (pairs_umap.size() == 1)
	{
		sorted_numbers.insert(sorted_numbers.begin(), pairs_umap[big_numbers[0]]);
		if (leftover != -1)
			dequeInsert(sorted_numbers, sorted_pairs, leftover, 0);
		return (sorted_numbers);
	}


	// step 3 - create sorted pair deque for inserting correctly
	for (size_t i = 0; i < pairs_umap.size(); ++i)
	{
		indexedPair new_pair;
		new_pair.big = sorted_numbers[i];
		new_pair.small = pairs_umap[sorted_numbers[i]];
		new_pair.index = i;
		sorted_pairs.push_back(new_pair);
	}
	

	// step 4 - insert smaller numbers into bigger numbers list with jacobsthal sequence

	// step 4.1 - insert first smaller number immediately
	sorted_numbers.insert(sorted_numbers.begin(), sorted_pairs[0].small);
	size_t i = 1;
	while (i < sorted_pairs.size())
	{
		sorted_pairs[i].index++;
		i++;
	}

	// step 4.2 - insert rest according to jacobsthal sequence
	std::deque<int> jacobsthalSequence = getJacobsthalSequence<std::deque<int>>(sorted_pairs.size());


	for (int index : jacobsthalSequence)
		dequeInsert(sorted_numbers, sorted_pairs, -1, index);
	if (leftover != -1)
		dequeInsert(sorted_numbers, sorted_pairs, leftover, 0);


	// step 5 - return sorted deque
	return (sorted_numbers);
}



void PmergeMe::dequeInsert(std::deque<int>& sorted_numbers, std::deque<indexedPair>& sorted_pairs, int leftover, int index)
{
	int value;
	int right;
	if (leftover != -1)
	{
		value = leftover;
		right = static_cast<int>(sorted_numbers.size() - 1);
	}
	else
	{
		value = sorted_pairs[index].small;
		right = sorted_pairs[index].index;
	}
	int	left = 0;
	int	mid;

	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (value < sorted_numbers[mid])
			right = mid;
		else
			left = mid + 1;
	}
	if (value > sorted_numbers[left])
		sorted_numbers.insert(sorted_numbers.begin() + left + 1, value);
	else
		sorted_numbers.insert(sorted_numbers.begin() + left, value);
	size_t i = left + 1;
	while (i < sorted_pairs.size())
	{
		sorted_pairs[i].index++;
		i++;
	}
}


void	PmergeMe::dequeSorting()
{
	auto start = std::chrono::high_resolution_clock::now();

	this->dequeParse();

	_deque_sorted = this->dequeSortElements(_deque);

	auto end = std::chrono::high_resolution_clock::now();
	_deque_time = std::chrono::duration<double, std::micro>(end - start).count();
}
///////////////////// END OF DEQUE /////////////////////////
