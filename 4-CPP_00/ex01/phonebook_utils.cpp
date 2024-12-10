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
