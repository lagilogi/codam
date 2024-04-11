/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/11 16:16:37 by wsonepou      ########   odam.nl         */
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
	int		infile;
	int		outfile;
	char	**paths;
	char	*limiter; // bonus
}	t_info;


void	kill_program(t_info *info, int i);
void	free_command(char **cmds, char **cmd_path);

void	getting_paths(t_info *info, char **envp);
char	*ft_pathjoin(char const *s1, char const *s2);

void	creating_child(t_info *info, char *argv, char **envp);
void	child_process(t_info *info, char *cmd, char **envp);

#endif
