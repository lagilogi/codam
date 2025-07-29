#pragma once

#include <iostream>
#include <stack>
#include <list>

template<class T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() = default;
		~MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		MutantStack& operator=(const MutantStack& other) = default;

		using iterator = typename std::stack<T, Container>::container_type::iterator;
		using c_iterator = typename std::stack<T, Container>::container_type::const_iterator;
		using r_iterator = typename std::stack<T, Container>::container_type::reverse_iterator;
		using c_r_iterator = typename std::stack<T, Container>::container_type::const_reverse_iterator;

		// iterator (begin / end)
		iterator begin();
		iterator end();
		

		// const iterator (begin / end)
		c_iterator begin() const;
		c_iterator end() const;


		// reverse iterator (begin / end)
		r_iterator rbegin();
		r_iterator rend();
		

		// const reverse iterator (begin / end)
		c_r_iterator rbegin() const;
		c_r_iterator rend() const;

};

#include "MutantStack.tpp"
