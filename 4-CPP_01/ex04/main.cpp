/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:17:50 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/13 16:24:08 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	find_and_replace(std::string &line, const std::string &str1, const std::string &str2)
{
	int str1_len = str1.length();
	int pos = 0;
	do {
		pos = line.find(str1, pos);
		if (pos > -1) {
			line.erase(pos, str1_len);
			line.insert(pos, str2);
			pos += str2.length();
		}
	} while (pos != -1);
}

int	check_input(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Error: Invalid amount of arguments" << std::endl;
		return 1;
	}
	if (argv[1][0] == '\0' || argv[2][0] == '\0') {
		std::cout << "Error: Input strings cannot be empty" << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (check_input(argc, argv) == 1)
		return 1;

	std::string file = argv[1];
	std::string str1(argv[2]);
	std::string str2(argv[3]);
	std::ifstream oldfile(file);
	if (!oldfile.is_open()) {
		std::cout << "Error: File [" << file << "] not found" << std::endl;
		return 1;
	}
	std::ofstream newfile(file + ".replace");
	if (!newfile.is_open()) {
		std::cout << "Error: Couldn't create or open new file" << std::endl;
		return 1;
	}

	std::string line(1024, '\0');
	while (oldfile.good())
	{
		oldfile.read(&line[0], 1024);
		find_and_replace(line, str1, str2);
		line.resize(oldfile.gcount());
		newfile << line;
	}
	newfile.close();
	oldfile.close();
	return 0;
}
