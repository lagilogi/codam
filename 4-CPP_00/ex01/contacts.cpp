/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contacts.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:16:07 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/16 15:44:31 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

void	Contacts::add_messages(int i) const
{
	if (i == 0)
		std::cout << "\nEnter first name: ";
	else if (i == 1)
		std::cout << "Enter last name: ";
	else if (i == 2)
		std::cout << "Enter nickname: ";
	else if (i == 3)
		std::cout << "Enter phone number: ";
	else if (i == 4)
		std::cout << "Enter your darkest secret: ";
	else if (i == 5)
		std::cout << "\nError: Field cannot be empty\n";
	else if (i == 6)
		std::cout << "\nError: Phone numbers can only consist of numbers\n";
}

int	Contacts::check_phonenumber(std::string phoneNumber) const
{
	int	len = phoneNumber.length();
	for (int o = 0; o < len; o++){
		if (!isdigit(phoneNumber[o]))
			return 1;
	}
	return 0;
}

void	Contacts::setDetails(int index) {
	this->index = index + 1;
	int	i = 0;
	while (i < 5) {
		add_messages(i);
		getline(std::cin, details[i]);
		if (details[i].empty()) {
			add_messages(5);
			continue;
		}
		else if (i == 3 && check_phonenumber(details[i])){
			add_messages(6);
			continue;
		}
		i++;
	}
}

void	Contacts::getList() const {
	std::string index = std::to_string(this->index);
	std::string field;
	std::cout << std::setw(10) << index << '|';
	for (int i = 0; i <= 2; i++) {
		field = details[i];
		if (field.length() > 10) {
			field = field.substr(0, 10);
			field[9] = '.';
		}
		else if (field.length() < 10)
			std::cout << std::setw(10);
		std::cout << field << '|';
	}
	std::cout << std::endl;
}

void	Contacts::getDetails() const {
	std::cout 	<< "\nFirst name: " << details[0] << '\n'
				<< "Last name: " << details[1] << '\n'
				<< "Nickname: " << details[2] << '\n'
				<< "Phone number: " << details[3] << '\n'
				<< "Darkest secret: " << details[4] << std::endl;
}
