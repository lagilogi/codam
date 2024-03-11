/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_lists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/11 14:30:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/11 18:36:36 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_of_3(t_stack **head, int moves, int argc)
{
	t_stack	*node2;
	t_stack	*node3;

	node2 = (*head)->next;
	node3 = (*head)->next->next;
	if (argc == 3)
	{
		if ((*head)->data > (*head)->next->data)
			moves += ft_swap(head, NULL, 'a');
		return (moves);
	}
	while (!((*head)->data < node2->data && node2->data < node3->data))
	{
		if (((*head)->data > node2->data && (*head)->data < node3->data)
			|| ((*head)->data < node2->data && (*head)->data < node3->data))
			moves += ft_swap(head, NULL, 'a');
		else if ((*head)->data > node2->data && (*head)->data > node3->data)
			moves += ft_rotate(head, NULL, 'a');
		else if ((*head)->data < node2->data && (*head)->data > node3->data)
			moves += ft_rev_rotate(head, NULL, 'a');
		node2 = (*head)->next;
		node3 = (*head)->next->next;
	}
	return (moves);
}

int	list_of_5(t_stack **stacka, t_stack **stackb, int moves, int argc)
{
	int	size_a;
	int	size_b;

	size_a = argc - 1;
	moves += ft_push(stacka, stackb, 'b');
	if (argc > 5)
		moves += ft_push(stacka, stackb, 'b');


	printf("STACK A:\n");
	print_list_data(*stacka);
	printf("STACK B:\n");
	print_list_data(*stackb);
	printf("\n");


	size_a = argc - 1 - moves;
	size_b = moves;
	moves = list_of_3(stacka, moves, argc);
	// if (size_a > 3)
	// 	moves += move_to_b(stacka, stackb, size_a, size_b);
	moves += move_to_a(stacka, stackb, size_a, size_b);
	return (moves);
}
