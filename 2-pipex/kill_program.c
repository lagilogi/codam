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

static void	free_cmd_list(t_cmds *cmds)
{
	t_cmds	*tmp;
	int		i;

	while (cmds != NULL)
	{
		i = 0;
		tmp = cmds->next;
		while (cmds->str[i] != NULL)
		{
			free(cmds->str[i]);
			i++;
		}
		free(cmds->str);
		cmds = tmp;
	}
}

void	kill_program(t_info *info, char *msg, int i)
{
	if (info->cmds != NULL)
	{
		printf("TRUE!\n");
		free_cmd_list(info->cmds);
	}
	if (i == 1)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(i);
}
