/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 14:22:14 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	bool	heredoc;
	char	*limiter;
	int		limiter_len;
}	t_info;

void	kill_program(t_info *info, int i);
void	free_command(char **cmds, char **cmd_path);

void	creating_child(t_info *info, char *argv, int *fds, char **envp);
pid_t	last_child(t_info *info, char **argv, char **envp);

void	here_doccer(t_info *info);

#endif