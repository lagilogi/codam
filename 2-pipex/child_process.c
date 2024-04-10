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
	char	*cmd_path;
	char	**cmds;

	i = 0;
	cmds = ft_split(cmd, ' ');
	// if (cmd == NULL)
		// end_child(&info, "ERROR: Pathjoin malloc failed/ Couldn't find command!", 1);
	cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
	while (cmd_path != NULL && access(cmd_path, F_OK | X_OK) == -1)
	{
		free(cmd_path);
		printf("[%s] in directory: %s\n", cmds[0], info->paths[i]);
		cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
		if (cmd_path == NULL)
			break ;
			// end_child(&info, "ERROR: Pathjoin malloc failed/ Couldn't find command!", 1);
		i++;
	}
	if (cmd_path != NULL)
		printf("FOUND COMMAND: %s\n", cmd_path);
	else
		printf("Didn't find command: %s\n", cmds[0]);
	free(cmd_path);
	free(cmds[0]);
	if (cmds[1] != NULL)
		free(cmds[1]);
	free(cmds);
}

