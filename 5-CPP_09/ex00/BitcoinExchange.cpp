#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_database_map = other._database_map;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	this->_database_map = other._database_map;
	return (*this);
}


bool	BitcoinExchange::parseDataCsvFile()
{
	std::ifstream data_file("data.csv");
	if (!data_file.is_open())
		std::cerr << "Error: Couldn't open data.csv" << std::endl;

	std::string input;

	while (std::getline(data_file, input))
	{
		if (input.empty() || input == "date,exchange_rate")
			continue ;
		if (!inputSplitter(input, ','))
			return (false);
		auto result = _database_map.insert({_date, _value});
		if (!result.second)
			std::cerr << "Error: duplicate date found in data.csv" << std::endl;
	}
	return (true);
}






void	BitcoinExchange::printValueTotal(char* file)
{
	std::ifstream input_file(file);
	if (!input_file.is_open())
		throw std::ios_base::failure("Error: Couldn't open input file");

	std::string input;

	while (std::getline(input_file, input))
	{
		if (input.empty() || input == "date | value")
			continue ;
		if (!inputSplitter(input, '|'))
			continue ;

		auto it = _database_map.lower_bound(_date);
		if (it->first == _date)
			std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl;
		else if (it == _database_map.end())
			std::cerr << "Error: date in the future => " << _date << std::endl;
		else if (it == _database_map.begin() && _date < it->first)
			std::cerr << "Error: date too early => " << _date << std::endl;
		else
		{
			--it;
			std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl;
		}
	}
}

bool	BitcoinExchange::checkDate()
{
	if (_date.size() != 10 || _date[4] != '-' || _date[7] != '-')
	{
		std::cerr << "Error: bad input => " << _date << std::endl;
		return (false);
	}
	for (int i = 0; i < 10; ++i)
	{
		if (i != 4 && i != 7)
			if (_date[i] < '0' || _date[i] > '9')
			{
				std::cerr << "Error: bad input => " << _date << std::endl;
				return (false);
			}
	}
	char dash;
	std::stringstream ss(_date);

	struct tm date = {};

	ss >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday;
	date.tm_year -=  1900;
	date.tm_mon -= 1;
	date.tm_hour = 1;
	date.tm_min = 0;
	date.tm_sec = 0;

	struct tm new_date = date;
	mktime(&new_date);

	if (date.tm_year == new_date.tm_year && date.tm_mon == new_date.tm_mon && date.tm_mday == new_date.tm_mday)
		return (true);

	std::cerr << "Error: bad input => " << _date << std::endl;
	return (false);
}





// Not sure if I need to check if the csv data values above 1000 are als too large..

bool BitcoinExchange::checkValue(std::string valueStr, bool input_check)
{
	if (valueStr.empty())
		return (false);
	char* ptr;
	strtof(valueStr.c_str(), &ptr);
	if (*ptr != '\0')
	{
		std::cout << "Error: not a number => " << valueStr << std::endl;
		return (false);
	}
	try
	{
		_value = std::stof(valueStr);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: could not convert number => " << valueStr << std::endl;
		return (false);
	}
	if (_value < 0)
	{
		std::cerr << "Error: not a positive number => " << _value << std::endl;
		return (false);
	}
	if (input_check == true && _value > 1000)
	{
		std::cerr << "Error: too large a number => " << _value << std::endl;
		return (false);
	}
	return (true);
}


bool	BitcoinExchange::inputSplitter(std::string& input, char delim)
{
	std::string valueStr;
	
	size_t i = input.find(delim);

	if (i == std::string::npos)
	{
		std::cerr << "Error: bad input => " << input << std::endl;
		return (false);
	}
	_date = input.substr(0, i); 
	valueStr = input.substr(i + 1);

	size_t start = this->_date.find_first_not_of(" \t\n\r\f\v");
	size_t end = this->_date.find_last_not_of(" \t\n\r\f\v");
	if (start == std::string::npos) {
		std::cerr << "Error: bad input => " << input << std::endl;
		return (false);
	}

	this->_date = this->_date.substr(start, end - start + 1);
	if (!checkDate())
		return (false);

	start = valueStr.find_first_not_of(" \t\n\r\f\v");
	end = valueStr.find_last_not_of(" \t\n\r\f\v");
	if (start == std::string::npos) {
		std::cerr << "Error: bad input => " << input << std::endl;
		return (false);
	}
	valueStr = valueStr.substr(start, end - start + 1);
	if (delim == '|')
	{
		if (!checkValue(valueStr, true))
			return (false);
	}
	else if (delim == ',')
	{
		if (!checkValue(valueStr, false))
			return (false);
	}
	return (true);
}
