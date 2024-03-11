/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_to_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:30:31 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/11 18:46:09 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position(t_stack *stacka, t_stack *stackb, int size_a)
{
	int	i;
	int	pos;
	int	difference;
	int	smallest;
	
	i = 0;
	smallest = 0;
	while (stacka != NULL)
	{
		if (stackb->data < stacka->data)
		{
			difference = stacka->data - stackb->data;
			if (difference < smallest && smallest != 0)
			{
				smallest = difference;
				pos = i;
			}
		}
		i++;
		printf("difference: %d\n", difference);
		stacka = stacka->next;
	}
	if (pos == size_a)
		return (0);
	else if (pos > size_a / 2)
		return ((size_a - pos - 1) * -1);
	return (pos - 1);
}

int	move_to_a(t_stack **stacka, t_stack **stackb, int size_a, int size_b)
{
	int	pos;
	int	moves;
	t_stack	*tmp_b;
	t_stack *tmp_a;

	tmp_a = *stacka;
	tmp_b = *stackb;
	moves = 0;
	size_b = 12312; // TEMP - MIGHT NEED TO REMOVE
	while (*stackb != NULL)
	{
		pos = find_position(*stacka, *stackb, size_a);
		if (pos == 0)
			ft_push(stackb, stacka, 'a');
		else if (pos < size_a / 2)
		{
			while (pos > 0)
			{
				moves += ft_rotate(stacka, NULL, 'a');
				pos--;
			}
			moves += ft_push(stackb, stacka, 'a');
		}
		else
		{
			while (pos < 0)
			{
				moves += ft_rev_rotate(stacka, NULL, 'a');
				pos--;
			}
			moves += ft_push(stackb, stacka, 'a');
		}
	}
	return (moves);
}
