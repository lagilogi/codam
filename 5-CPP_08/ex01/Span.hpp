#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>


class Span
{
	private:
		unsigned int		_maxN;
		std::vector<int>	_vector;

	public:
		Span();
		Span(unsigned int size);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void	addNumber(int num);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
};



