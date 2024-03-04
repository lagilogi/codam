/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 19:06:55 by wsonepou      ########   odam.nl         */
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
	// ft_swap(&stacka); // OLD function that switches nodes instead of values
	// ft_swap(stacka);
	// ft_swap(stacka, stackb, 'a');
	// ft_rotate(&stacka);
	ft_push(&stacka, &stackb);
	ft_push(&stacka, &stackb);
	ft_push(&stacka, &stackb);

	printf("List A:\n");		// For testing purposes
	print_list_data(stacka);	// For testing purposes
	printf("\nList B:\n");		// For testing purposes
	print_list_data(stackb);	// For testing purposes

	// ft_swap_both(stacka, stackb);
	// ft_swap(stacka, stackb, 'b');
	ft_rotate_rev(&stacka, &stackb, 1);
	// ft_rotate(&stacka);

	// printf("\n\nAfter Swap Both\n");
	printf("List A:\n");		// For testing purposes
	print_list_data(stacka);	// For testing purposes
	printf("\nList B:\n");		// For testing purposes
	print_list_data(stackb);	// For testing purposes

	// ft_rotate(&stackb, NULL, 0);
	// ft_rotate(&stacka);

	// printf("\n\nAfter Swap Both\n");
	// printf("List A:\n");		// For testing purposes
	// print_list_data(stacka);	// For testing purposes
	// printf("\nList B:\n");		// For testing purposes
	// print_list_data(stackb);	// For testing purposes

	// // ft_rotate(&stacka, &stackb, 1);
	// ft_rotate(&stacka);

	// printf("\n\nAfter Swap Both\n");
	// printf("List A:\n");		// For testing purposes
	// print_list_data(stacka);	// For testing purposes
	// printf("\nList B:\n");		// For testing purposes
	// print_list_data(stackb);	// For testing purposes

	return (0);
}
