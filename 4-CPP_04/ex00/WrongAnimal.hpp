#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "header.hpp"

class WrongAnimal {
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& temp);

		const std::string& getType() const;

		void	makeSound() const;
};

#endif