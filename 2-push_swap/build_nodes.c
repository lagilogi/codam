/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_nodes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:30:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/14 15:09:21 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexing(t_stack *head, int argc)
{
	t_stack	*tmp;
	t_stack	*current;
	int		i;
	int		highest;

	i = argc - 2;
	while (i > 0)
	{
		tmp = head;
		highest = INT_MIN;
		while (tmp != NULL)
		{
			if (tmp->index == 0 && tmp->data > highest)
			{
				current = tmp;
				highest = tmp->data;
			}
			tmp = tmp->next;
		}
		current->index = i;
		i--;
	}
}

static void	check_doubles(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = (*head)->next;
	prev = *head;
	while (prev->next != NULL)
	{
		while (tmp != NULL)
		{
			if (prev->data == tmp->data)
				kill_program(head, NULL, 1);
			tmp = tmp->next;
		}
		prev = prev->next;
		tmp = prev->next;
	}
}

static int	ft_atoi2(const char *nptr, t_stack **head)
{
	int		i;
	int		min;
	long	o;

	i = 0;
	min = 1;
	o = 0;
	if (nptr[i] == '-')
	{
		min = -1;
		i++;
	}
	if (nptr[i] == '\0')
		kill_program(head, NULL, 1);
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			kill_program(head, NULL, 1);
		o = o * 10 + (nptr[i] - '0');
		if (o < INT_MIN || o > INT_MAX)
			kill_program(head, NULL, 1);
		i++;
	}
	return (o * min);
}

static t_stack	*create_node(char *num, t_stack **head)
{
	t_stack	*node;
	node = malloc(sizeof(t_stack));
	if (!node)
		kill_program(head, NULL, 1);
	node->data = ft_atoi2(num, head);
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	create_list(t_stack **stacka, int argc, char **argv)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	*stacka = create_node(argv[i], stacka);
	i++;
	tmp = *stacka;
	while (i < argc)
	{
		tmp->next = create_node(argv[i], stacka);
		tmp = tmp->next;
		i++;
	}
	check_doubles(stacka);
	indexing(*stacka, argc);
	if (list_check(*stacka))
		kill_program(stacka, NULL, 0);
}
