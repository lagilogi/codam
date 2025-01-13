/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 18:35:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/13 12:42:30 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static Fixed	getSurfaceSize(const Point &v1, const Point &v2, const Point &v3)
{
	// shoelace method
	Fixed surfaceSize((v1.getX() * v2.getY() +
						v2.getX() * v3.getY() +
						v3.getX() * v1.getY())
						-
						(v1.getY() * v2.getX() + 
						v2.getY() * v3.getX() +
						v3.getY() * v1.getX()));


	if (surfaceSize < 0)
		surfaceSize = surfaceSize * -1;
	// std::cout << surfaceSize << std::endl;
	return (surfaceSize / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return false;

	Fixed totalSurfaceSize = getSurfaceSize(a, b, c);
	if (totalSurfaceSize == 0)
		return false;
	
	Fixed pointSurfaceSize = 0;

	Fixed surfaceSize1 = getSurfaceSize(point, a, b);
	Fixed surfaceSize2 = getSurfaceSize(point, b, c);
	Fixed surfaceSize3 = getSurfaceSize(point, c, a);
	
	if (surfaceSize1 == 0 || surfaceSize2 == 0 || surfaceSize3 == 0)
		return false;
	pointSurfaceSize = surfaceSize1 + surfaceSize2 + surfaceSize3;
	
	return (pointSurfaceSize == totalSurfaceSize);
}
