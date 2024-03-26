/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/12 14:21:57 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/26 18:47:36 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	list_check_a(t_stack *head)
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

void	rotate_till_correct(t_stack **stacka, t_info *info)
{
	int		pos;

	pos = find_minimum(*stacka);
	if (pos < info->size_a / 2)
		while (!list_check_a(*stacka))
			ft_rotate(stacka, NULL, 'a');
	else
		while (!list_check_a(*stacka))
			ft_rev_rotate(stacka, NULL, 'a');
}
