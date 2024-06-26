/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_to_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:30:31 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/27 17:24:18 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(t_stack *stacka)
{
	int	smallest;
	int	pos;
	int	i;

	smallest = stacka->data;
	i = 0;
	pos = 0;
	if (stacka->next != NULL)
		stacka = stacka->next;
	while (stacka != NULL)
	{
		i++;
		if (stacka->data < smallest)
		{
			smallest = stacka->data;
			pos = i;
		}
		stacka = stacka->next;
	}
	return (pos);
}

static bool	biggest_check(t_stack *stacka, int num)
{
	while (stacka != NULL)
	{
		if (num < stacka->data)
			return (false);
		stacka = stacka->next;
	}
	return (true);
}

static int	find_pos_in_a(t_stack *stacka, t_stack *stackb, int num)
{
	int	current_pos;
	int	pos;
	int	dif;

	current_pos = 0;
	pos = 0;
	dif = INT_MAX;
	if (biggest_check(stacka, stackb->data))
		return (find_smallest(stacka));
	while (stacka != NULL)
	{
		if (num < stacka->data && stacka->data - num < dif)
		{
			dif = stacka->data - num;
			pos = current_pos;
		}
		if (dif == 1)
			return (pos);
		current_pos++;
		stacka = stacka->next;
	}
	return (pos);
}

static void	find_min_moves(t_stack *stacka, t_stack *stackb, t_info *info)
{
	int	a;
	int	b;
	int	moves;

	b = 0;
	while (stackb != NULL)
	{
		a = find_pos_in_a(stacka, stackb, stackb->data);
		moves = check_moves(a, b, info);
		if (moves == 0)
			break ;
		if (moves < info->min_moves)
		{
			reset_info(info);
			info->min_moves = moves;
			set_info(a, b, info);
		}
		stackb = stackb->next;
		b++;
	}
}

void	move_to_a(t_stack **stacka, t_stack **stackb, t_info *info)
{
	while (*stackb != NULL)
	{
		find_min_moves(*stacka, *stackb, info);
		while (info->rot_a_b--)
			ft_rotate(stacka, stackb, 'r');
		while (info->rev_rot_a_b--)
			ft_rev_rotate(stacka, stackb, 'r');
		while (info->rot_a--)
			ft_rotate(stacka, NULL, 'a');
		while (info->rot_b--)
			ft_rotate(stackb, NULL, 'b');
		while (info->rev_rot_a--)
			ft_rev_rotate(stacka, NULL, 'a');
		while (info->rev_rot_b--)
			ft_rev_rotate(stackb, NULL, 'b');
		ft_push(stackb, stacka, info, 'a');
		reset_info(info);
	}
}
