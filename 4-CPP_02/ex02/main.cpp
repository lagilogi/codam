#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b(5);
	Fixed c(42.42f);
	Fixed d = b + c;

	std::cout << a << " " << b << " " << c << " " << d << std::endl;

	a = b;
	b = d;
	c = b;
	d = a++ * 23.45f;

	std::cout << a << " " << b << " " << c << " " << d << std::endl;

	if (a == b)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "False" << std::endl;
	std::cout << d.toInt() << std::endl;
	std::cout << a.toFloat() << std::endl;
}



// int main( void )
// {
// 	Fixed 		a;
// 	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }

// int main(void)
// {
// 	// Fixed	a(Fixed(5) - Fixed(5));
// 	// Fixed	b(Fixed(1) + Fixed(1));
// 	// Fixed	c(Fixed(30) / Fixed(5));
// 	// Fixed	d(Fixed(2) * Fixed(4));
// 	// int		x = 6;

// 	// std::cout << "a = " << a << std::endl;
// 	// std::cout << "b = " << b << std::endl;
// 	// std::cout << "c = " << c << std::endl;
// 	// std::cout << "d = " << d << std::endl;
// 	// if (c < d)
// 	// 	std::cout << c << " is less than " << d << std::endl;
// 	// if (c > d)
// 	// 	std::cout << c << " is greater than " << d << std::endl;
// 	// if (c <= x)
// 	// 	std::cout << x << " is less then or equals " << c << std::endl;
// 	// if (c >= x)
// 	// 	std::cout << c << " is greater then or equals " << x << std::endl;
// 	// if (c == x)
// 	// 	std::cout << c << " equals " << x << std::endl;
// 	// if (c != 10)
// 	// 	std::cout << c << " does not equal 10 " << std::endl;
	
// 	// std::cout	<< "\n\nInitial value of a: " << a

//     // 			<< "\n\nPre-increment: " << ++a // a is incremented before printing
// 	// 			<< "\nAfter pre-increment: " << a // a is already incremented

// 	// 			<< "\nPre-decrement: " << --a // a is decremented before printing
// 	// 			<< "\nAfter pre-decrement: " << a // a is already decremented

// 	// 			<< "\n\nPost-increment: " << a++ // a's original value is printed
// 	// 			<< "\nAfter post-increment: " << a // a is incremented now

// 	// 			<< "\nPost-decrement: " << a-- // a's original value is printed
// 	// 			<< "\nAfter post-decrement: " << a << std::endl; // a is decremented now
	

// 	Fixed 	a(9);
// 	Fixed	b(2);
// 	Fixed	c(10);
// 	Fixed	d(20);

	
// 	a = a * b;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << c << std::endl;
// 	std::cout << d << std::endl;
	
// 	return (0);
// }