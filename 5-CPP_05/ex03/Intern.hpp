#pragma once

#include "headers.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string formName, std::string targetName);

		class NonexistentFormException : public std::exception
		{
			public:
				const char* what() const throw() override;
		};
};