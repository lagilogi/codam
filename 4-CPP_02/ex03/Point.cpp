/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 18:34:46 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/06 19:07:23 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float set_x, const float set_y) : x(set_x), y(set_y)
{
	std::cout << "Point constructor called with arguments" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	std::cout << "Copy Point constructor called" << std::endl;
}

Point& Point::operator=(const Point &other)
{
	// Needs work
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}
