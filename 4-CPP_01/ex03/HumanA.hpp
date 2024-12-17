/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:32:42 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 18:06:00 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "header.hpp"

class HumanA {
	private:
		std::string	_name;
		std::string	_weapon;

	public:
		HumanA(std::string name, std::string weapon);
		void	attack() const;
};

#endif