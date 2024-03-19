/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 14:21:57 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/19 13:22:04 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	list_check(t_stack *head)
{
	if (head->next != NULL)
	{
		while (head->data < head->next->data)
		{
			head = head->next;
			if (head->next == NULL)
				return (true);
		}
	}
	return (false);
}

int	find_minimum(t_stack *head)
{
	int		i;
	int		min;
	int		pos;

	min = INT_MAX;
	i = 0;
	while (head != NULL)
	{
		if (head->data < min)
		{
			min = head->data;
			pos = i;
		}
		i++;
		head = head->next;
	}
	return (pos);
}

void	rotate_till_correct(t_stack **stacka, t_info *info)
{
	int		pos;
	t_stack	*tmp;

	tmp = *stacka;
	pos = find_minimum(*stacka);
	if (pos < info->size_a / 2)
		while (!list_check(*stacka))
			ft_rotate(stacka, NULL, info, 'a');
	else
		while (!list_check(*stacka))
			ft_rev_rotate(stacka, NULL, info, 'a');
}
