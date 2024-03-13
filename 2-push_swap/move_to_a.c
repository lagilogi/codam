/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_to_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:30:31 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/13 18:12:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_stack **stacka, t_stack **stackb, t_info *info)
{
	int	pos;

	while (*stackb != NULL)
	{
		pos = find_position(*stacka, *stackb);
		printf("Position: %d, Size_a: %d\n", pos, info->size_a);
		if (pos == info->size_a - 1)
			ft_rev_rotate(stacka, NULL, info, 'a');
		else if (pos <= info->size_a / 2)
		{
			while (pos > 0)
			{
				ft_rotate(stacka, NULL, info, 'a');
				pos--;
			}
		}
		else
		{
			while (pos < info->size_a)
			{
				ft_rev_rotate(stacka, NULL, info, 'a');
				pos++;
			}
		}
		ft_push(stackb, stacka, info, 'a');
		print_list_data(*stacka, *stackb);
	}
}
