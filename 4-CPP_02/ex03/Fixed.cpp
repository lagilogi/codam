/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:31:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/06 18:49:56 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/* CONSTRUCTORS */
Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : fixed_point(num << frac_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : fixed_point(roundf(num * (1 << frac_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}




/* COPY CONSTRUCTOR */
Fixed::Fixed(const Fixed &other)
{
	fixed_point = other.fixed_point;
}


/* COPY ASSIGNMENT OPERATOR OVERLOAD */
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
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
	NewObject.fixed_point = (fixed_point * other.fixed_point) >> frac_bits;
	return NewObject;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed NewObject;
	NewObject.fixed_point = (fixed_point << frac_bits) / other.fixed_point;
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
	fixed_point++;
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
	fixed_point--;
	return NewObject;
}


/* OPERATOR OVERLOAD */
bool Fixed::operator>(const Fixed &other) const
{
	return (fixed_point > other.fixed_point);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (fixed_point >= other.fixed_point);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (fixed_point < other.fixed_point);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (fixed_point <= other.fixed_point);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (fixed_point != other.fixed_point);
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
	std::cout << "Destructor called" << std::endl;
}




/* MEMBER FUNCTIONS */
int	Fixed::toInt(void) const
{
	return (fixed_point >> frac_bits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point) / (1 << frac_bits));
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}






/* GETTERS & SETTERS */
int	Fixed::getRawBits( void ) const
{
	return (fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}
