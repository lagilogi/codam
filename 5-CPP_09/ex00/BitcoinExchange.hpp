#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>


class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database_map;
		std::string						_date;
		float							_value;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		bool	parseDataCsvFile();
		void	printValueTotal(char* input_file);
		bool	checkDate();
		bool	checkValue(std::string value, bool input_check);
		bool	inputSplitter(std::string& input, char delim);

};

