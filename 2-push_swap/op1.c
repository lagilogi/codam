/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op1.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 17:40:00 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 18:31:27 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// OPERATIONS TO MAKE
// - SS = Swap 2 elements of stack A and B at the same time, counts as only 1 operation
//
// - RA = Rotate A, shift up all elements in stack A
// - RB = Rotate B, shift up all elements in stack B
// - RR = Rotate A and B, shift up all elements of stack A and B at the same time, counts as only 1 operation
//
// - RRA = Rotate A, Shift down all elements in stack A
// - RRB = Rotate B, shift down all elements in stack B
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

	node = *stack_old;
	*stack_old = (*stack_old)->next;
	node->next = *stack_new;
	*stack_new = node;
	return(1);
}
