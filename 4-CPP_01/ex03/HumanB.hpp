/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:33:04 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 18:09:45 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "header.hpp"

class HumanB {
	private:
		std::string	_name;
		std::string	_weapon;

	public:
		HumanB(std::string name);
		HumanB(std::string name, std::string weapon);
		void	attack() const;
};

#endif