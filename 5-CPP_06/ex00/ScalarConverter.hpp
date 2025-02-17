#pragma once

#include <iostream>
#include <climits>
#include <cfloat>

enum type_e : char
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	PSEUDO = 4
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

	public:
		static void convert(const std::string& input);
};
