/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   psr.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 17:40:00 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/28 19:03:15 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_old, t_stack **stack_new, t_info *info, char x)
{
	t_stack	*node;

	if (*stack_old == NULL)
		return ;
	node = *stack_old;
	*stack_old = (*stack_old)->next;
	node->next = *stack_new;
	*stack_new = node;
	ft_printf("p%c\n", x);
	if (x == 'a')
	{
		info->size_a++;
		info->size_b--;
	}
	else if (x == 'b')
	{
		info->size_a--;
		info->size_b++;
	}
}

void	ft_swap(t_stack **stacka, t_stack **stackb, char x)
{
	t_stack	*tmp;

	if ((x == 'a' || x == 's') && (*stacka == NULL || (*stacka)->next == NULL))
		return ;
	if ((x == 'b' || x == 's') && (*stackb == NULL || (*stackb)->next == NULL))
		return ;
	if (x == 'a' || x == 's')
	{
		tmp = (*stacka)->next;
		(*stacka)->next = tmp->next;
		tmp->next = *stacka;
		*stacka = tmp;
	}
	if (x == 'b' || x == 's')
	{
		tmp = (*stackb)->next;
		(*stackb)->next = tmp->next;
		tmp->next = *stackb;
		*stackb = tmp;
	}
	ft_printf("s%c\n", x);
}

void	ft_rotate(t_stack **stack1, t_stack **stack2, char x)
{
	t_stack	*tmp;
	t_stack	*first;

	if (*stack1 == NULL || (*stack1)->next == NULL)
		return ;
	tmp = *stack1;
	first = (*stack1)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack1;
	(*stack1)->next = NULL;
	*stack1 = first;
	if (stack2 != NULL)
		ft_rotate(stack2, NULL, x);
	else
		ft_printf("r%c\n", x);
}

void	ft_rev_rotate(t_stack **stack1, t_stack **stack2, char x)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack1 == NULL || (*stack1)->next == NULL)
		return ;
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
		ft_rev_rotate(stack2, NULL, x);
	else
		ft_printf("rr%c\n", x);
}
