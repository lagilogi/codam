/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:29:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/22 19:01:41 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_command(char **cmds, char **cmd_path)
{
	if (*cmd_path != NULL)
		free(cmd_path);
	free(cmds[0]);
	if (cmds[1] != NULL)
		free(cmds[1]);
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

void	kill_program(char **paths, int i)
{
	if (paths != NULL)
		free_paths(paths);
	if (i > 0)
		perror("ERROR");
	exit(i);
}
