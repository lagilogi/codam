/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:29:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/13 18:12:06 by wsonepou      ########   odam.nl         */
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
}	t_stack;

typedef struct s_info
{
	int	size_a;
	int	size_b;
	int	moves;
}	t_info;

void	create_list(t_stack **head, int argc, char **argv);
void	kill_program(t_stack **stacka, t_stack **stackb, char *msg, int i);

void		ft_push(t_stack **stack_old, t_stack **stack_new, t_info *info, char x);
void		ft_swap(t_stack **stacka, t_stack **stackb, t_info *info, char x);
void		ft_rotate(t_stack **stack1, t_stack **stack2, t_info *info, char x);
void		ft_rev_rotate(t_stack **stack1, t_stack **stack2, t_info *info, char x);

void	list_of_3(t_stack **head, t_info *info);
void	sorting(t_stack **stacka, t_stack **stackb, t_info *info);
void	move_to_a(t_stack **stacka, t_stack **stackb, t_info *info);
void	move_to_b(t_stack **stacka, t_stack **stackb, t_info *info);
int		find_position(t_stack *stack1, t_stack *stack2);
void	rotate_till_correct(t_stack **stacka, t_info *info);
bool	list_check(t_stack *head); // Can probably be made static and removed here
bool	just_rotate(t_stack **stacka);

void	print_list_data(t_stack *stacka, t_stack *stackb);

#endif
