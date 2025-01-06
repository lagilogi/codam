/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:31:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/06 17:43:35 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors & destructors */
Fixed::Fixed() : fixed_point(0)					// Default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)					// Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &temp)		// Copy assignment operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &temp)
		fixed_point = temp.getRawBits();
	return *this;
}

Fixed::~Fixed()									// Destructor
{
	std::cout << "Destructor called" << std::endl;
}


/* Getters & Setters */
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_point = raw;
}