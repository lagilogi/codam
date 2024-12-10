/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:45:34 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/10 17:29:05 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	search_command(PhoneBook *phonebook)
{

	
}

static void	add_command(PhoneBook *phonebook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickame;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter first name: ";
	
}

static int	command(PhoneBook *phonebook, std::string cmd, int cmd_len)
{
	for (int i = 0; i < cmd_len; i++)
		cmd[i] = std::toupper(cmd[i]);
	if (cmd == "ADD")
		add_command(phonebook);
	else if (cmd == "SEARCH")
		search_command(phonebook);
	else if (cmd == "EXIT")
		return 3;
	else
		std::cout << "Error: Not a valid command!\n";
	return 0;
}

int	main()
{
	PhoneBook	phonebook;
	std::string	cmd;
	int			cmd_len;

	startup_messages();
	do {
		std::cout << "\nWhat would you like to do?: ";
		getline(std::cin, cmd);
		if (cmd.empty())
			std::cout << "Error: Empty command\n";
		cmd_len = cmd.length();
	} while (command(&phonebook, cmd, cmd_len) != 3);

	return 0;
}
