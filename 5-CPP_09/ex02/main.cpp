#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	try
	{
		PmergeMe pMerge(argc, argv);

		pMerge.checkInput();
		if (DEBUG)
			std::cout << "----------------------VECTOR---------------------" << std::endl;
		pMerge.vectorSorting();
		
		if (DEBUG)
			std::cout << "\n\n----------------------DEQUE----------------------" << std::endl;
		pMerge.dequeSorting();
		pMerge.printResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
