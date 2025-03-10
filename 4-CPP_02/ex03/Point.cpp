#include "header.hpp"

Point::Point() : x(0), y(0)
{
	// std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float set_x, const float set_y) : x(set_x), y(set_y)
{
	// std::cout << "Point constructor called with arguments" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	// std::cout << "Copy Point constructor called" << std::endl;
}

Point& Point::operator=(const Point &other)
{
	// Can't assign any values as x and Y are const.
	(void)other; // Suppress 'unused variable' warning
	return *this;	
}


bool Point::operator==(const Point &other) const
{
	if (x == other.x && y == other.y)
		return true;
	return false;
}

Point::~Point()
{
	// std::cout << "Point destructor called" << std::endl;
}


const Fixed& Point::getX() const
{
	return (x);
}

const Fixed& Point::getY() const
{
	return (y);
}
