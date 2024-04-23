/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 17:44:03 by wsonepou      ########   odam.nl         */
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
# include "./libft/libft.h"

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

pid_t	creating_childs(t_info *info, char **argv, char **envp);

void	here_doccer(t_info *info);
char	*ft_pathjoin(char const *s1, char const *s2);
void	closing_fds(int *fds);

#endif