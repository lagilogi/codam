/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contacts.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:45:53 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 14:18:29 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contacts {
	private:
		int			index;
		std::string	details[5];

	public:
		void	setDetails(int index);
		void	getList() const;
		void	getDetails() const;
		void	add_messages(int i) const;
		int		check_phonenumber(std::string phoneNumber) const;
};

#endif