/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:23:30 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/10 16:55:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_info *info, char *cmd)
{
	int		i;
	char	**cmds;
	char	*cmd_path;


	i = 0;
	cmds = ft_split(cmd, ' ');
	if (cmd == NULL)
		kill_program(info, "ERROR: Splitting command & flags failed!", 1);


	cmd_path = ft_pathjoin(info->paths[i], cmds[0]);


	while (cmd_path != NULL && access(cmd_path, F_OK | X_OK) == -1)
	{
		free(cmd_path);
		printf("[%s] in directory: %s\n", cmds[0], info->paths[i]);
		cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
		if (cmd_path == NULL)
			break ;
			// kill_program(&info, "ERROR: Pathjoin malloc failed/ Couldn't find command!", 1);
		i++;
	}


	if (cmd_path != NULL)
	{
		printf("COMMAND FOUND!\n"); // REPLACE WITH 'EXECVE' or NEW FUNCTION
		free(cmd_path);
	}
	else
		free_command(cmds, &cmd_path);


	kill_program(info, "ENDING CHILD!\n", 0);
}

