/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:31:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/30 19:42:06 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors & destructors
Fixed::Fixed() : fixed_point(0) {}				// Default constructor

Fixed::Fixed(const Fixed &copy)					// Copy constructor
{
	
}

Fixed& Fixed::operator=(const Fixed &o_copy)	// Copy assigntment operator overload
{
	
}

Fixed::~Fixed() {}								// Destructor


// Getters & Setters
int	Fixed::getRawBits( void ) const
{
	return (fixed_point);
}

int Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}