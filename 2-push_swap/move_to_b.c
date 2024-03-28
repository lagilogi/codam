/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_to_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:31:14 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/28 18:43:40 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	smallest_check(t_stack *stackb, t_info *info, int num)
{
	while (stackb != NULL)
	{
		if (info->halved == true && stackb->data == info->top)
		{
			skip_half(&stackb, info);
			if (stackb == NULL)
				return (true);
		}
		if (num > stackb->data)
			return (false);
		stackb = stackb->next;
	}
	return (true);
}

static int	find_biggest(t_stack *stackb, t_info *info)
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
		if (info->halved == true && stackb->data == info->top)
			i += skip_half(&stackb, info);
		if (stackb == NULL)
			return (pos);
		if (stackb->data > biggest)
		{
			biggest = stackb->data;
			pos = i;
		}
		stackb = stackb->next;
	}
	return (pos);
}

static int	pos_in_b(t_stack *stacka, t_stack *stackb, t_info *info, int num)
{
	t_pos_b	tmp;

	set_info_pos_b(&tmp);
	if (info->halved == false && smallest_check(stackb, info, stacka->data))
		return (find_biggest(stackb, info));
	else if (smallest_check(stackb, info, stacka->data))
		return (find_top(stackb, info));
	while (stackb != NULL)
	{
		if (info->halved == true && stackb->data == info->top)
			tmp.current_pos += skip_half(&stackb, info);
		if (stackb == NULL)
			return (tmp.pos);
		if (num > stackb->data && num - stackb->data < tmp.dif)
		{
			tmp.dif = num - stackb->data;
			tmp.pos = tmp.current_pos;
		}
		if (tmp.dif == 1)
			return (tmp.pos);
		tmp.current_pos++;
		stackb = stackb->next;
	}
	return (tmp.pos);
}

static void	find_min_moves(t_stack *stacka, t_stack *stackb, t_info *info)
{
	int	a;
	int	b;
	int	moves;

	a = 0;
	while (stacka != NULL)
	{
		b = pos_in_b(stacka, stackb, info, stacka->data);
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
	while (info->size_a > 3 && !list_check_a(*stacka))
	{
		if (info->halved == false && info->size_a < info->size_b
			&& info->size_a > 100)
		{
			limit_stack_b(*stackb, info);
			ft_push(stacka, stackb, info, 'b');
		}
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
		ft_push(stacka, stackb, info, 'b');
		reset_info(info);
	}
}
