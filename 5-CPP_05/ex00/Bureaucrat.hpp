#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(const std::string name = "NoName", int grade = 150);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& temp);

		Bureaucrat& operator++();	// ++x assignment operator overload
		Bureaucrat operator++(int);	// x++ assignment operator overload
		Bureaucrat& operator--();	// --x assignment operator overload
		Bureaucrat operator--(int);	// x-- assignment operator overload

		const std::string& getName() const;
		int getGrade() const;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);
