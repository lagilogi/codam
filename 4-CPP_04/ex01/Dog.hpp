#ifndef	DOG_HPP
# define DOG_HPP

#include "header.hpp"

class Dog : public Animal
{
	private:
		Brain* _DogBrain;

	public:
		Dog();
		~Dog() override;
		Dog(const Dog& other);
		Dog& operator=(const Dog& temp);

		void				makeSound() const override;
		void				setIdeas(int i, std::string idea);
		const std::string&	getIdeas(int i) const;
};

#endif