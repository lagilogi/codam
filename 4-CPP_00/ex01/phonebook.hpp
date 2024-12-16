/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:45:53 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/16 17:24:20 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contacts.hpp"

class PhoneBook {
	private:
		Contacts	contact[8];
		int			contact_amount;

	public:
		PhoneBook();
		void	setDetails(int index);
		void	getList() const;
		void	getDetails(int index) const;
		int		getContact_amount() const;
		void	setContact_amount();
};
