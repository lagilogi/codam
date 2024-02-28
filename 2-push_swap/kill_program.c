/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 17:53:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 18:11:07 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_list(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
	printf("List deleted!\n");
}

void	kill_program(t_list **stacka, t_list **stackb, char *msg, int i)
{
	if (*stacka != NULL)
		delete_list(stacka);
	if (*stackb != NULL)
		delete_list(stackb);
	printf("%s", msg);
	exit(i);
}