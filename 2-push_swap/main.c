/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/11 16:57:42 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_data(t_stack *head)
{
	int		i = 1;

	if (head == NULL)
		printf("PRINT LIST DATA: Linked list is empty!\n");
	while (head != NULL)
	{
		printf("Node %d - Num: %d, index: %d\n", i, head->data, head->index);
		head = head->next;
		i++;
	}
}

int		count_nodes(t_stack *head)
{
	int	count = 0;

	if (head == NULL)
		printf("Linked list is empty!\n");
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
}

bool	list_check(t_stack *head)
{
	while (head->data < head->next->data)
	{
		head = head->next;
		if (head->next == NULL)
			return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		moves;

	stacka = NULL;
	stackb = NULL;
	moves = 0;
	if (argc < 2)
		kill_program(&stacka, &stackb, "ERROR: Not enough arguments!", 1);
	create_list(&stacka, argc, argv);
	if (argc == 3 || argc == 4)
		moves += list_of_3(&stacka, moves, argc);
	else if (argc == 5 || argc == 6)
		moves += list_of_5(&stacka, &stackb, moves, argc);
	// else if (argc > 6)

	printf("Moves: %d\n", moves); // CHANGE FOR OWN PRINTF
	print_list_data(stacka);
	kill_program(&stacka, &stackb, "Sorting was Succesful!", 0);

	return (0);
}

// ---------------------------------------------------------------------

// int	main(int argc, char **argv)
// {
// 	t_list	*stacka;
// 	t_list	*stackb;

// 	stacka = NULL;
// 	stackb = NULL;
// 	if (argc < 2)
// 		kill_program(&stacka, &stackb, "ERROR: Not enough arguments!\n", 1);
// 	create_list(&stacka, argc, argv);
// 	ft_swap(&stacka); // OLD function that switches nodes instead of values
// 	ft_swap(stacka);
// 	ft_swap(stacka, stackb, 'a');
// 	ft_rotate(&stacka);
// 	ft_push(&stacka, &stackb);
// 	ft_push(&stacka, &stackb);
// 	ft_push(&stacka, &stackb);

// 	printf("List A:\n");		// For testing purposes
// 	print_list_data(stacka);	// For testing purposes
// 	printf("\nList B:\n");		// For testing purposes
// 	print_list_data(stackb);	// For testing purposes

// 	ft_swap_both(stacka, stackb);
// 	ft_swap(stacka, stackb, 'b');
// 	ft_rotate_rev(&stacka, &stackb, 1);
// 	ft_rotate(&stacka);

// 	printf("\n\nAfter Swap Both\n");
// 	printf("List A:\n");		// For testing purposes
// 	print_list_data(stacka);	// For testing purposes
// 	printf("\nList B:\n");		// For testing purposes
// 	print_list_data(stackb);	// For testing purposes

// 	ft_rotate(&stackb, NULL, 0);
// 	ft_rotate(&stacka);

// 	printf("\n\nAfter Swap Both\n");
// 	printf("List A:\n");		// For testing purposes
// 	print_list_data(stacka);	// For testing purposes
// 	printf("\nList B:\n");		// For testing purposes
// 	print_list_data(stackb);	// For testing purposes

// 	// ft_rotate(&stacka, &stackb, 1);
// 	ft_rotate(&stacka);

// 	printf("\n\nAfter Swap Both\n");
// 	printf("List A:\n");		// For testing purposes
// 	print_list_data(stacka);	// For testing purposes
// 	printf("\nList B:\n");		// For testing purposes
// 	print_list_data(stackb);	// For testing purposes

// 	return (0);
// }
