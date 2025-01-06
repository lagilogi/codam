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

/* CONSTRUCTORS */
Fixed::Fixed() : fixed_point(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : fixed_point(num << frac_bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : fixed_point(roundf(num * (1 << frac_bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}




/* COPY CONSTRUCTOR */
Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	fixed_point = other.fixed_point;
}


/* COPY ASSIGNMENT OPERATOR OVERLOAD */
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this == &other)
   		return *this;
	fixed_point = other.fixed_point;
	return *this;
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed NewObject;
	NewObject.fixed_point = fixed_point + other.fixed_point;
	return NewObject;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed NewObject;
	NewObject.fixed_point = fixed_point - other.fixed_point;
	return NewObject;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed NewObject;
	NewObject.fixed_point = fixed_point * other.fixed_point;
	return NewObject;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed NewObject;
	NewObject.fixed_point = fixed_point / other.fixed_point;
	return NewObject;
}

Fixed& Fixed::operator++()
{
	fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed NewObject(*this);
	NewObject.fixed_point++;
	return NewObject;
}

Fixed& Fixed::operator--()
{
	fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed NewObject(*this);
	NewObject.fixed_point--;
	return NewObject;
}


/* OPERATOR OVERLOAD */
bool Fixed::operator>(const Fixed &other)
{
	if (fixed_point > other.fixed_point)
		return true;
	return false;
}
bool Fixed::operator>=(const Fixed &other)
{
	if (fixed_point >= other.fixed_point)
		return true;
	return false;
}
bool Fixed::operator<(const Fixed &other)
{
	if (fixed_point < other.fixed_point)
		return true;
	return false;
}
bool Fixed::operator<=(const Fixed &other)
{
	if (fixed_point <= other.fixed_point)
		return true;
	return false;
}
bool Fixed::operator==(const Fixed &other)
{
	if (fixed_point == other.fixed_point)
		return true;
	return false;
}
bool Fixed::operator!=(const Fixed &other)
{
	if (fixed_point != other.fixed_point)
		return true;
	return false;
}

/* OUTPUT OPERATOR OVERLOAD */
std::ostream& operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return output;
}




/* DESTRUCTOR */
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}




/* MEMBER FUNCTIONS */
int	Fixed::toInt(void) const
{
	int num = fixed_point >> frac_bits;
	return num;
}

float Fixed::toFloat(void) const
{
	float num = (float)fixed_point / (1 << frac_bits);
	return num;
}




/* GETTERS & SETTERS */
int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	fixed_point = raw;
}
