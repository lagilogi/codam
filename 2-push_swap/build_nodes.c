/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_nodes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:30:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/19 15:27:30 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if ((o > INT_MAX && min == 1) || (o - 1 > INT_MAX && min == -1))
			kill_program(head, NULL, 1);
		i++;
	}
	return (o * min);
}

static t_stack	*create_node(char *num, t_stack **head)
{
	int		value;
	t_stack	*node;

	value = ft_atoi2(num, head);
	node = malloc(sizeof(t_stack));
	if (!node)
		kill_program(head, NULL, 1);
	node->data = value;
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
	if (list_check(*stacka))
		kill_program(stacka, NULL, 0);
}
