/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_nodes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:30:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 17:31:27 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_list **head)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = (*head)->next;
	prev = *head;
	while (prev->next != NULL)
	{
		while (tmp != NULL)
		{
			if (prev->data == tmp->data)
				kill_program(head, NULL, "ERROR: Double integer found!", 1);
			tmp = tmp->next;
		}
		prev = prev->next;
		tmp = prev->next;
	}
}

static int	ft_atoi2(const char *nptr, t_list **head)
{
	int			i;
	int			min;
	int			o;

	i = 0;
	min = 1;
	o = 0;
	if (nptr[i] == '-')
	{
		min = -1;
		i++;
	}
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			kill_program(head, NULL, "ERROR: Not a Number!", 1);
		o = o * 10 + (nptr[i] - '0');
		i++;
	}
	return (o * min);
}

static t_list	*create_node(char *num, t_list **head)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (!node)
		kill_program(head, NULL, "ERROR: Failed to malloc node!", 1);
	node->data = ft_atoi2(num, head);
	node->next = NULL;

	return (node);
}

void	create_list(t_list **head, int argc, char **argv)
{
	t_list	*tmp;
	int		i = 1;

	*head = create_node(argv[i], head);
	i++;
	tmp = *head;
	while (i < argc)
	{
		tmp->next = create_node(argv[i], head);
		tmp = tmp->next;
		i++;
	}
	check_doubles(head);
}
