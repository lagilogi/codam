/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 18:42:08 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/28 19:29:31 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static bool	check_list(t_stack *stacka, t_stack *stackb)
{
	if (stackb != NULL)
		return (false);
	if (stacka->next != NULL)
	{
		while (stacka->data < stacka->next->data)
		{
			stacka = stacka->next;
			if (stacka->next == NULL)
				return (true);
		}
	}
	return (false);
}

bool	compare(char *str, char *input)
{
	int	i;

	i = 0;
	while (str[i] && input[i])
	{
		if (str[i] != input[i])
			return (false);
		i++;
	}
	if (str[i] != input[i])
		return (false);
	return (true);
}

bool	input(t_stack **stacka, t_stack **stackb, char **str)
{
	if (compare(*str, "pa\n"))
		ft_push(stackb, stacka);
	else if (compare(*str, "pb\n"))
		ft_push(stacka, stackb);
	else if (compare(*str, "sa\n"))
		ft_swap(stacka, stackb, 'a');
	else if (compare(*str, "sb\n"))
		ft_swap(stacka, stackb, 'b');
	else if (compare(*str, "ss\n"))
		ft_swap(stacka, stackb, 's');
	else if (compare(*str, "ra\n"))
		ft_rotate(stacka, NULL);
	else if (compare(*str, "rb\n"))
		ft_rotate(stackb, NULL);
	else if (compare(*str, "rr\n"))
		ft_rotate(stacka, stackb);
	else if (compare(*str, "rra\n"))
		ft_rev_rotate(stacka, NULL);
	else if (compare(*str, "rrb\n"))
		ft_rev_rotate(stackb, NULL);
	else if (compare(*str, "rrr\n"))
		ft_rev_rotate(stacka, stackb);
	else
		kill_program(stacka, stackb, str, 1);
	return (true);
}

static void	manual_sorting(t_stack **stacka, t_stack **stackb)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		input(stacka, stackb, &str);
		free (str);
		str = get_next_line(0);
	}
	if (check_list(*stacka, *stackb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		kill_program(&stacka, &stackb, NULL, 0);
	create_list(&stacka, argc, argv);
	manual_sorting(&stacka, &stackb);
	kill_program(&stacka, &stackb, NULL, 0);
	return (0);
}
