/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 14:48:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/17 17:30:54 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;
	
	// addresses
	std::cout 	<< "\nThe memory address of the string variable:   " << &str << "\n"
				<< "The memory address held by stringPTR:        " << strPTR << "\n"
				<< "The memory address held by stringREF:        " << &strREF << "\n" << std::endl;

	

	// values
	std::cout 	<< "The value of the string variable:    " << str << "\n"
				<< "The value pointed to by stringPTR:   " << *strPTR << "\n"
				<< "The value pointed to by stringREF:   " << strREF << "\n" << std::endl;

	return 0;
}
