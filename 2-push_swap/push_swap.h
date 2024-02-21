/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 11:29:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/21 18:39:30 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef	struct s_list
{
	int				value;
	int				index;
	// struct s_list 	*prev;
	struct s_list	*next;
}	t_list;

t_list	*initialize(t_list *sa, int argc, char **argv);

#endif
