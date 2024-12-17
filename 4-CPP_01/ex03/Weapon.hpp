/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:31:49 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 17:59:05 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "header.hpp"

class Weapon {
	private:
		std::string _type;
	
	public:
		Weapon(std::string type);
		std::string getType() const;
		void		setType(std::string weapon);
};

#endif