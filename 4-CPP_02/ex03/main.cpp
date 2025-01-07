/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:31:37 by wsonepou      #+#    #+#                 */
/*   Updated: 2025/01/07 18:19:19 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main()
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	
	// Point d(3.1, 3.1);
	Point e(1, 1);
	// Point f(6, 100);

	bsp(a, b, c, e);
	// std::cout << "Point d: " << bsp(a, b, c, d) << std::endl;
	// std::cout << "Point e: " << bsp(a, b, c, e) << std::endl;
	// std::cout << "Point f: " << bsp(a, b, c, f) << std::endl;
}
