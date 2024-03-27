/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:29:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/27 17:26:40 by wsonepou      ########   odam.nl         */
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

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pos_b
{
	int	current_pos;
	int	dif;
	int	pos;
}	t_pos_b;

typedef struct s_info
{
	int		size_a;
	int		rot_a;
	int		rev_rot_a;
	int		size_b;
	int		rot_b;
	int		rev_rot_b;
	int		rot_a_b;
	int		rev_rot_a_b;
	int		min_moves;
	int		min;
	int		max;
	bool	halved;
	bool	end;
	int		moves;
}	t_info;

void	create_list(t_stack **head, int argc, char **argv);
void	kill_program(t_stack **stacka, t_stack **stackb, int i);

void	ft_push(t_stack **stack_old, t_stack **stack_new, t_info *info, char x);
void	ft_swap(t_stack **stacka, t_stack **stackb, char x);
void	ft_rotate(t_stack **stack1, t_stack **stack2, char x);
void	ft_rev_rotate(t_stack **stack1, t_stack **stack2, char x);

void	sorting(t_stack **stacka, t_stack **stackb, t_info *info);
void	list_of_3(t_stack **head, t_info *info);

void	move_to_a(t_stack **stacka, t_stack **stackb, t_info *info);
void	rotate_till_correct(t_stack **stacka, t_info *info);
bool	list_check_a(t_stack *head);

void	move_to_b(t_stack **stacka, t_stack **stackb, t_info *info);
void	rotate_b_till_correct(t_stack **stackb, t_info *info);
void	limit_stack_b(t_stack *stackb, t_info *info);
int		find_smallest_b(t_stack *stackb, t_info *info);
int		skip_half(t_stack **stackb, t_info *info);
void	set_info_pos_b(t_pos_b	*tmp);

bool	just_rotate(t_stack *stacka);
int		find_minimum(t_stack *head);
void	reset_info(t_info *info);
void	set_info(int a, int b, t_info *info);
int		check_moves(int a, int b, t_info *info);

#endif
