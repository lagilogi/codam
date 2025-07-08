#include "MutantStack.hpp"


int main()
{
	MutantStack<int> mutantStack;
	std::list<int>  listStack;

	mutantStack.push(5);		listStack.push_back(5);
	mutantStack.push(17);		listStack.push_back(17);

	std::cout << "mutantStack: " << mutantStack.top() << " - list: " << listStack.back() << std::endl;

	mutantStack.pop();			listStack.pop_back();

	std::cout << "mutantStack: " << mutantStack.size() << " - list: " << listStack.size() << std::endl;

	mutantStack.push(3);		listStack.push_back(3);
	mutantStack.push(5);		listStack.push_back(5);
	mutantStack.push(737);		listStack.push_back(737);
	mutantStack.push(0);		listStack.push_back(0);

	MutantStack<int>::iterator it = mutantStack.begin();
	MutantStack<int>::iterator ite = mutantStack.end();
	std::list<int>::iterator l_it = listStack.begin();
	std::list<int>::iterator l_ite = listStack.end();

	std::cout << "\n__LOOPS___" << std::endl;
	while (it != ite)
	{
		std::cout << "MutantStack: " << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	while (l_it != l_ite)
	{
		std::cout << "listStack: " << *l_it << std::endl;
		++l_it;
	}


	it = mutantStack.begin();
	ite = mutantStack.end();
	l_it = listStack.begin();
	l_ite = listStack.end();

	++it;
	--ite;

	++l_it;
	--l_ite;

	std::cout << "\n__LOOPS 2___" << std::endl;
	while (it != ite)
	{
		std::cout << "MutantStack: " << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	while (l_it != l_ite)
	{
		std::cout << "listStack: " << *l_it << std::endl;
		++l_it;
	}

	std::stack<int> s(mutantStack);

	return 0;
}