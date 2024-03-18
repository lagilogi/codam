/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_to_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:31:14 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/18 21:19:31 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest(t_stack *stackb)
{
	int	biggest;
	int	pos;
	int	i;
	
	biggest = stackb->data;
	i = 0;
	pos = 0;
	if (stackb->next != NULL)
		stackb = stackb->next;
	while (stackb != NULL)
	{
		i++;
		if (stackb->data > biggest)
		{
			biggest = stackb->data;
			pos = i;
		}
		stackb = stackb->next;
	}
	return (pos);
}

static int	find_pos_in_b(t_stack *stacka, t_stack *stackb, int num)
{
	int	i;
	int dif;
	int pos;

	i = 0;
	pos = 0;
	dif = INT_MIN;
	if (smallest_check(stackb, stacka->data))
		return (find_biggest(stackb));
	while (stackb != NULL)
	{
		if (num > stackb->data)
		{
			if (num - stacka->data> 0 && num - stacka->data < dif)
			{
				dif = num - stacka->data;
				pos = i;
			}
		}
		i++;
		stackb = stackb->next;
	}
	return (pos);
}

static void	find_min_moves(t_stack *stacka, t_stack *stackb, t_info *info)
{
	int a;
	int	b;
	int	moves;

	a = 0;
	while (stacka != NULL)
	{
		b = find_pos_in_b(stacka, stackb, stacka->data);
		moves = check_moves(a, b, info);
		if (moves == 0)
			break ;
		if (moves < info->min_moves)
		{
			reset_info(info);
			info->min_moves = moves;
			set_info(a, b, info);
		}
		stacka = stacka->next;
		a++;
	}
}

void	move_to_b(t_stack **stacka, t_stack **stackb, t_info *info)
{
	while (info->size_a > 3 && !list_check(*stacka))
	{
		find_min_moves(*stacka, *stackb, info);
		// print_info(info); // For testing purposes
		while (info->rot_a_b--)
			ft_rotate(stacka, stackb, info, 'r');
		while (info->rev_rot_a_b--)
			ft_rev_rotate(stacka, stackb, info, 'r');
		while (info->rot_a--)
			ft_rotate(stacka, NULL, info, 'a');
		while (info->rot_b--)
			ft_rotate(stackb, NULL, info, 'b');
		while (info->rev_rot_a--)
			ft_rev_rotate(stacka, NULL, info, 'a');
		while (info->rev_rot_b--)
			ft_rev_rotate(stackb, NULL, info, 'b');
		ft_push(stacka, stackb, info, 'b');
		reset_info(info);
		// print_list_data(*stacka, *stackb); // For testing purposes
	}
}

// void	move_to_b(t_stack **stacka, t_stack **stackb, t_info *info)
// {
// 	int	pos;

// 	while (info->size_a > 3 && !list_check(*stacka))
// 	{
// 		pos = find_position(*stackb, *stacka);
// 		if (pos == info->size_b - 1)
// 			ft_rev_rotate(stackb, NULL, info, 'b');
// 		else if (pos <= info->size_b / 2)
// 		{
// 			while (pos > 0)
// 			{
// 				ft_rotate(stackb, NULL, info, 'b');
// 				pos--;
// 			}
// 		}
// 		else
// 		{
// 			while (pos < info->size_b)
// 			{
// 				ft_rev_rotate(stackb, NULL, info, 'b');
// 				pos++;
// 			}
// 		}
// 		ft_push(stacka, stackb, info, 'b');
// 		// print_list_data(*stacka, *stackb);
// 	}
// }
