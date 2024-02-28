/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op1.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 17:40:00 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 19:08:13 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// OPERATIONS TO MAKE
// - SS = Swap 2 elements of stack A and B at the same time, counts as only 1 operation
//
// - RR = Rotate A and B, shift up all elements of stack A and B at the same time, counts as only 1 operation
//
// - RRR = Rotate A and B, shift down all elements of stack A and B at the same time, counts as only 1 operation



int	ft_swap(t_list **head) // Used for swapping both stack A and B
{
	t_list	*tmp;
	t_list	*node3;
	
	if ((*head)->next == NULL)
		return (0);
	else
	{
		tmp = (*head)->next;
		node3 = (*head)->next->next;
		tmp->next = *head;
		(*head)->next = node3;
		*head = tmp;
	}
	return (1);
}

int	ft_push(t_list **stack_old, t_list **stack_new)
{
	t_list	*node;

	if (*stack_old == NULL)
		return (0);
	node = *stack_old;
	*stack_old = (*stack_old)->next;
	node->next = *stack_new;
	*stack_new = node;
	return(1);
}

int	ft_rotate(t_list **head) // first node becomes last
{
	t_list	*tmp;
	t_list	*first;

	if (*head == NULL)
		return (0);
	tmp = *head;
	first = (*head)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	*head = first;
	return (1);
}

int	ft_rotate_rev(t_list **head) // last node becomes first
{
	t_list	*tmp;
	t_list	*last;
	
	if (*head == NULL)
		return (0);
	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->next->next == NULL)
			break ;
		tmp = tmp->next;
	}
	last = tmp;
	tmp = tmp->next;
	last->next = NULL;
	tmp->next = *head;
	*head = tmp;
	return (1);
}
