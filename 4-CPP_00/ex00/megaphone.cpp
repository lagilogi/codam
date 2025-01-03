/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 14:37:15 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/16 14:37:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; argv[i] != NULL; i++)
		{
			for (int o = 0; argv[i][o] != '\0'; o++)
				argv[i][o] = std::toupper(argv[i][o]);
			std::cout << argv[i];
		}
	std::cout << '\n';
	return 0;
}

