/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:29:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/30 13:16:34 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	closing_fds(int *fds)
{
	if (fds[0] != -1 && close(fds[0]) == -1)
		perror("fds[0]");
	if (fds[1] != -1 && close(fds[1]) == -1)
		perror("fds[1]");
	fds[0] = -1;
	fds[1] = -1;
}

void	free_command(char **cmds, char **cmd_path)
{
	if (cmd_path != NULL && *cmd_path != NULL)
		free(cmd_path);
	if (cmds[0] != NULL && cmds != NULL && cmds[1] != NULL)
		free(cmds[1]);
	if (cmds != NULL && cmds[0] != NULL)
		free(cmds[0]);
	if (cmds != NULL)
		free(cmds);
}

void	free_paths(t_info *info)
{
	int	i;

	i = 0;
	while (info->paths[i] != NULL)
	{
		free(info->paths[i]);
		i++;
	}
	free(info->paths);
}

void	kill_program(t_info *info, char *arg, int i)
{
	closing_fds(info->fds);
	if (info->paths != NULL)
		free_paths(info);
	if (i > 0 && errno > 0 && arg != NULL)
		perror(arg);
	exit(i);
}
