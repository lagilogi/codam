/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/10 16:57:50 by wsonepou      ########   odam.nl         */
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

typedef struct s_info {
	int		fd_0;
	int		fd_1;
	char	**paths;
}	t_info;


void	kill_program(t_info *info, char *msg, int i);
void	free_command(char **cmds, char **cmd_path);

void	getting_paths(t_info *info, char **envp);
char	*ft_pathjoin(char const *s1, char const *s2);

void	child_process(t_info *info, char *cmd);

#endif
