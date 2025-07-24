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

std::vector<int>	PmergeMe::getJacobsthalSequence(int vector_size)
{
	std::vector<int>	jacobsthal_sequence;
	int					num1 = 1;
	int					num2 = 1;
	int					result;
	int					result2;
	int					last_passed_result;

	while (1)
	{
		result = (num1 + (num2 * 2));
		if (result > vector_size)
			break ;
		jacobsthal_sequence.push_back(result - 1);
		last_passed_result = result;
		result2 = result - 1;
		while (result2 > num1)
		{
			jacobsthal_sequence.push_back(result2 - 1);
			result2--;
		}
		num2 = num1;
		num1 = result;
	}
	while (last_passed_result < vector_size)
	{
		jacobsthal_sequence.push_back(last_passed_result);
		last_passed_result++;
	}

	{	// TESTING ---
		std::cout << "Jacobsthal: ";
		if (!jacobsthal_sequence.empty())
		{
			for (int element : jacobsthal_sequence)
				std::cout << element << " ";
			std::cout << "\n" << std::endl;

		}
	}
	
	return (jacobsthal_sequence);
}

indexedPair			PmergeMe::createIndexedPair(int num1, int num2, int pair_index)
{
	indexedPair new_pair;

	new_pair.big = num1 >= num2 ? num1 : num2;
	new_pair.small = num1 <= num2 ? num1 : num2;
	new_pair.original_index = pair_index;
	return (new_pair);
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




void	PmergeMe::vectorIncrementOriginalIndex(std::vector<indexedPair>& number_pairs, size_t index)
{
	if (index >= number_pairs.size())
		return ;
	while (index < number_pairs.size())
	{
		if (number_pairs[index].original_index != -1)
			number_pairs[index].original_index++;
		index++;
	}
}







std::vector<int>	PmergeMe::vectorSortElements(std::vector<int>& numbers, std::vector<indexedPair>& previous_pairs)
{
	std::vector<indexedPair>	number_pairs;
	std::vector<int>			big_numbers;

	if (numbers.size() == 2)
	{
		if (numbers[0] > numbers[1])
			previous_pairs[0].original_index = 1;
		big_numbers.push_back(std::min(numbers[0], numbers[1]));
		big_numbers.push_back(std::max(numbers[0], numbers[1]));

		{	// TESTING ---
			std::cout << "Vector bignum: ";
			for (int element : big_numbers)
				std::cout << element << " ";
			std::cout << std::endl;
		}

		std::cout << "Pairs passed along: " << previous_pairs.size() << "\n--\n" << std::endl;
		return (big_numbers);
	}


	size_t	i = 0;
	int		pair_index = 0;
	while (i + 1 < numbers.size())
	{
		if (numbers[i] >= numbers[i + 1])
			big_numbers.push_back(numbers[i]);
		else
			big_numbers.push_back(numbers[i + 1]);
		number_pairs.push_back(createIndexedPair(numbers[i], numbers[i + 1], pair_index));
		i += 2;
		pair_index++;
	}
	if (numbers.size() % 2 != 0)
		big_numbers.push_back(numbers.back());


	{	// TESTING ---
		std::cout << "Vector bignum: ";
		for (int element : big_numbers)
			std::cout << element << " ";
		std::cout << std::endl;
		std::cout << "Vector big:    ";
		for (indexedPair element : number_pairs)
			std::cout << element.big << " ";
		std::cout << std::endl;
		std::cout << "Vector small:  ";
		for (indexedPair element : number_pairs)
			std::cout << element.small << " "; 
		std::cout << std::endl;
		std::cout << "Pairs passed along: " << previous_pairs.size() << "\n--\n" << std::endl;
		// END OF TESTING ---
	}




	if (big_numbers.size() >= 2)
		big_numbers = vectorSortElements(big_numbers, number_pairs);


	// Checking if vector of 2 elements and 1 pair special case
	if (number_pairs.size() == 1 && big_numbers.size() == 2)
	{
		vectorInsert(big_numbers, number_pairs, previous_pairs, -1);
		return (big_numbers);
	}

	previous_pairs = number_pairs;
	// Always adding first small number to front of big_numbers
	vectorInsert(big_numbers, number_pairs, previous_pairs, 0);
	if (number_pairs.size() == 1)
		return (big_numbers);







	std::vector<int>	jacobsthal_sequence = getJacobsthalSequence(number_pairs.size());
	if (!jacobsthal_sequence.empty())
	{
		for (i = 0; i < jacobsthal_sequence.size(); ++i)
			vectorInsert(big_numbers, number_pairs, previous_pairs, jacobsthal_sequence[i]);
	}

	{	// TESTING ---
		std::cout << "Vector bignum after: ";
		for (int element : big_numbers)
			std::cout << element << " ";
		std::cout << std::endl;
	}

	return (big_numbers);
}


void	PmergeMe::vectorInsert(std::vector<int>& big_numbers, std::vector<indexedPair>& number_pairs, std::vector<indexedPair>& previous_pairs, int index)
{
	std::cout << "Big number size: " << big_numbers.size() << std::endl;

	// In case of a single pair, of which the small needs to be added to the big_numbers list
	// that contains 2 numbers, thus dealing with an uneven amount of numbers at this stage.
	// We compare the smaller value of the pair with the first number in the big_numbers list,
	// so we know to insert before or after that number.
	if (big_numbers.size() == 2 && number_pairs.size() == 1)
	{
		if (number_pairs[0].small <= big_numbers[0])
			big_numbers.insert(big_numbers.begin(), number_pairs[0].small);
		else
			big_numbers.insert(big_numbers.begin() + 1, number_pairs[0].small);
		return ;
	}

	// In case of the first small value to be added, it can always be dropped at the front 
	// of the big_numbers list.
	if (index == 0)
	{
		big_numbers.insert(big_numbers.begin(), number_pairs[0].small);
		previous_pairs.insert(previous_pairs.begin(), number_pairs[0]);
		vectorIncrementOriginalIndex(number_pairs, 1);
		return ;
	}
	

	// We start comparing the small value with the value in front of the value in front of
	// its pair.
	int i = number_pairs[index].original_index - 1;
	while (i >= 0)
	{
		if (number_pairs[index].small >= big_numbers[i])
		{
			number_pairs[index].original_index = i + 1;
			big_numbers.insert(big_numbers.begin() + i + 1, number_pairs[index].small);
			previous_pairs.insert(previous_pairs.begin() + i + 1, number_pairs[index]);
			number_pairs[index].original_index = -1;
			break ;
		}
		--i;
	}

	i++;
	while (i < (int)number_pairs.size())
	{
		if (number_pairs[i].original_index != -1)
			number_pairs[i].original_index++;
		i++;
	}
}




std::vector<int>	PmergeMe::vectorSortElements(std::vector<int>& numbers)
{
	std::vector<indexedPair> dummy;
	return (vectorSortElements(numbers, dummy));
}


void	PmergeMe::vectorSorting()
{
	// getTime(VECTOR, START);
	this->vectorParse();
	this->vectorSortElements(_vector);




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
