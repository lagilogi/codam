/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 18:34:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/06 19:06:41 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "header.hpp"

class Point
{
	private:
		const int x;
		const int y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);

		Point& Point::operator=(const Point &other);

		~Point();

};

#endif