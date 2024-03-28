/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 17:31:14 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/28 18:42:27 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	limit_stack_b(t_stack *stackb, t_info *info)
{
<<<<<<< HEAD
	t_stack	*tmp;

	tmp = stackb;
	info->top = stackb->data;
=======
	info->min = stackb->data;
>>>>>>> refs/remotes/origin/main
	while (stackb->next != NULL)
		stackb = stackb->next;
	info->bottom = stackb->data;
	info->halved = true;
}

int	skip_half(t_stack **stackb, t_info *info)
{
	int	i;

	i = 0;
	while (*stackb != NULL)
	{
		if ((*stackb)->data == info->bottom)
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

int	find_top(t_stack *stackb, t_info *info)
{
	int	pos;

	pos = 0;
	while (stackb->next->data != info->top)
	{
		stackb = stackb->next;
		pos++;
	}
	return (pos + 1);
}

void	set_info_pos_b(t_pos_b	*tmp)
{
	tmp->current_pos = 0;
	tmp->pos = 0;
	tmp->dif = INT_MAX;
}
