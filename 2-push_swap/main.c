/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/14 15:28:00 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_data(t_stack *stacka, t_stack *stackb)
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

static void	set_info(t_info *info, int argc)
{
	info->size_a = argc - 1;
	info->size_b = 0;
	info->moves = 0;
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_info	info;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		kill_program(&stacka, &stackb, 1);
	set_info(&info, argc);
	create_list(&stacka, argc, argv);
	sorting(&stacka, &stackb, &info);

	// ft_printf("Moves: %d\n", info.moves);
	// print_list_data(stacka, stackb);
	kill_program(&stacka, &stackb, 0);
	return (0);
}
