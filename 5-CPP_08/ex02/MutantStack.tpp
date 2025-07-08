#include "MutantStack.hpp"

template<class T, class Container>
typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template<class T, class Container>
typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template<class T, class Container>
typename std::stack<T, Container>::container_type::const_iterator MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template<class T, class Container>
typename std::stack<T, Container>::container_type::const_iterator MutantStack<T, Container>::end() const
{
	return (this->c.end());
}


template<class T, class Container>
typename std::stack<T, Container>::container_type::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template<class T, class Container>
typename std::stack<T, Container>::container_type::reverse_iterator MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

template<class T, class Container>
typename std::stack<T, Container>::container_type::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template<class T, class Container>
typename std::stack<T, Container>::container_type::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return (this->c.rend());
}