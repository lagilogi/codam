/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/02 13:29:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/15 16:38:25 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	kill_program(t_info *info, int i)
{
	if (info->paths != NULL)
		free_paths(info);
	close (info->infile);
	close (info->outfile);
	if (i > 0)
		perror("ERROR");
	exit(i);
}
