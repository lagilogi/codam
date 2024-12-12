/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook_utils.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:45:56 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/10 15:53:33 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	startup_messages()
{
	std::cout << "\n**** Welcome to the PhoneBook ****\n";
	std::cout << "\nYou can ADD, SEARCH or EXIT the PhoneBook\n";
	std::cout << "\nType:\n";
	std::cout << "ADD    - to add a contact\n";
	std::cout << "SEARCH - to search a contact\n";
	std::cout << "EXIT   - to exit the phonebook\n";
	std::cout << "\nThe Phonebook is currently empty. We suggest adding a contact\n";
}

void	add_messages(int i)
{
	if (i == 0)
		std::cout << "\nEnter first name: ";
	else if (i == 1)
		std::cout << "\nEnter last name: ";
	else if (i == 2)
		std::cout << "\nEnter nickname: ";
	else if (i == 3)
		std::cout << "\nEnter phone number: ";
	else if (i == 4)
		std::cout << "\nEnter your darkest secret: ";
	else if (i == 5)
		std::cout << "\nError: Field cannot be empty";
	else if (i == 6)
		std::cout << "\nError: Phone numbers can only consist of numbers";
}

int	check_phonenumber(std::string phoneNumber)
{
	for (int o = 0; phoneNumber[o] != '\0'; o++){
		if (!isdigit(phoneNumber[o]))
			add_messages(5);
			return 1;
	}
}
