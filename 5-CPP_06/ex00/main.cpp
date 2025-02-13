#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid input - Pass a char(w), int(42), float(42.0f), double(42.0) or pseudo(nan)" << std::endl;
		return (1);
	}
	for (int i = 0; argv[1][i]; ++i)
	{
		if (!isprint(argv[1][i]) && !isspace(argv[1][i]))
		{
			std::cerr << "Invalid input - Only use displayable characters" << std::endl;
			return (1);
		}
	}
	std::string input = argv[1];
	if (input.empty())
	{
		std::cerr << "Invalid input - Empty strings not allowed" << std::endl;
		return (1);
	}
	ScalarConverter::convert(input);
}
