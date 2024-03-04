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

int	ft_swap(t_list *stacka, t_list *stackb, char x) // Used for swapping stack A or B
{
	int	tmp;

	if (stacka->next == NULL && (x == 'a' || x == 'c'))
		return (0);
	if (stackb->next == NULL && (x == 'b' || x == 'c'))
		return (0);
	if (x == 'a' || x == 'c')
	{
		tmp = stacka->data;
		stacka->data = stacka->next->data;
		stacka->next->data = tmp;
	}
	if (x == 'b' || x == 'c')
	{
		tmp = stackb->data;
		stackb->data = stackb->next->data;
		stackb->next->data = tmp;
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

int	ft_rotate(t_list **stack1, t_list **stack2, int i) // first node becomes last for stack A, B or for both stacks
{
	t_list	*tmp;
	t_list	*first;

	if (*stack1 == NULL || (stack2 == NULL && i == 1))
		return (0);
	tmp = *stack1;
	first = (*stack1)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack1;
	(*stack1)->next = NULL;
	*stack1 = first;
	if (stack2 != NULL)
		ft_rotate(stack2, NULL, 0);
	return (1);
}

int	ft_rotate_rev(t_list **stack1, t_list **stack2, int i) // last node becomes first
{
	t_list	*tmp;
	t_list	*last;

	if (*stack1 == NULL || (stack2 == NULL && i == 1))
		return (0);
	tmp = *stack1;
	while (tmp->next != NULL)
	{
		if (tmp->next->next == NULL)
			break ;
		tmp = tmp->next;
	}
	last = tmp;
	tmp = tmp->next;
	last->next = NULL;
	tmp->next = *stack1;
	*stack1 = tmp;
	if (stack2 != NULL)
		ft_rotate(stack2, NULL, 0);
	return (1);
}




// int	ft_swap(t_list **head) // Used for swapping both stack A and B - // OLD function that switches nodes instead of values
// {
// 	t_list	*tmp;
// 	t_list	*node3;

// 	if ((*head)->next == NULL)
// 		return (0);
// 	else
// 	{
// 		tmp = (*head)->next;
// 		node3 = (*head)->next->next;
// 		tmp->next = *head;
// 		(*head)->next = node3;
// 		*head = tmp;
// 	}
// 	return (1);
// }

// int	ft_swap(t_list *head) // Used for swapping stack A or B
// {
// 	int	tmp;

// 	if (head->next == NULL)
// 		return (0);
// 	else
// 	{
// 		tmp = head->data;
// 		head->data = head->next->data;
// 		head->next->data = tmp;
// 	}
// 	return (1);
// }

// int	ft_swap_both(t_list *stacka, t_list *stackb) // Used for swapping both stack A and B
// {
// 	int	tmp;

// 	if (stacka->next == NULL || stacka->next == NULL)
// 		return (0);
// 	else
// 	{
// 		tmp = stacka->data;
// 		stacka->data = stacka->next->data;
// 		stacka->next->data = tmp;
// 		tmp = stackb->data;
// 		stackb->data = stackb->next->data;
// 		stackb->next->data = tmp;
// 	}
// 	return (1);
// }




// int	ft_rotate(t_list **head) // first node becomes last for either stack A or B
// {
// 	t_list	*tmp;
// 	t_list	*first;

// 	if (*head == NULL)
// 		return (0);
// 	tmp = *head;
// 	first = (*head)->next;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = *head;
// 	(*head)->next = NULL;
// 	*head = first;
// 	return (1);
// }

// int	ft_rotate_both(t_list **stacka, t_list **stackb) // first node becomes last for both stack A and B
// {
// 	t_list	*tmp;
// 	t_list	*first;

// 	if (*stacka == NULL || *stackb == NULL)
// 		return (0);
// 	tmp = *stacka;
// 	first = (*stacka)->next;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = *stacka;
// 	(*stacka)->next = NULL;
// 	*stacka = first;
// 	tmp = *stackb;
// 	first = (*stackb)->next;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = *stackb;
// 	(*stackb)->next = NULL;
// 	*stackb = first;
// 	return (1);
// }


// int	ft_rotate_rev(t_list **head) // last node becomes first
// {
// 	t_list	*tmp;
// 	t_list	*last;

// 	if (*head == NULL)
// 		return (0);
// 	tmp = *head;
// 	while (tmp->next != NULL)
// 	{
// 		if (tmp->next->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 	}
// 	last = tmp;
// 	tmp = tmp->next;
// 	last->next = NULL;
// 	tmp->next = *head;
// 	*head = tmp;
// 	return (1);
// }
