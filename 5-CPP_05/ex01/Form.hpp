#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		const int			_requiredSign;
		const int			_requiredExec;
		bool				_signed;

	public:
		Form(std::string name = "B-2718", int rSign = 10, int rExec = 10);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		const std::string&	getName() const;
		int					getRequiredSign() const;
		int					getRequiredExec() const;
		bool				getSigned() const;

		void				beSigned(const Bureaucrat& bc);

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

std::ostream& operator<<(std::ostream& output, const Form& form);