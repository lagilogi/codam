/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:29:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/28 18:35:53 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef	struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

void	create_list(t_list **head, int argc, char **argv);
void	kill_program(t_list **stacka, t_list **stackb, char *msg, int i);

int		ft_swap(t_list **head);
int		ft_push(t_list **stack_old, t_list **stack_new);

#endif