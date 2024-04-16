/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/16 18:58:24 by wsonepou      ########   odam.nl         */
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
	char	**paths;
	int		std_in;
	int		std_out;
	int		infile;
	int		outfile;
	int		cmds;
	int		child_nr;
	int		argc;
	char	*limiter; // bonus
}	t_info;


void	kill_program(t_info *info, int i);
void	free_command(char **cmds, char **cmd_path);

void	creating_child(t_info *info, char *argv, int *fds, char **envp);


#endif