#pragma once

#include "headers.hpp"

class AForm
{
	private:
		const std::string	_name;
		const int			_requiredSign;
		const int			_requiredExec;
		bool				_signed;

	public:
		AForm(std::string name = "B-2718", int rSign = 10, int rExec = 10);
		~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		const std::string&	getName() const;
		int					getRequiredSign() const;
		int					getRequiredExec() const;
		bool				getSigned() const;

		virtual void		beSigned(const Bureaucrat& bc);
		virtual void		execute(Bureaucrat const& executor) const = 0;

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
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw() override;
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw() override;
		};
		class FileErrorException : public std::exception
		{
			public:
				const char* what() const throw() override;
		};
};

std::ostream& operator<<(std::ostream& output, const AForm& form);