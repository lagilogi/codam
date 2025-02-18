#include "iter.hpp"

int main()
{
	int x[] = { 1, 2, 3, 4, 5 };
	::iter(x, sizeof(x) / sizeof(int), printer);	std::cout << std::endl;

	float y[] = { 1.2, 2.8, 3.1, 4.5, 5.9 };
	::iter(y, sizeof(y) / sizeof(float), printer);	std::cout << std::endl;

	char z[] = { 'c', 'H', 'o', '!', ']'};
	::iter(z, sizeof(z) / sizeof(char), printer);	std::cout << std::endl;

	std::string v[] = { "hello", "World!", "1234567890z", "094u389hngjtr", "Hmmm.."};
	::iter(v, sizeof(v) / sizeof(std::string), printer);

}