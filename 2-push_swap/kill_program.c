/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 17:53:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/19 14:59:12 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_list(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

void	kill_program(t_stack **stacka, t_stack **stackb, int i)
{
	if (stacka != NULL && *stacka != NULL)
		delete_list(stacka);
	if (stackb != NULL && *stackb != NULL)
		delete_list(stackb);
	if (i == 1)
		write(2, "Error\n", 6);
	exit(i);
}
