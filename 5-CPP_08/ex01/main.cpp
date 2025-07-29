#include "Span.hpp"

int main()
{
	Span sp = Span(8);
	std::vector<int> x = { 1, 2, 100};
	std::vector<int> y = { 67, 83, 22, 45, 512, 79 };

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(x.begin(), x.end());
	sp.addNumber(y.begin(), y.end());
	sp.addNumber(300);

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl;

	Span sp2 = Span(10000);
	std::srand(time(0));
	for (int i = 0; i < 10000; ++i)
		sp2.addNumber(rand());

	return 0;
}
