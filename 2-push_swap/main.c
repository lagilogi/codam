/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:28:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/13 18:11:13 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_data(t_stack *stacka, t_stack *stackb)
{
	int		i = 0;

	ft_printf("\n- Stack A -\n");
	if (stacka == NULL)
		ft_printf("Stack empty!\n");
	while (stacka != NULL)
	{
		ft_printf("Node %d - Num: %d\n", i, stacka->data);
		stacka = stacka->next;
		i++;
	}
	i = 0;
	// stackb = NULL;
	ft_printf("\n");
	ft_printf("- Stack B -\n");
	if (stackb == NULL)
		ft_printf("Stack empty!\n");
	while (stackb != NULL)
	{
		ft_printf("Node %d - Num: %d\n", i, stackb->data);
		stackb = stackb->next;
		i++;
	}
	ft_printf("\n\n");
}

static void	set_info(t_info *info, int argc)
{
	info->size_a = argc - 1;
	info->size_b = 0;
	info->moves = 0;
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_info	info;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		kill_program(&stacka, &stackb, "ERROR: Not enough arguments!", 1);
	set_info(&info, argc);
	create_list(&stacka, argc, argv);
	sorting(&stacka, &stackb, &info);

	ft_printf("Moves: %d\n", info.moves);
	print_list_data(stacka, stackb);
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
