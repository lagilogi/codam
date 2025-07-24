#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		try
		{
			PmergeMe pMerge(argv[1]);

			pMerge.checkInput();
			pMerge.vectorSorting();
			// pMerge.dequeSort();
			// pMerge.printResult();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: invalid amount of arguments - should be 2" << std::endl;
	return (1);
}
