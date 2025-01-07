/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 18:34:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/07 18:05:18 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "header.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);

		Point& operator=(const Point &other);

		bool operator==(const Point &other) const;

		const Fixed& getX() const;
		const Fixed& getY() const;

		~Point();

};

#endif