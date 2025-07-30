#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char* input) : _input(input), _vector_time(0), _deque_time(0), _elements_amount(0) {}

PmergeMe::~PmergeMe() {}


void	PmergeMe::checkInput()
{
	for (char c : _input)
	{
		if (c != ' ' && !std::isdigit(c))
			throw std::runtime_error("Error: invalid input");
	}
}


void	PmergeMe::checkNumbers()
{
	std::stringstream	ss(_input);
	std::vector<int>	numbers;
	int					num;

	while (ss >> num)
		numbers.push_back(num);
	
	if (numbers.empty())
		throw std::runtime_error("Error: no numbers");
	if (numbers.size() == 1)
		throw std::runtime_error("Error: nothing to sort");

	for (size_t i = 0; i < numbers.size(); ++i)
		for (size_t j = i + 1; j < numbers.size(); ++j)
			if (numbers[i] == numbers[j])
				throw std::runtime_error("Error: duplicates found");
	
	_elements_amount = numbers.size();
}




std::vector<int> PmergeMe::getJacobsthalSequence(int pend_size)
{
	std::vector<int> sequence;
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




void	PmergeMe::vectorParse()
{
	std::stringstream	ss(_input);
	int					num;

	while (ss >> num)
		_vector.push_back(num);

	{	// TESTING ---
		std::cout << "Vector: ";
		// for (int element : _vector)
		// 	std::cout << "" << element << " ";
		for (size_t i = 0; i < _vector.size(); ++i)
		{
			if (i % 2 == 0 && i + 1 != _vector.size())
				std::cout << "(" << _vector[i];
			else if (i % 2 == 1)
				std::cout << ", " << _vector[i] << "), ";
			else
				std::cout << _vector[i];
		}
		std::cout << "\n" << std::endl;
		// END OF TESTING ---
	}
}




void	printPairs(std::unordered_map<int, int>& pairs_umap, std::vector<int>& big_numbers, std::vector<int>& numbers, int leftover)
{
	std::cout << "\n---Pairs list" << std::endl;
	std::cout << "Initial list:  ";
	for (int element : numbers)
		std::cout << " " << element << " ";
	std::cout << std::endl;
	std::cout << "\nBig list:   ";
	for (int element : big_numbers)
		std::cout << " " << element << " ";
	std::cout << std::endl;
	std::cout << "\nBig pair:   ";
	for (auto element : pairs_umap)
	std::cout << " " << element.first << " ";
	std::cout << std::endl;
	std::cout << "Small pair: ";
	for (auto element : pairs_umap)
		std::cout << " " << element.second << " ";
	std::cout << std::endl;
	if (leftover != -1)
		std::cout << "Leftover:    " << leftover << std::endl;
	std::cout << "---End of pairs list\n" << std::endl;
}




void	createVectorPairs(const std::vector<int>& numbers, std::vector<int>& big_numbers, std::unordered_map<int, int>& pairs_map)
{
	size_t i = 0;

	while (i + 1 < numbers.size())
	{
		std::cout << "Adding pair: " << numbers[i] << " & " << numbers[i + 1] << std::endl;
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




std::vector<int> PmergeMe::vectorSortElements(std::vector<int>& numbers)
{
	std::cout << "-----------------------------------------------------------------" << std::endl;
	if (numbers.size() <= 1)
	{
		std::cout << "--------------------------------" << std::endl;
		return (numbers);
	}



	// step 1 - make pairs and put bigger numbers of its pair in a seperate vector
	std::unordered_map<int, int>	pairs_umap;
	std::vector<int>				big_numbers;
	int								leftover = -1;
	createVectorPairs(numbers, big_numbers, pairs_umap);
	if (numbers.size() % 2 != 0)
		leftover = numbers.back();
	printPairs(pairs_umap, big_numbers, numbers, leftover);




	// step 2 - call self-function recursively to sort bigger numbers on deeper levels
	std::vector<int> sorted_numbers = vectorSortElements(big_numbers);
	
	
	{	// TESTING ---
		std::cout << "Sorted numbers: ";
		for (int ele : sorted_numbers)
			std::cout << ele << " ";
		std::cout << std::endl;
	}

	std::vector<indexedPair>	sorted_pairs;
	if (pairs_umap.size() == 1)
	{
		std::cout << "adding value: " << pairs_umap[big_numbers[0]] << std::endl;
		sorted_numbers.insert(sorted_numbers.begin(), pairs_umap[big_numbers[0]]);
		if (leftover != -1)
			vectorInsert(sorted_numbers, sorted_pairs, leftover, 0);
		std::cout << "--------------------------------" << std::endl;
		return (sorted_numbers);
	}





	// step 3 - create sorted pair vector for inserting correctly
	// std::vector<indexedPair>	sorted_pairs;
	
	{	// TESTING ---
		std::cout << "\n\npairs_umap size: " << pairs_umap.size() << std::endl;
		std::cout << "Big pair:   ";
		for (auto element : pairs_umap)
		std::cout << " " << element.first << " ";
		std::cout << std::endl;
		std::cout << "Small pair: ";
		for (auto element : pairs_umap)
			std::cout << " " << element.second << " ";
		std::cout << std::endl;
	}

	for (size_t i = 0; i < pairs_umap.size(); ++i)
	{
		indexedPair new_pair;
		new_pair.big = sorted_numbers[i];
		new_pair.small = pairs_umap[sorted_numbers[i]];
		new_pair.index = i;
		sorted_pairs.push_back(new_pair);
	}

	{	// TESTING ---
		std::cout << "\n---After sorting numbers & sorting pairs - before inserting" << std::endl;
		std::cout << "Sorted numbers:  ";
		for (int element : sorted_numbers)
			std::cout << element << " ";
		std::cout << std::endl;
		std::cout << "big:    ";
		for (indexedPair element : sorted_pairs)
			std::cout << element.big << " ";
		std::cout << std::endl;
		std::cout << "small:  ";
		for (indexedPair element : sorted_pairs)
			std::cout << element.small << " ";
		std::cout << std::endl;
		if (leftover != -1)
			std::cout << "Leftover: " << leftover << std::endl;
		std::cout << "---End of After sorting numbers & sorting pairs - before inserting\n" << std::endl;
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
	std::vector<int> jacobsthalSequence = getJacobsthalSequence(sorted_pairs.size());

	// {	// TESTING ---
	// 	std::cout << "jacobsthal: ";
	// 	for (int ele : jacobsthalSequence)
	// 		std::cout << ele;
	// 	std::cout << std::endl;
	// }


	for (int index : jacobsthalSequence)
		vectorInsert(sorted_numbers, sorted_pairs, -1, index);
	if (leftover != -1)
		vectorInsert(sorted_numbers, sorted_pairs, leftover, 0);


	// step 5 - return sorted vector
	std::cout << "--------------------------------" << std::endl;
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
	
	// { // TESTING ----
	// 	std::cout << "---Adding to sorted numbers" << std::endl;
	// 	std::cout << "Sorted: ";
	// 	for (int ele : sorted_numbers)
	// 		std::cout << ele << " ";
	// 	std::cout << std::endl;
	// 	std::cout << "Big num: " << sorted_pairs[index].big << " / index: " << sorted_pairs[index].index << std::endl;
	// }

	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (value < sorted_numbers[mid])
			right = mid;
		else
			left = mid + 1;
	}
	std::cout << "adding value: " << value << " with index: " << index << std::endl;
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


void	PmergeMe::vectorSorting()
{
	getTime(VECTOR, START);
	this->vectorParse();
	_vector_sorted = this->vectorSortElements(_vector);

	getTime(VECTOR, END);
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
	// std::cout << "Time to process a range of " << _elements_amount << " elements with std::deque  : " << _deque_time << " us" << std::endl;
}
