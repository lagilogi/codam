/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_nodes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:30:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/21 18:57:42 by wsonepou      ########   odam.nl         */
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

static t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (tmp);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

static t_list	*ft_lstnew(int num, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->value = num;
	new->index = index;
	new->next = NULL;
	// new->prev = NULL;
	return (new);
}

t_list	*initialize(t_list *stacka, int argc, char **argv)
{
	t_list	*new;
	t_list	*tmp;
	int		i;
	int		num;

	i = 1;
	num = ft_atoi2(argv[i]);
	stacka = ft_lstnew(num, i);
	i++;
	while (i < argc)
	{
		num = ft_atoi2(argv[i]);
		tmp = ft_lstnew(num, i);
		ft_lstadd_back(&stacka, tmp);
		i++;
	}
	return (stacka);
}
