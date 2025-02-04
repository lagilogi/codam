#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "header.hpp"

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& temp);

		const std::string& getIdea(int index) const;
		void setIdea(std::string& idea, int index);
};

#endif