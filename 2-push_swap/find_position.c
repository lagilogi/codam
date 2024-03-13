/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_position.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/13 11:45:13 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/13 18:12:11 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_smallest(t_stack *stack)
{
	int	smallest;
	
	smallest = stack->data;
	if (stack->next != NULL)
		stack = stack->next;
	while (stack != NULL)
	{
		if (stack->data < smallest)
			smallest = stack->data;
		stack = stack->next;
	}
	return (smallest);
}

static int	check_biggest(t_stack *stack)
{
	int	biggest;
	
	biggest = stack->data;
	if (stack->next != NULL)
		stack = stack->next;
	while (stack != NULL)
	{
		if (biggest < stack->data)
			biggest = stack->data;
		stack = stack->next;
	}
	return (biggest);
}

int	if_bigger(t_stack *stack1, t_stack *stack2)
{
	t_stack	*tmp;
	int		smallest;
	int		pos;
	
	tmp = stack1;
	smallest = check_smallest(stack1);
	pos = 0;
	if (check_biggest(stack1) < stack2->data)
	{
		while (stack1->data != smallest)
		{
			stack1 = stack1->next;
			pos++;
		}
		return (pos);
	}
	else
		return (-1);
}


int	find_position(t_stack *stack1, t_stack *stack2) // Check target node in Stack 1, so we push to stack 1
{
	int	i;
	int	pos;
	int	difference;
	int	smallest;
	
	i = 0;
	smallest = INT_MAX;
	pos = 0;
	if (if_bigger(stack1, stack2) != -1)
		return (if_bigger(stack1, stack2));
	while (stack1 != NULL)
	{
		if (stack2->data < stack1->data)
		{
			difference = stack1->data - stack2->data;
			if (difference < smallest)
			{
				smallest = difference;
				pos = i;
			}
		}
		i++;
		stack1 = stack1->next;
	}
	return (pos);
}
