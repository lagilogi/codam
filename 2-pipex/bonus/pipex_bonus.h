/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/22 18:47:41 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_info
{
	char	**paths;
	int		infile;
	int		outfile;
	int		cmds;
	int		child_nr;
	int		argc;
	bool	heredoc; // bonus
	char	*limiter; // bonus
	int		limiter_len; // bonus
}	t_info;

void	kill_program(t_info *info, int i);
void	free_command(char **cmds, char **cmd_path);

void	creating_child(t_info *info, char *argv, int *fds, char **envp);

void	here_doccer(t_info *info); // BONUS

#endif