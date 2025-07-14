#pragma once

#include <iostream>
#include <stack>

enum characters
{
	SPACE = 0,
	NUMBER = 1,
	OPERATOR = 2,
	INVALID_CHAR = -1
};

void	RPN(std::string input);
