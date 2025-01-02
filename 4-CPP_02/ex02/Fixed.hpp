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
#include <cmath>

class Fixed {
	private:
		int	fixed_point;
		static const int frac_bits = 8;

	public:
		Fixed();								// Default constructor
		Fixed(const int num);					// int parameter constructor
		Fixed(const float num);					// float parameter constructor
		Fixed(const Fixed &other);				// Copy constructor

		Fixed& operator=(const Fixed &other);	// = assigntment operator overload
		Fixed& operator+(const Fixed &other);	// + assigntment operator overload
		Fixed& operator-(const Fixed &other);	// - assigntment operator overload
		Fixed& operator*(const Fixed &other);	// * assigntment operator overload
		Fixed& operator/(const Fixed &other);	// / assigntment operator overload


		~Fixed();								// Destructor

		int		toInt( void ) const;			// Change fixed_point to Int
		float	toFloat( void ) const;			// Change fixed_point to Float
		int		getRawBits( void ) const;		// Getter
		void	setRawBits( int const raw );	// Setter
};

std::ostream& 	operator<<(std::ostream &out, const Fixed &fixed);	// >> assignment operator overload (output)

#endif