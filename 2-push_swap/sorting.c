/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 14:30:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/27 15:50:37 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_of_3(t_stack **head, t_info *info)
{
	t_stack	*node2;
	t_stack	*node3;

	node2 = (*head)->next;
	node3 = (*head)->next->next;
	if (info->size_a == 2)
	{
		if ((*head)->data > (*head)->next->data)
			ft_swap(head, NULL, 'a');
		return ;
	}
	while (!((*head)->data < node2->data && node2->data < node3->data))
	{
		if (((*head)->data > node2->data && (*head)->data < node3->data)
			|| ((*head)->data < node2->data && (*head)->data < node3->data))
			ft_swap(head, NULL, 'a');
		else if ((*head)->data > node2->data && (*head)->data > node3->data)
			ft_rotate(head, NULL, 'a');
		else if ((*head)->data < node2->data && (*head)->data > node3->data)
			ft_rev_rotate(head, NULL, 'a');
		node2 = (*head)->next;
		node3 = (*head)->next->next;
	}
}

bool	just_rotate(t_stack *stacka)
{
	int		i;
	int		first;

	first = stacka->data;
	i = 0;
	while (stacka != NULL && i < 2)
	{
		if (stacka->next == NULL)
		{
			if (stacka->data > first)
				i++;
		}
		if (stacka->next != NULL && stacka->data > stacka->next->data)
			i++;
		stacka = stacka->next;
	}
	if (i >= 2)
		return (false);
	return (true);
}

void	sorting(t_stack **stacka, t_stack **stackb, t_info *info)
{
	if (info->size_a == 1)
		return ;
	else if (info->size_a == 2 || info->size_a == 3)
		return (list_of_3(stacka, info));
	else if (just_rotate(*stacka))
		return (rotate_till_correct(stacka, info));
	ft_push(stacka, stackb, info, 'b');
	if (info->size_a > 3 && !just_rotate(*stacka))
		ft_push(stacka, stackb, info, 'b');
	if (info->size_a > 3 && !just_rotate(*stacka))
		move_to_b(stacka, stackb, info);
	list_of_3(stacka, info);
	move_to_a(stacka, stackb, info);
	if (list_check_a(*stacka))
		return ;
	rotate_till_correct(stacka, info);
}
