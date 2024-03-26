/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:31:14 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/26 17:21:47 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	limit_stack_b(t_stack *stackb, t_info *info)
{
	t_stack	*tmp;

	tmp = stackb;
	info->min = stackb->data;
	while (stackb->next != NULL)
		stackb = stackb->next;
	info->max = stackb->data;
	info->halved = true;
}

int	skip_half(t_stack **stackb, t_info *info)
{
	int	i;

	i = 0;
	while (*stackb != NULL)
	{
		if ((*stackb)->data == info->max)
		{
			*stackb = (*stackb)->next;
			return (i + 1);
		}
		*stackb = (*stackb)->next;
		i++;
	}
	info->end = true;
	return (i);
}

int	find_smallest_b(t_stack *stackb, t_info *info)
{
	int	smallest;
	int	pos;
	int	i;

	smallest = stackb->data;
	i = 0;
	pos = 0;
	if (stackb->next != NULL)
		stackb = stackb->next;
	while (stackb != NULL)
	{
		i++;
		if (info->halved == true && stackb->data == info->min)
			i += skip_half(&stackb, info);
		if (stackb == NULL)
			return (pos + 1);
		if (stackb->data < smallest)
		{
			smallest = stackb->data;
			pos = i;
		}
		stackb = stackb->next;
	}
	return (pos + 1);
}
