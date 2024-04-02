/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:24:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/02 16:25:25 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_cmds	*create_node(t_info *info, char *str)
{
	t_cmds	*node;

	node = malloc(sizeof(t_cmds));
	if (node == NULL)
		kill_program(info, "ERROR: Creating node failed!", 1);
	node->str = ft_split(str, ' ');
	if (node->str == NULL)
		kill_program(info, "ERROR: Ft_split failed!", 1);
	node->exec_found = false;
	node->next = NULL;
	return (node);
}



void	parsing_command(t_info *info, int argc, char **argv)
{
	t_cmds	*tmp;
	int		i;

	i = 3;
	info->cmds = create_node(info, argv[2]);
	if (info->cmds == NULL)
		kill_program(info, "ERROR: Creating first node failed!", 1);
	tmp = info->cmds;
	while (i < argc - 1)
	{
		tmp->next = create_node(info, argv[i]);
		tmp = tmp->next;
		i++;
	}
}