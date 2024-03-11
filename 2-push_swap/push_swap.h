/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:29:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 19:00:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef	struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

void	create_list(t_list **head, int argc, char **argv);
void	kill_program(t_list **stacka, t_list **stackb, char *msg, int i);
int		ft_push(t_list **stack_old, t_list **stack_new, char x);
// int		ft_swap(t_list *stacka, t_list *stackb, char x);
int		ft_swap(t_list **stacka, t_list **stackb, char *action, char x);
int		ft_rotate(t_list **stack1, t_list **stack2, int i, char x);
int		ft_rev_rotate(t_list **stack1, t_list **stack2, int i, char x);
bool	list_check(t_list *head);

#endif
