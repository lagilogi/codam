/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/02 17:50:10 by wsonepou      ########   odam.nl         */
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

typedef struct s_cmds {
	char			**str;
	bool			exec_found;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_info {
	int		fd_0;
	int		fd_1;
	t_cmds	*cmds;
}	t_info;


void	kill_program(t_info *info, char *msg, int i);
void	parsing_command(t_info *info, int argc, char **argv);

#endif
