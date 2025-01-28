#ifndef	WRONGCAT_HPP
# define WRONGCAT_HPP

#include "header.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& temp);

		void	makeSound() const;
};

#endif