/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 18:42:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/26 18:44:25 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

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



#endif