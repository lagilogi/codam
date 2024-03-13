/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 14:30:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/13 18:10:24 by wsonepou      ########   odam.nl         */
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
			ft_swap(head, NULL, info, 'a');
		return ;
	}
	while (!((*head)->data < node2->data && node2->data < node3->data))
	{
		if (((*head)->data > node2->data && (*head)->data < node3->data)
			|| ((*head)->data < node2->data && (*head)->data < node3->data))
			ft_swap(head, NULL, info, 'a');
		else if ((*head)->data > node2->data && (*head)->data > node3->data)
			ft_rotate(head, NULL, info, 'a');
		else if ((*head)->data < node2->data && (*head)->data > node3->data)
			ft_rev_rotate(head, NULL, info, 'a');
		node2 = (*head)->next;
		node3 = (*head)->next->next;
	}
}

bool	just_rotate(t_stack **stacka)
{
	t_stack *tmp;
	int		i;
	int		first;

	tmp = *stacka;
	first = tmp->data;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			if (tmp->data > first)
				i++;
		}
		if (tmp->next != NULL && tmp->data > tmp->next->data)
			i++;
		tmp = tmp->next;
	}
	if (i >= 2)
		return(false);
	return (true);
}

void	sorting(t_stack **stacka, t_stack **stackb, t_info *info)
{
	if (info->size_a == 2 || info->size_a == 3)
	{
		list_of_3(stacka, info);
		return ;
	}
	else if (just_rotate(stacka))
	{
		rotate_till_correct(stacka, info);
		return ;
	}
	print_list_data(*stacka, *stackb);
	ft_push(stacka, stackb, info, 'b');
	if (info->size_a > 3 && !just_rotate(stacka))
		ft_push(stacka, stackb, info, 'b');
	if (info->size_a > 3)
		move_to_b(stacka, stackb, info);
	if (!just_rotate(stacka))
		list_of_3(stacka, info);
	// printf("\nAFTER PUSHING TO B\n"); // List checker
	print_list_data(*stacka, *stackb); // List checker
	move_to_a(stacka, stackb, info);
	if (list_check(*stacka))
		return ;
	rotate_till_correct(stacka, info);
}
