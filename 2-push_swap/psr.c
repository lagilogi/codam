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

int	ft_swap(t_list **stacka, t_list **stackb, char *action, char x)
{
	t_list	*tmp;

	if ((x == 'a' || x == 'c') && (*stacka == NULL || (*stacka)->next == NULL))
		return (0);
	if ((x == 'b' || x == 'c') && (*stackb == NULL || (*stackb)->next == NULL))
		return (0);
	if (x == 'a' || x == 'c')
	{
		tmp = (*stacka)->next;
		(*stacka)->next = tmp->next;
		tmp->next = *stacka;
		*stacka = tmp;
	}
	if (x == 'b' || x == 'c')
	{
		tmp = (*stackb)->next;
		(*stackb)->next = tmp->next;
		tmp->next = *stackb;
		*stackb = tmp;
	}
	write(1, action, 2);
	write(1, "\n", 1);
	return (1);
}

// int	ft_swap(t_list *stacka, t_list *stackb, char x)
// {
// 	int	tmp;

// 	if ((x == 'a' || x == 'c') && (stacka == NULL || stacka->next == NULL))
// 		return (0);
// 	if ((x == 'b' || x == 'c') && (stackb == NULL || stackb->next == NULL))
// 		return (0);
// 	if (x == 'a' || x == 'c')
// 	{
// 		tmp = stacka->data;
// 		stacka->data = stacka->next->data;
// 		stacka->next->data = tmp;
// 	}
// 	if (x == 'b' || x == 'c')
// 	{
// 		tmp = stackb->data;
// 		stackb->data = stackb->next->data;
// 		stackb->next->data = tmp;
// 	}
// 	if (x == 'a')
// 		write(1, "sa\n", 3);
// 	if (x == 'b')
// 		write(1, "sb\n", 3);
// 	if (x == 'c')
// 		write(1, "ss\n", 3);
// 	return (1);
// }

int	ft_push(t_list **stack_old, t_list **stack_new, char x)
{
	t_list	*node;

	if (*stack_old == NULL)
		return (0);
	node = *stack_old;
	*stack_old = (*stack_old)->next;
	node->next = *stack_new;
	*stack_new = node;
	if (x == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return(1);
}

int	ft_rotate(t_list **stack1, t_list **stack2, int i, char x) // first node becomes last for stack A, B or for both stacks
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
		ft_rotate(stack2, NULL, 0, x);
	if (x == 'a')
		write(1, "ra\n", 3);
	if (x == 'b')
		write(1, "rb\n", 3);
	if (x == 'c')
		write(1, "rr\n", 3);
	return (1);
}

int	ft_rev_rotate(t_list **stack1, t_list **stack2, int i, char x) // last node becomes first
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
		ft_rotate(stack2, NULL, 0, x);
	if (x == 'a')
		write(1, "rra\n", 4);
	if (x == 'b')
		write(1, "rrb\n", 4);
	if (x == 'c')
		write(1, "rrr\n", 4);
	return (1);
}
