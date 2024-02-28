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

static int	ft_atoi2(const char *nptr)
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
		{
			printf("NOT A NUMBER!\n"); // VERVANG DOOR FT_PRINTF
			exit(EXIT_FAILURE); // EXIT
		}
		o = o * 10 + (nptr[i] - '0');
		i++;
	}
	return (o * min);
}

static t_list	*create_node(char *num)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (!node)
		exit(1); // EXIT
	node->data = ft_atoi2(num);
	node->next = NULL;

	return (node);
}

void	create_list(t_list **head, int argc, char **argv)
{
	t_list	*tmp;
	int		i = 1;

	*head = create_node(argv[i]);
	i++;
	tmp = *head;
	while (i < argc)
	{
		tmp->next = create_node(argv[i]);
		tmp = tmp->next;
		i++;
	}
}