/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:23:30 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/11 15:39:40 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_info *info, char *cmd, char **envp)
{
	int		i;
	char	**cmds;
	char	*cmd_path;

	i = 0;
	cmds = ft_split(cmd, ' ');
	if (cmd == NULL)
		kill_program(info, errno);
	cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
	while (cmd_path != NULL && access(cmd_path, F_OK | X_OK) == -1)
	{
		free(cmd_path);
		cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
		i++;
	}
	if (cmd_path == NULL)
	{
		printf("CMD PATH IS NULL!\n");
		free_command(cmds, &cmd_path);
		kill_program(info, errno);
	}
	else
		execve(cmd_path, cmds, envp);
	kill_program(info, errno);
}

void	creating_child(t_info *info, char *argv, char **envp)
{
	const int	pid = fork();

	if (pid == -1)
		kill_program(info, errno);
	if (pid == 0)
		child_process(info, argv, envp);
}
