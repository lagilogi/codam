/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 18:32:56 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_data(t_list *head)
{
	int		i = 1;

	if (head == NULL)
		printf("PRINT LIST DATA: Linked list is empty!\n");
	while (head != NULL)
	{
		printf("Node %d contains Num: %d\n", i, head->data);
		head = head->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		kill_program(&stacka, &stackb, "ERROR: Not enough arguments!\n", 1);
	create_list(&stacka, argc, argv);
	ft_swap(&stacka);
	ft_push(&stacka, &stackb);
	ft_push(&stackb, &stacka);
	printf("List A:\n");
	print_list_data(stacka);
	printf("\nList B:\n");
	print_list_data(stackb);

	return (0);
}
