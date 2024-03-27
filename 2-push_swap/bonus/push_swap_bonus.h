/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/26 18:42:45 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/27 13:14:17 by wsonepou      ########   odam.nl         */
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

void	create_list(t_stack **stacka, int argc, char **argv);
void	kill_program(t_stack **stacka, t_stack **stackb, char **str, int i);

void	ft_push(t_stack **stack_old, t_stack **stack_new);
void	ft_swap(t_stack **stacka, t_stack **stackb, char x);
void	ft_rotate(t_stack **stack1, t_stack **stack2);
void	ft_rev_rotate(t_stack **stack1, t_stack **stack2);

char	*get_next_line(int fd);
char	*ft_read(int fd, char *rem);
char	*ft_rem(char *rem, char **line_address);
char	*ft_line(char *rem);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_nlcheck(char *str);
char	*ft_free2(char **str);

#endif