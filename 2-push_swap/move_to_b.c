/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_to_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:31:14 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/13 18:12:20 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack **stacka, t_stack **stackb, t_info *info)
{
	int	pos;

	while (info->size_a > 3 && !list_check(*stacka))
	{
		pos = find_position(*stackb, *stacka);
		if (pos == info->size_b - 1)
			ft_rev_rotate(stackb, NULL, info, 'b');
		else if (pos <= info->size_b / 2)
		{
			while (pos > 0)
			{
				ft_rotate(stackb, NULL, info, 'b');
				pos--;
			}
		}
		else
		{
			while (pos < info->size_b)
			{
				ft_rev_rotate(stackb, NULL, info, 'b');
				pos++;
			}
		}
		ft_push(stacka, stackb, info, 'b');
		// print_list_data(*stacka, *stackb);
	}
}
