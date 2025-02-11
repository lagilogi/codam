#pragma once

#include "headers.hpp"

class AForm;

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

		const std::string&	getName() const;
		int					getGrade() const;

		void				signForm(AForm& form);
		void				executeForm(AForm const& form);

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() override;
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() override;
		};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);
