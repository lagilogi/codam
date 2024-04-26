/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/26 17:25:30 by wsonepou      ########   odam.nl         */
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
	char	*infile;
	char	*outfile;
	int		cmds;
	int		current_cmd;
	int		argc;
	int		fds[2];
	bool	heredoc;
	char	*limiter;
	int		limiter_len;
}	t_info;

pid_t	creating_children(t_info *info, char **argv, char **envp);
void	ft_heredoc(t_info *info);
char	*ft_pathjoin(char const *s1, char const *s2);
void	setting_io(t_info *info);
void	kill_program(t_info *info, char *arg, int i);
void	free_command(char **cmds, char **cmd_path);
void	free_paths(t_info *info);
void	closing_fds(int *fds);

#endif