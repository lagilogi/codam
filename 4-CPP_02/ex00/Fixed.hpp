/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:32:36 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/30 19:42:00 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	fixed_point;
		static const int frac_bits;

	public:
		Fixed();									// Default constructor
		Fixed(const Fixed &copy);					// Copy constructor
		Fixed& Fixed::operator=(const Fixed &op);	// Copy assigntment operator overload
		~Fixed();									// Destructor

		int	getRawBits( void ) const;
		int setRawBits( int const raw ); 
};


#endif