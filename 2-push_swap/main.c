/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/18 21:20:16 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_data(t_stack *stacka, t_stack *stackb) // For testing purposes
{
	int		i = 0;

	ft_printf("\n- Stack A -\n");
	if (stacka == NULL)
		ft_printf("Stack empty!\n");
	while (stacka != NULL)
	{
		ft_printf("Node %d - Num: %d\n", i, stacka->data);
		stacka = stacka->next;
		i++;
	}
	i = 0;
	// stackb = NULL;
	ft_printf("\n");
	ft_printf("- Stack B -\n");
	if (stackb == NULL)
		ft_printf("Stack empty!\n");
	while (stackb != NULL)
	{
		ft_printf("Node %d - Num: %d\n", i, stackb->data);
		stackb = stackb->next;
		i++;
	}
	ft_printf("\n\n");
}

void	print_info(t_info *info) // For testing purposes
{
	printf("rot a: %d\n", info->rot_a);
	printf("rev rot a: %d\n", info->rev_rot_a);
	printf("rot b: %d\n", info->rot_b);
	printf("rev rot b: %d\n", info->rev_rot_b);
	printf("rot a b: %d\n", info->rot_a_b);
	printf("rev rot a b: %d\n", info->rev_rot_a_b);
	printf("min moves: %d\n\n", info->min_moves);
}

static void	init_info(t_info *info, int argc)
{
	info->size_a = argc - 1;
	info->rot_a = 0;
	info->rev_rot_a = 0;
	info->size_b = 0;
	info->rot_b = 0;
	info->rev_rot_b = 0;
	info->rot_a_b = 0;
	info->rev_rot_a_b = 0;
	info->min_moves = argc - 1;
	info->moves = 0;
}

// void	search_length(t_stack *stacka) // tryout
// {
// 	int	i;

// 	i = 0;
// 	while ()
// }

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_info	info;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		kill_program(&stacka, &stackb, 1);
	init_info(&info, argc);
	create_list(&stacka, argc, argv);
	// search_length(stacka); // tryout
	sorting(&stacka, &stackb, &info);

	print_list_data(stacka, stackb); // For testing purposes
	
	// ft_printf("Moves: %d\n", info.moves); // For testing purposes
	kill_program(&stacka, &stackb, 0);
	return (0);
}
