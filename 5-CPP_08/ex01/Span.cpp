#include "Span.hpp"

Span::Span() : _maxN()
{
	std::cout << "Span object created" << std::endl;
}

Span::Span(unsigned int size) : _maxN(size)
{
	std::cout << "Span object created with size " << size << std::endl;
}

Span::~Span()
{
	std::cout << "Span object destructed" << std::endl;
}

Span::Span(const Span& other)
{
	for (int num : other._vector)
		this->_vector.push_back(num);
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
		for (int num : other._vector)
			this->_vector.push_back(num);
	return (*this);
}

void	Span::addNumber(int num)
{
	if (_vector.size() == _maxN)
	{
		std::cout << "Span already full" << std::endl;
		return ;
	}
	_vector.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((_vector.size() + std::distance(begin, end)) > _maxN)
	{
		std::cout << "Too many elements to add" << std::endl;
		return ;
	}

	for (std::vector<int>::iterator it = begin; it != end; ++it)
		_vector.push_back(*it);
	std::cout << "All numbers added- new list:" << std::endl;
	for (int n : _vector)
		std::cout << n << " ";
	std::cout << std::endl;
}


int	Span::shortestSpan()
{
	std::vector<int> sorted = _vector;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int> diffVector;
	int size = _vector.size();

	for (int i = 0; i < size; ++i)
	{
		if (i == 0)
			continue ;
		diffVector.push_back(sorted[i] - sorted[i - 1]);
	}

	return *std::min_element(diffVector.begin(), diffVector.end());
}

int Span::longestSpan()
{
	int max = *std::max_element(_vector.begin(), _vector.end());
	int min = *std::min_element(_vector.begin(), _vector.end());

	return (max - min);
}
