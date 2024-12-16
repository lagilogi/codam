/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:45:56 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/16 17:23:48 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Constructor" << std::endl;
	contact_amount = 0;
}

void	PhoneBook::setDetails(int index){
	contact[index].setDetails(index);
}


void	PhoneBook::getList() const {
	std::cout << "    Index |first name| last name|  nickname|\n";
	for (int i = 0; i < contact_amount; i++)
		contact[i].getList();
}

void	PhoneBook::getDetails(int index) const {
	contact[index - 1].getDetails();
}


int		PhoneBook::getContact_amount() const {
	return contact_amount;
}

void	PhoneBook::setContact_amount(){
	if (contact_amount < 8)
		contact_amount++;
}
