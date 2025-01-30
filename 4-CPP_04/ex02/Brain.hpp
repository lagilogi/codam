#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "header.hpp"

class Brain
{
	public:
		std::string _ideas[100];
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& temp);
};

#endif