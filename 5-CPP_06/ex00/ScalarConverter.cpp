#include "ScalarConverter.hpp"

/* Constructor & destructor */
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

/* Copy constructors */
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}


/* Type checks */
int checkIfInt(const std::string& input, int strlen)
{
	int i = 0;

	if (input[0] == '-')
		++i;
	while (i < strlen)
		if (!isdigit(input[i++]))
			return (0);
	return (INT);
}

int	checkIfFloat(const std::string& input, int strlen)
{
	int dotcount = 0;
	int i = 0;

	if (input.back() != 'f' || input.find('.') == std::string::npos)
		return (0);
	if (input[0] == '-')
		++i;
	while (i < strlen)
	{
		if (input[i] == '.')
		{
			++dotcount;
			if (!isdigit(input[i + 1]) || dotcount > 1)
				return (-1);
		}
		else if (!isdigit(input[i]) && i < strlen - 1)
			return (-1);
		i++;
	}
	return (FLOAT);
}

int checkIfDouble(const std::string& input, int strlen)
{
	int dotcount = 0;
	int i = 0;

	if (input.find('.') == std::string::npos)
		return (0);
	if (input[0] == '-')
		++i;
	while (i < strlen)
	{
		if (input[i] == '.')
		{
			++dotcount;
			if (dotcount > 1)
				return (-1);
		}
		else if (!isdigit(input[i]))
			return (0);
		i++;
	}
	return (DOUBLE);
}

int checkIfPseudo(const std::string& input)
{
	if (input == "-inf" || input == "+inf" || input == "nan"
		|| input == "-inff" || input == "+inff" || input == "nanf")
		return (PSEUDO);
	return (-1);
}


/* Converters */
void	charConverter(const std::string& input)
{
	char	c = input[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	std::cout << "Char: " << c
			<< "\nInt: " << i
			<< "\nFloat: " << f << ".0f"
			<< "\nDouble: " << d << ".0" << std::endl;
}

void	intConverter(const std::string& input)
{
	try
	{
		int integer = std::stoi(input);
		if (integer < 30 || integer > 127)
			std::cout << "Char: Non displayable";
		else
			std::cout << "Char: " << static_cast<char>(integer);
		std::cout << "\nInt: " << integer
				<< "\nFloat: " << static_cast<float>(integer) << ".0f"
				<< "\nDouble: " << static_cast<double>(integer) << ".0" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "This integer overflows resulting in:\n"
				<< "Char: Impossible\n"
				<< "Int: Impossible\n"
				<< "Float: Impossible\n"
				<< "Double: Impossible" << std::endl;
	}
}

void	floatConverter(const std::string& input)
{
	try
	{
		float	floatNum = std::stof(input);
		long	integerRep = static_cast<long>(floatNum);
		size_t	dotPos = input.find('.');

		if (integerRep < 30 || integerRep > 127)
			std::cout << "Char: Non displayable";
		else
			std::cout << "Char: " << static_cast<char>(floatNum);
		if (dotPos > 9 || integerRep < INT_MIN || integerRep > INT_MAX)
			std::cout << "\nInt: Impossible";
		else
			std::cout << "\nInt: " << integerRep;
		if (floatNum - static_cast<int>(floatNum) == 0 || dotPos > 6)
		{
			std::cout << "\nFloat: " << floatNum << ".0f"
						<< "\nDouble: " << static_cast<double>(floatNum) << ".0" << std::endl;
		}
		else
		{
			std::cout << "\nFloat: " << floatNum << "f"
						<< "\nDouble: " << static_cast<double>(floatNum) << std::endl;					
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "This float overflows resulting in:\n"
				<< "Char: Impossible\n"
				<< "Int: Impossible\n"
				<< "Float: Impossible\n"
				<< "Double: Impossible" << std::endl;
	}
}

void	doubleConverter(const std::string& input)
{
	try
	{
		double	doubleNum = std::stod(input);
		long	integerRep = static_cast<long>(doubleNum);
		size_t	dotPos = input.find('.');

		if (integerRep < 30 || integerRep > 127)
			std::cout << "Char: Non displayable";
		else
			std::cout << "Char: " << static_cast<char>(doubleNum);
		if (dotPos > 9 || integerRep < INT_MIN || integerRep > INT_MAX)
			std::cout << "\nInt: Impossible";
		else
			std::cout << "\nInt: " << integerRep;
		if (doubleNum - static_cast<int>(doubleNum) == 0 || dotPos > 6)
		{
			std::cout << "\nFloat: " << static_cast<float>(doubleNum) << ".0f"
						<< "\nDouble: " << doubleNum << ".0" << std::endl;
		}
		else
		{
			std::cout << "\nFloat: " << static_cast<float>(doubleNum) << "f"
						<< "\nDouble: " << doubleNum << std::endl;					
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "This double overflows resulting in:\n"
				<< "Char: Impossible\n"
				<< "Int: Impossible\n"
				<< "Float: Impossible\n"
				<< "Double: Impossible" << std::endl;
	}
}

void	pseudoConverter(const std::string& input)
{
	std::string array[6] = {"-inf", "-inff", "+inf", "+inff", "nan", "nanf" };
	int i, o;
	for (i = 0; i < 6; ++i)
		if (input == array[i])
			break ;
	if (i % 2 == 0)
		i++;
	o = i - 1;
	std::cout << "Char: Impossible"
			<< "\nInt: Impossible"
			<< "\nFloat: " << array[i]
			<< "\nDouble: " << array[o] << std::endl;
}






/* Switch and if statements */
int	typeCheck(const std::string& input)
{
	int	valid;
	int	strlen = input.length();

	if (strlen == 1)
		if (!isdigit(input[0]))
			return (CHAR);
	valid = checkIfInt(input, strlen);
	if (valid != 0)
		return (valid);
	valid = checkIfFloat(input, strlen);
	if (valid != 0)
		return (valid);
	valid = checkIfDouble(input, strlen);
	if (valid != 0)
		return (valid);
	return (checkIfPseudo(input));
}

void	ScalarConverter::convert(const std::string& input)
{
	int inputType = typeCheck(input);
	switch (inputType)
	{
		case CHAR:
			charConverter(input);
			break;
		case INT:
			intConverter(input);
			break;
		case FLOAT:
			floatConverter(input);
			break;
		case DOUBLE:
			doubleConverter(input);
			break;
		case PSEUDO:
			pseudoConverter(input);
			break;
		default:
			std::cerr << "Invalid input - Pass a char(w), int(42), float(42.0f) or double(42.0)" << std::endl;
	}
}
