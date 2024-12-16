/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:45:34 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/16 14:41:42 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	startup_messages()
{
	std::cout	<< "\n**** Welcome to the PhoneBook ****\n"
				<< "\nYou can ADD, SEARCH or EXIT the PhoneBook\n"
				<< "\nType:\n"
				<< "ADD    - to add a contact\n"
				<< "SEARCH - to search a contact\n"
				<< "EXIT   - to exit the phonebook\n"
				<< "\nThe Phonebook is currently empty. We suggest adding a contact"
				<< std::endl;
}

static void	search_command(PhoneBook &phonebook)
{
	std::string	input;
	int			index;
	int			x = 0;


	if (phonebook.getContact_amount() == 0) {
		std::cout << "\n>> There are no contacts in the phonebook\n";
		return ;
	}
	phonebook.getList();
	std::cout << "\nWhat contact would you like the details of?\n";
	do {
		std::cout << "Enter index: ";
		getline(std::cin, input);
		if (input.length() != 1 || !isdigit(input[0])) {
			std::cout << "\nError: invalid index\n";
			continue ;
		}
		else
			index = std::stoi(input);
		if (index > phonebook.getContact_amount() || index < 1) {
			std::cout << "\nError: invalid index\n";
			continue ;
		}
		x = 1;
	} while (x == 0);
	phonebook.getDetails(index);
}

static void	add_command(PhoneBook &phonebook)
{
	static int	index = 0;
	phonebook.setDetails(index);
	index++;
	if (phonebook.getContact_amount() < 8)
		std::cout << "\n>> You have added contact #" << index;
	else
		std::cout << "\n>> You have overwritten contact #" << index;
	if (index == 8)
		index = 0;
	phonebook.setContact_amount();
}

static int	command(PhoneBook &phonebook, std::string cmd)
{
	int	cmd_len;

	if (cmd.empty()) {
		std::cout << "\nError: Empty command";
		return 0;
	}
	cmd_len = cmd.length();
	for (int i = 0; i < cmd_len; i++)
		cmd[i] = std::toupper(cmd[i]);
	if (cmd == "ADD")
		add_command(phonebook);
	else if (cmd == "SEARCH")
		search_command(phonebook);
	else if (cmd == "EXIT")
		return 3;
	else
		std::cout << "Error: Not a valid command" << std::endl;
	return 0;
}

int	main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	startup_messages();
	do {
		std::cout << "\nWhat would you like to do?: ";
		getline(std::cin, cmd);
	} while (command(phonebook, cmd) != 3);
	std::cout << "Exited phonebook\n";

	return 0;
}
