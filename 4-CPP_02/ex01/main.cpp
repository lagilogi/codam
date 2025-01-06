/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:31:37 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/06 18:02:10 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed 		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}


// int main()
// {
// 	Fixed	a(-10);
// 	Fixed	b(5);
// 	Fixed	c(-2.345f);
// 	Fixed	d(8.98f);
// 	Fixed	e = b.getRawBits() + d.getRawBits();

// 	std::cout << a << " " << b << " " << c << " " << d << std::endl;

// 	std::cout << a.toFloat() << " " << c.toInt() << std::endl;

// 	a.setRawBits(214342);
	
// 	std::cout << a.toFloat() << " " << a.toInt() << std::endl;
// 	e.setRawBits(e.getRawBits() >> 8);
// 	std::cout << e << std::endl;
// }