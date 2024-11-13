#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; argv[i] != NULL; i++)
			std::cout << argv[i];
	std::cout << '\n';
	return 0;
}

