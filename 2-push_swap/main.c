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

int		count_nodes(t_list *head)
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

bool	list_check(t_list *head)
{
	while (head->data < head->next->data)
	{
		head = head->next;
		if (head->next == NULL)
			return (true);
	}
	return (false);
}

static int	list_of_2(t_list **head)
{
	int	moves;

	moves = 0;
	if ((*head)->data > (*head)->next->data)
		moves += ft_swap(*head, NULL, 'a');
	return (moves);
}

static int	list_of_3(t_list **head)
{
	int		moves;
	t_list	*node2;
	t_list	*node3;

	moves = 0;
	node2 = (*head)->next;
	node3 = (*head)->next->next;
	while (!((*head)->data < node2->data && node2->data < node3->data))
	{
		if (((*head)->data > node2->data && (*head)->data < node3->data)
			|| ((*head)->data < node2->data && (*head)->data < node3->data))
			moves += ft_swap(*head, NULL, 'a');
		else if ((*head)->data > node2->data && (*head)->data > node3->data)
		{
			moves += ft_rotate(head, NULL, 0, 'a');
			node2 = (*head)->next;
			node3 = (*head)->next->next;
		}
		else if ((*head)->data < node2->data && (*head)->data > node3->data)
		{
			moves += ft_rev_rotate(head, NULL, 0, 'a');
			node2 = (*head)->next;
			node3 = (*head)->next->next;
		}
	}
	return (moves);
}

void	list_of_5(t_list **stacka, t_list **stackb)
{
	int	moves;

	moves = 0;
	moves += ft_push(stacka, stackb, 'b');
	moves += ft_push(stacka, stackb, 'b');
	// while (!list_check(*stacka) && *stacka != NULL)
	// {
	// 	moves +=
	// }
	return (moves);

}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		moves;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		kill_program(&stacka, &stackb, "ERROR: Not enough arguments!", 1);
	create_list(&stacka, argc, argv);
	if (argc == 3)
		printf("Moves: %d", list_of_2(&stacka));
	if (argc == 4)
		printf("Moves: %d", list_of_3(&stacka));
	// if (argc >= 5 && argc <= 6)
	// 	list_of_5(&stacka, &stackb);

	print_list_data(stacka);

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
