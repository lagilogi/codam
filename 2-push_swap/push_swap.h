/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:29:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/11 18:41:50 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef	struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev; // prev
}	t_stack;

void	create_list(t_stack **head, int argc, char **argv);
void	kill_program(t_stack **stacka, t_stack **stackb, char *msg, int i);
int		ft_push(t_stack **stack_old, t_stack **stack_new, char x);
int		ft_swap(t_stack **stacka, t_stack **stackb, char x);
int		ft_rotate(t_stack **stack1, t_stack **stack2, char x);
int		ft_rev_rotate(t_stack **stack1, t_stack **stack2, char x);
int		list_of_3(t_stack **head, int moves, int argc);
int		list_of_5(t_stack **stacka, t_stack **stackb, int moves, int argc);
int		move_to_a(t_stack **stacka, t_stack **stackb, int size_a, int size_b);
bool	list_check(t_stack *head);


void	print_list_data(t_stack *head);

#endif
