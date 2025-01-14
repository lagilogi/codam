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

		Fixed& operator=(const Fixed &other);	// = assignment operator overload
		Fixed operator+(const Fixed &other);	// + assignment operator overload
		Fixed operator-(const Fixed &other);	// - assignment operator overload
		Fixed operator*(const Fixed &other);	// * assignment operator overload
		Fixed operator/(const Fixed &other);	// / assignment operator overload

		Fixed& operator++();					// ++x assignment operator overload
		Fixed operator++(int);					// x++ assignment operator overload
		Fixed& operator--();					// --X assignment operator overload
		Fixed operator--(int);					// x-- assignment operator overload

		bool operator>(const Fixed &other) const;		// > assignment operator overload
		bool operator>=(const Fixed &other) const;	// >= assignment operator overload
		bool operator<(const Fixed &other) const;		// < assignment operator overload
		bool operator<=(const Fixed &other) const;	// <= assignment operator overload
		bool operator==(const Fixed &other) const;	// == assignment operator overload
		bool operator!=(const Fixed &other) const;	// != assignment operator overload


		~Fixed();								// Destructor

		int		toInt( void ) const;			// Change fixed_point to Int
		float	toFloat( void ) const;			// Change fixed_point to Float
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		
		int		getRawBits( void ) const;		// Getter
		void	setRawBits( int const raw );	// Setter
};

std::ostream& 	operator<<(std::ostream &out, const Fixed &fixed);	// >> assignment operator overload (output)

#endif
