#include "BitcoinExchange.hpp"

int	fileExists(char* file)
{
	int correct_files = 0;

	std::ifstream data_file("data.csv");
	if (data_file.good())
		correct_files++;
	else
		std::cerr << "ERROR: data.csv does not exist" << std::endl;
	
	std::ifstream input_file(file);
	if (input_file.good())
		correct_files++;
	else
		std::cerr << "ERROR: could not open input file" << std::endl;
	
	return (correct_files);
}

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		if (fileExists(argv[1]) < 2)
			return (1);
		try
		{
			BitcoinExchange btc;
			if (btc.parseDataCsvFile() == false)
				return (1);
			btc.printValueTotal(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (1);
		}
	}
	else
		std::cerr << "ERROR: Invalid amount of arguments (" << argc - 1 << ") - Needs 1 input file!" << std::endl;
	
	return (0);
}