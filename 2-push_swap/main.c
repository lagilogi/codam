/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/26 17:04:35 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	info->min = INT_MAX;
	info->max = INT_MIN;
	info->halved = false;
	info->end = false;
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
		kill_program(&stacka, &stackb, 0);
	init_info(&info, argc);
	create_list(&stacka, argc, argv);
	sorting(&stacka, &stackb, &info);
	kill_program(&stacka, &stackb, 0);
	return (0);
}
