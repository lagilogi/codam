/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:29:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 13:58:04 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_command(char **cmds, char **cmd_path)
{
	if (*cmd_path != NULL)
		free(cmd_path);
	if (cmds[1] != NULL)
		free(cmds[1]);
	if (cmds[0] != NULL)
		free(cmds[0]);
	if (cmds != NULL)
		free(cmds);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	kill_program(char **paths, char *argv, int i)
{
	if (paths != NULL)
		free_paths(paths);
	if (i > 0)
		perror(argv);
	exit(i);
}
