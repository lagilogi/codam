/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:29:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/10 13:29:35 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_command(char **cmds, char **cmd_path)
{
	if (*cmd_path != NULL)
	{
		printf("CMD_PATH IS NOT NULL\n");
		free(cmd_path);
	}
	free(cmds[0]);
	if (cmds[1] != NULL)
		free(cmds[1]);
	free(cmds);
}

static void	free_paths(t_info *info)
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

void	kill_program(t_info *info, char *msg, int i)
{
	info = NULL;
	if (info->paths != NULL)
		free_paths(info);
	if (i == 1)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(i);
}
