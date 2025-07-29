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

// std::vector<int>	PmergeMe::getJacobsthalSequence(int vector_size)
// {
// 	std::vector<int>	jacobsthal_sequence;
// 	int					curr_num = 1;
// 	int					prev_num = 1;
// 	int					num_to_add = 0;
// 	int					jacobs_num = 3;


// 	// do
// 	// {
// 	// 	jacobs_num = curr_num + (2 * prev_num); 
// 	// 	num_to_add = jacobs_num;
// 	// 	while (num_to_add > curr_num)
// 	// 	{
// 	// 		jacobsthal_sequence.push_back(num_to_add - 1);
// 	// 		num_to_add--;
// 	// 	}
// 	// 	prev_num = curr_num;
// 	// 	curr_num = jacobs_num;
// 	// } while (jacobs_num < vector_size);
	

// 	while (jacobs_num <= vector_size)
// 	{
// 		jacobs_num = curr_num + (2 * prev_num);
// 		num_to_add = jacobs_num;
// 		while (num_to_add > curr_num)
// 		{
// 			jacobsthal_sequence.push_back(num_to_add - 1);
// 			num_to_add--;
// 		}
// 		prev_num = curr_num;
// 		curr_num = jacobs_num;
// 	}
// }

std::vector<int> PmergeMe::getJacobsthalSequence(int vector_size)
{
	std::vector<int> sequence;
	if (vector_size <= 1)
		return sequence;

	int j_prev = 0;
	int j_curr = 1;
	int j_next = j_curr + 2 * j_prev;

	std::vector<bool> added(vector_size, false);

	// Generate Jacobsthal sequence in insertion order
	while (j_next < vector_size)
	{
		if (!added[j_next]) {
			sequence.push_back(j_next);
			added[j_next] = true;
		}
		for (int i = j_next - 1; i > j_prev; --i)
		{
			if (!added[i] && (int)sequence.size() < vector_size - 1)
			{
				sequence.push_back(i);
				added[i] = true;
			}
		}
		j_prev = j_curr;
		j_curr = j_next;
		j_next = j_curr + 2 * j_prev;
	}

	// Fill in any missing indices (in ascending order)
	for (int i = 1; i < vector_size; ++i)
	{
		if (!added[i])
			sequence.push_back(i);
	}

	return sequence;
}




// std::vector<int>	PmergeMe::getJacobsthalSequence(int vector_size)
// {
// 	std::vector<int>	jacobsthal_sequence;
// 	int					num1 = 1;
// 	int					num2 = 1;
// 	int					result = 0;
// 	int					result2 = 0;
// 	int					last_passed_result = 3;

// 	while (1)
// 	{
// 		result = (num1 + (num2 * 2));
// 		if (result > vector_size)
// 			break ;
// 		jacobsthal_sequence.push_back(result - 1);
// 		last_passed_result = result;
// 		result2 = result - 1;
// 		while (result2 > num1)
// 		{
// 			jacobsthal_sequence.push_back(result2 - 1);
// 			result2--;
// 		}
// 		num2 = num1;
// 		num1 = result;
// 	}
// 	result = vector_size - 1;
// 	while (result > last_passed_result)
// 	{
// 		jacobsthal_sequence.push_back(last_passed_result);
// 		result--;
// 	}
	
// 	return (jacobsthal_sequence);
// }

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




void	PmergeMe::vectorIncrementOriginalIndex(pairVector& number_pairs, size_t index)
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


// FOR TESTING PURPOSES
void	printPairs(pairVector& pairs, std::vector<int>& numbers)
{
	std::cout << "\nPairs list ---" << std::endl;
	std::cout << "Big:\n";
	for (int element : numbers)
		std::cout << " " << element << " ";
	std::cout << std::endl;
	for (indexedPair element : pairs)
		std::cout << " " << element.big << " ";
	std::cout << std::endl;
	for (indexedPair element : pairs)
		std::cout << " " << element.small << " ";
	std::cout << std::endl;
	for (indexedPair element : pairs)
		std::cout << " " << element.original_index << " ";
	std::cout << "\nEnd of pairs list ---\n" << std::endl;
}



// std::vector<int>	PmergeMe::vectorSortElements(std::vector<int>& numbers, pairVector& previous_pairs)
// {
// 	pairVector	number_pairs;
// 	std::vector<int>			big_numbers;

// 	{	// TESTING ---
// 		std::cout << "Check pairs at start of recursion function";
// 		printPairs(previous_pairs, big_numbers);
// 	}

// 	if (numbers.size() == 2)
// 	{
// 		std::cout << "Swapping" << std::endl;
// 		if (numbers[0] > numbers[1])
// 			previous_pairs[0].original_index = 1;
		// big_numbers.push_back(std::min(numbers[0], numbers[1]));
// 		big_numbers.push_back(std::max(numbers[0], numbers[1]));

// 		{	// TESTING ---
// 			std::cout << "Vector bignum: ";
// 			for (int element : big_numbers)
// 				std::cout << element << " ";
// 			std::cout << std::endl;
// 		}

// 		return (big_numbers);
// 	}


// 	size_t	i = 0;
// 	int		pair_index = 0;
// 	while (i + 1 < numbers.size())
// 	{
// 		if (numbers[i] >= numbers[i + 1])
// 			big_numbers.push_back(numbers[i]);
// 		else
// 			big_numbers.push_back(numbers[i + 1]);
// 		number_pairs.push_back(createIndexedPair(numbers[i], numbers[i + 1], pair_index));
// 		i += 2;
// 		pair_index++;
// 	}
// 	if (numbers.size() % 2 != 0)
// 		big_numbers.push_back(numbers.back());


// 	{	// TESTING ---
// 		std::cout << "Vector bignum: ";
// 		for (int element : big_numbers)
// 			std::cout << element << " ";
// 		std::cout << std::endl;
// 		std::cout << "Vector big:    ";
// 		for (indexedPair element : number_pairs)
// 			std::cout << element.big << " ";
// 		std::cout << std::endl;
// 		std::cout << "Vector small:  ";
// 		for (indexedPair element : number_pairs)
// 			std::cout << element.small << " "; 
// 		std::cout << std::endl;
// 		std::cout << "Pairs passed along: " << previous_pairs.size() << "\n--\n" << std::endl;
// 		// END OF TESTING ---
// 	}




// 	if (big_numbers.size() >= 2)
// 		big_numbers = vectorSortElements(big_numbers, number_pairs);

// 	{	// TESTING ---
// 		std::cout << "Check pairs after insertion";
// 		printPairs(number_pairs, big_numbers);
// 	}

// 	if (number_pairs.size() == 1 && big_numbers.size() == 2)
// 	{
// 		if (number_pairs[0].big > previous_pairs[2].big)
// 		{
// 			number_pairs.insert(number_pairs.begin(), previous_pairs[2]);
// 			number_pairs[0].original_index = 0;
// 		}
// 	}


// 	// Checking if vector of 2 elements and 1 pair special case
// 	if (number_pairs.size() == 1 && big_numbers.size() == 2)
// 	{
// 		vectorInsert(big_numbers, number_pairs, previous_pairs, -1);
// 		return (big_numbers);
// 	}

// 	{	// TESTING ---
// 		std::cout << "Check number_pairs before setting it over to previous pairs" << std::endl;
// 		printPairs(number_pairs, big_numbers);
// 	}

// 	previous_pairs = number_pairs;


// 	// Always adding first small number to front of big_numbers
// 	vectorInsert(big_numbers, number_pairs, previous_pairs, 0);
// 	if (number_pairs.size() == 1)
// 		return (big_numbers);
// 	if (number_pairs.size() == 2)
// 	{
// 		vectorInsert(big_numbers, number_pairs, previous_pairs, 1);
// 		return (big_numbers);
// 	}


// 	std::cout << "Small numbers for jacobsthal:";
// 	for (indexedPair element : number_pairs)
// 		std::cout << element.small << " ";
// 	std::cout << std::endl;
// 	std::vector<int>	jacobsthal_sequence = getJacobsthalSequence(number_pairs.size());
// 	if (!jacobsthal_sequence.empty())
// 	{
// 		for (i = 0; i < jacobsthal_sequence.size(); ++i)
// 			vectorInsert(big_numbers, number_pairs, previous_pairs, jacobsthal_sequence[i]);
// 	}

// 	{	// TESTING ---
// 		std::cout << "Vector bignum after: ";
// 		for (int element : big_numbers)
// 			std::cout << element << " ";
// 		std::cout << std::endl;
// 	}

// 	return (big_numbers);
// }


// void	PmergeMe::vectorInsert(std::vector<int>& big_numbers, pairVector& number_pairs, pairVector& previous_pairs, int index)
// {
// 	{	// TESTING ---
// 		std::cout << "Big number size: " << big_numbers.size() << std::endl;
// 		std::cout << "Vector bignum: ";
// 		for (int element : big_numbers)
// 			std::cout << element << " ";
// 		std::cout << std::endl;
// 		std::cout << "Pair to insert: " << number_pairs[index].small << " / " << number_pairs[index].big << " - Index: " << number_pairs[index].original_index << " - Passed index: " << index << std::endl;
// 	}

// 	// In case of a single pair, of which the small needs to be added to the big_numbers list
// 	// that contains 2 numbers, thus dealing with an uneven amount of numbers at this stage.
// 	// We compare the smaller value of the pair with the first number in the big_numbers list,
// 	// so we know to insert before or after that number.
// 	indexedPair to_insert = number_pairs[index];

// 	if (big_numbers.size() == 2 && number_pairs.size() == 1)
// 	{
// 		if (number_pairs[0].small <= big_numbers[0])
// 			big_numbers.insert(big_numbers.begin(), number_pairs[0].small);
// 		else
// 			big_numbers.insert(big_numbers.begin() + 1, number_pairs[0].small);
// 		{	// TESTING ----
// 			std::cout << "Inserting struct from previous pairs:\n"
// 						<< "Big: " << previous_pairs[0].big << "\n"
// 						<< "Sma: " << previous_pairs[0].small << "\n"
// 						<< "ind: " << previous_pairs[0].original_index << std::endl;
// 		}
// 		number_pairs.insert(number_pairs.begin(), previous_pairs[0]);
// 		{	// TESTING ---
// 			std::cout << "directly after inserting" << std::endl;
// 			printPairs(number_pairs, big_numbers);
// 		}
		
// 		return ;
// 	}

// 	// In case of the first small value to be added, it can always be dropped at the front 
// 	// of the big_numbers list.
// 	if (index == 0)
// 	{
// 		big_numbers.insert(big_numbers.begin(), number_pairs[0].small);

// 		// {	// TESTING ----
// 		// 	std::cout << "Inserting struct from previous pairs:\n"
// 		// 				<< "Big: " << previous_pairs[0].big << "\n"
// 		// 				<< "Sma: " << previous_pairs[0].small << "\n"
// 		// 				<< "ind: " << previous_pairs[0].original_index << std::endl;
// 		// }

// 		number_pairs.insert(number_pairs.begin(), previous_pairs[0]);
// 		vectorIncrementOriginalIndex(number_pairs, 1);
		
		
// 		{	// TESTING ---
// 			std::cout << "directly after inserting" << std::endl;
// 			printPairs(number_pairs, big_numbers);
// 		}
		
		
// 		return ;
// 	}
	

// 	// We start comparing the small value with the value in front of the value in front of
// 	// its pair.
// 	int i = number_pairs[index].original_index - 1;
// 	while (i >= 0)
// 	{
// 		if (number_pairs[index].small >= big_numbers[i])
// 		{
// 			number_pairs[index].original_index = i + 1;
// 			big_numbers.insert(big_numbers.begin() + i + 1, number_pairs[index].small);
// 			number_pairs.insert(number_pairs.begin() + i + 1, previous_pairs[index]);
			
// 			{	// TESTING ---
// 				std::cout << "directly after inserting" << std::endl;
// 				printPairs(number_pairs, big_numbers);
// 			}
			
// 			break ;
// 		}
// 		--i;
// 	}

// 	i++;
// 	while (i < (int)number_pairs.size())
// 	{
// 		if (number_pairs[i].original_index != -1)
// 			number_pairs[i].original_index++;
// 		i++;
// 	}
// }



// std::vector<int>	PmergeMe::vectorSortElements(std::vector<int>& numbers, pairVector& previous_pairs)
// {
// 	pairVector			number_pairs;
// 	pairVector			updated_pairs;
// 	std::vector<int>	big_numbers;

// 	// // step 1 - Check if int vector only contains 2 numbers
// 	// if (numbers.size() == 2)
// 	// {
// 	// 	std::cout << "Swapping" << std::endl;
// 	// 	if (numbers[0] > numbers[1])
// 	// 		previous_pairs[0].original_index = 1;
// 	// 	big_numbers.push_back(std::min(numbers[0], numbers[1]));
// 	// 	big_numbers.push_back(std::max(numbers[0], numbers[1]));

// 	// 	return (big_numbers);
// 	// }

// 	// Step 1 - Make pairs
// 	size_t	i = 0;
// 	int		pair_index = 0;
// 	while (i + 1 < numbers.size())
// 	{
// 		if (numbers[i] >= numbers[i + 1])
// 			big_numbers.push_back(numbers[i]);
// 		else
// 			big_numbers.push_back(numbers[i + 1]);
// 		number_pairs.push_back(createIndexedPair(numbers[i], numbers[i + 1], pair_index));
// 		i += 2;
// 		pair_index++;
// 	}
// 	if (numbers.size() % 2 != 0)
// 		big_numbers.push_back(numbers.back());


// 	// Step 2 - if our list of big numbers is bigger than 1, we need to go a level deeper
// 	if (big_numbers.size() >= 2)
// 		big_numbers = vectorSortElements(big_numbers, number_pairs);


// 	// step 3 - Save previo
// 	updated_pairs = number_pairs;


// 	// step 4 - Add first small number to list
// 	vectorInsert(big_numbers, number_pairs, previous_pairs, updated_pairs, 0);


// 	// step 5 - generate jacobsthal sequence to add smaller numbers in jacobsthal order
// 	std::vector<int>	jacobsthal_sequence = getJacobsthalSequence(number_pairs.size());
// 	for (i = 0; i < jacobsthal_sequence.size(); ++i)
// 		vectorInsert(big_numbers, number_pairs, previous_pairs, updated_pairs, jacobsthal_sequence[i]);


// 	// step 6 - Set updated_pairs to previous pairs for parent recursion level
// 	previous_pairs = updated_pairs;

// 	return (big_numbers);
// }


// void	PmergeMe::vectorInsert(std::vector<int>& big_numbers, pairVector& number_pairs, pairVector& previous_pairs, pairVector& updated_pairs, int index)
// {
// 	{	// TESTING ---
// 		std::cout << "Big number size: " << big_numbers.size() << std::endl;
// 		std::cout << "Vector bignum: ";
// 		for (int element : big_numbers)
// 			std::cout << element << " ";
// 		std::cout << std::endl;
// 		std::cout << "Pair to insert: " << number_pairs[index].small << " / " << number_pairs[index].big << " - Index: " << number_pairs[index].original_index << " - Passed index: " << index << std::endl;
// 		std::cout << "Number pairs:" << std::endl;
// 		printPairs(number_pairs, big_numbers);
// 		std::cout << "Updated pairs:" << std::endl;
// 		printPairs(updated_pairs, big_numbers);
// 	}

// 	if (index < 0 || index >= (int)number_pairs.size())
// 		return ;

// 	int i  = number_pairs[index].original_index - 1;
// 	while (i >= 0)
// 	{
// 		if (number_pairs[index].small >= big_numbers[i])
// 			break ;
// 		--i;
// 	}
// 	big_numbers.insert(big_numbers.begin() + i + 1, number_pairs[index].small);
// 	updated_pairs.insert(updated_pairs.begin() + i + 1, previous_pairs[index]);
// 	// for (size_t o = i + 2; i < updated_pairs.size(); ++i)
// 	// {

// 	// }
// }








std::vector<int> PmergeMe::vectorSortElements(std::vector<int>& numbers)
{
	if (numbers.size() <= 1)
		return numbers;

	std::vector<indexedPair> pairs;
	std::vector<int> big_numbers;

	// Step 1: Form pairs and extract bigs
	for (size_t i = 0; i + 1 < numbers.size(); i += 2) {
		int a = numbers[i];
		int b = numbers[i + 1];

		indexedPair p;
		if (a >= b) {
			p.big = a;
			p.small = b;
		} else {
			p.big = b;
			p.small = a;
		}
		pairs.push_back(p);
		big_numbers.push_back(p.big);
	}

	// Store leftover if input has odd size
	bool has_remainder = (numbers.size() % 2 != 0);
	int leftover = has_remainder ? numbers.back() : -1;

	// Step 2: Recursively sort bigs
	std::vector<int> sorted_bigs = vectorSortElements(big_numbers);

	// Step 3: Mirror order — map index from sorted_bigs back to pairs
	std::vector<indexedPair> mirrored_pairs;
	for (int sorted_big : sorted_bigs) {
		for (size_t i = 0; i < pairs.size(); ++i) {
			if (pairs[i].big == sorted_big) {
				mirrored_pairs.push_back(pairs[i]);
				// Invalidate so duplicates don’t match again
				pairs[i].big = -99999999;
				break;
			}
		}
	}

	// Step 4: Jacobsthal order (excluding index 0)
	std::vector<int> jacobsthal_order = getJacobsthalSequence(mirrored_pairs.size());

	// Step 5: Insert smalls
	std::vector<int> result = sorted_bigs;
	vectorInsert(result, mirrored_pairs, jacobsthal_order);

	// Step 6: Add leftover if present
	if (has_remainder) {
		auto pos = std::lower_bound(result.begin(), result.end(), leftover);
		result.insert(pos, leftover);
	}

	return result;
}



void PmergeMe::vectorInsert(std::vector<int>& result, const std::vector<indexedPair>& mirrored_pairs, const std::vector<int>& jacobsthal_sequence)
{
	if (mirrored_pairs.empty())
		return;

	// Always insert the first small value at the beginning
	result.insert(result.begin(), mirrored_pairs[0].small);

	// Insert the rest based on Jacobsthal sequence
	for (size_t i = 0; i < jacobsthal_sequence.size(); ++i)
	{
		int idx = jacobsthal_sequence[i];
		if ((size_t)idx >= mirrored_pairs.size())
			continue;

		int small = mirrored_pairs[idx].small;
		auto pos = std::lower_bound(result.begin(), result.end(), small);
		result.insert(pos, small);
	}
}







// void	createVectorPairs(const std::vector<int>& numbers, std::vector<int>& big_numbers, pairVector& number_pairs)
// {
// 	int			big;
// 	int			small;
// 	int			pair_index = 0;

// 	for (size_t i = 0; i + 1 < numbers.size(); i += 2)
// 	{
// 		indexedPair new_pair;

// 		if (numbers[i] >= numbers[i + 1])
// 		{
// 			big = numbers[i];
// 			small = numbers[i + 1];
// 		}
// 		else
// 		{
// 			big = numbers[i + 1];
// 			small = numbers[i];
// 		}
// 		big_numbers.push_back(big);
// 		new_pair.big = big;
// 		new_pair.small = small;
// 		new_pair.original_index = pair_index;
// 		number_pairs.push_back(new_pair);
// 		pair_index++;
// 	}
// }


// std::vector<int>	PmergeMe::vectorSortElements(std::vector<int>& numbers, pairVector& previous_pairs)
// {
// 	std::vector<int>	big_numbers;
// 	pairVector			number_pairs;
// 	int					left_over_num = -1;

// 	if (numbers.size() <= 3)
// 	{
// 		big_numbers.push_back(std::min(numbers[0], numbers[1]));
// 		big_numbers.push_back(std::max(numbers[0], numbers[1]));
// 		if (numbers.size() == 3)
// 			left_over_num = numbers[2];
// 	}

// 	// Step 1 - create pairs & store left-over num if there is one
// 	if (numbers.size() >= 4)
// 		createVectorPairs(numbers, big_numbers, number_pairs);
// 	if (numbers.size() % 2 != 0)
// 		left_over_num = numbers.back();


// 	// step 2 - If we have multiple pairs to make
// 	if (numbers.size() >= 4)
// 		big_numbers = vectorSortElements(big_numbers, number_pairs);
	






// 	return (big_numbers);
// }


// void	PmergeMe::vectorInsert(std::vector<int>& big_numbers, pairVector& number_pairs, pairVector& previous_pairs, pairVector& updated_pairs, int index)
// {
// 	{	// TESTING ---
// 		std::cout << "Big number size: " << big_numbers.size() << std::endl;
// 		std::cout << "Vector bignum: ";
// 		for (int element : big_numbers)
// 			std::cout << element << " ";
// 		std::cout << std::endl;
// 		std::cout << "Pair to insert: " << number_pairs[index].small << " / " << number_pairs[index].big << " - Index: " << number_pairs[index].original_index << " - Passed index: " << index << std::endl;
// 		std::cout << "Number pairs:" << std::endl;
// 		printPairs(number_pairs, big_numbers);
// 		std::cout << "Updated pairs:" << std::endl;
// 		printPairs(updated_pairs, big_numbers);
// 	}

// 	if (index < 0 || index >= (int)number_pairs.size())
// 		return ;

// 	int i  = number_pairs[index].original_index - 1;
// 	while (i >= 0)
// 	{
// 		if (number_pairs[index].small >= big_numbers[i])
// 			break ;
// 		--i;
// 	}
// 	big_numbers.insert(big_numbers.begin() + i + 1, number_pairs[index].small);
// 	updated_pairs.insert(updated_pairs.begin() + i + 1, previous_pairs[index]);
// 	// for (size_t o = i + 2; i < updated_pairs.size(); ++i)
// 	// {

// 	// }
// }








// std::vector<int>	PmergeMe::vectorSortElements(std::vector<int>& numbers)
// {
// 	pairVector dummy;
// 	return (vectorSortElements(numbers, dummy));
// }


void	PmergeMe::vectorSorting()
{
	// getTime(VECTOR, START);
	this->vectorParse();
	_vector_sorted = this->vectorSortElements(_vector);

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
