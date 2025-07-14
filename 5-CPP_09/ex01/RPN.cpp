#include "RPN.hpp"

int checkIfValidCharacter(char c)
{
	std::string	numbers = "0123456789";
	std::string operators = "+-/*";

	if (c == ' ')
		return (SPACE);
	else if (numbers.find(c) != std::string::npos)
		return (NUMBER);
	else if (operators.find(c) != std::string::npos)
		return (OPERATOR);
	return (INVALID_CHAR);
}

void	calculate(std::stack<float>& numbers, char c)
{
	float num1 = numbers.top();
	numbers.pop();
	float num2 = numbers.top();
	numbers.pop();

	if (c == '*')
		numbers.push(num2 * num1);
	else if (c == '/')
		numbers.push(num2 / num1);
	else if (c == '+')
		numbers.push(num2 + num1);
	else if (c == '-')
		numbers.push(num2 - num1);
}

void	RPN(std::string input)
{
	if (input.empty())
		throw std::runtime_error("Error: empty input");

	std::stack<float>	numbers;
	int					char_type;

	for (size_t i = 0; i < input.size(); ++i)
	{
		char_type = checkIfValidCharacter(input[i]);
		if (char_type == INVALID_CHAR)
			throw std::runtime_error("Error: invalid character");
		else if (char_type != SPACE && input[i + 1] != ' ' && input[i + 1] != '\0')
			throw std::runtime_error("Error: invalid input - Need spaces between characters");
		if (char_type == NUMBER)
			numbers.push(input[i] - '0');
		else if (char_type == OPERATOR)
		{
			if (numbers.size() < 2)
				throw std::runtime_error("Error: not enough numbers for operation");
			else if (numbers.top() == 0 && input[i] == '/')
				throw std::runtime_error("Error: can't divide by 0");
			calculate(numbers, input[i]);
		}
	}
	if (numbers.size() > 1)
		throw std::runtime_error("Error: not enough operators to calculate");
	std::cout << numbers.top() << std::endl;
}
