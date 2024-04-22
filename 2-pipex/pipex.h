/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:39:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/22 19:19:53 by wsonepou      ########   odam.nl         */
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

void	kill_program(char **paths, int i);
void	free_paths(char **paths);
void	free_command(char **cmds, char **cmd_path);

void	cmd_1(char **paths, char **argv, int *fds, char **envp);
pid_t	cmd_2(char **paths, char **argv, int *fds, char **envp);

#endif