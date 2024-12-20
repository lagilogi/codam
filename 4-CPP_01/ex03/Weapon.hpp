/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 17:31:49 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/20 17:42:19 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "header.hpp"

class Weapon {
	private:
		std::string _type;
	
	public:
		Weapon(const std::string type);
		std::string getType() const;
		void		setType(const std::string weapon);
};

#endif