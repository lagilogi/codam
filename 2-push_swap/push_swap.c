/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/21 18:58:39 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stacka;

	if (argc < 2)
	{
		printf("Not enough arguments!\n"); // VERVANG DOOR FT_PRINTF
		exit(EXIT_FAILURE); // EXIT
	}
	stacka = initialize(stacka, argc, argv);

	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int 	array[5] = {1, 4, 3, 2, 5};
// 	int		i;
// 	int		tmp;
// 	bool	operation;
// 	i = 0;
// 	operation = true;
// 	while (operation == true)
// 	{
// 		operation = false;
// 		while(i < 5)
// 		{
// 			if (array[i] > array[i + 1] && i + 1 != 5)
// 			{
// 				tmp = array[i];
// 				array[i] = array[i + 1];
// 				array[i + 1] = tmp;
// 				operation = true;
// 			}
// 			i++;
// 		}
// 		if (operation == false)
// 			break ;
// 		i = 0;
// 	}
// 	i = 0;
// 	while(i < 5)
// 	{
// 		printf("%d: %d\n", i, array[i]);
// 		i++;
// 	}
// 	return (0);
// }
