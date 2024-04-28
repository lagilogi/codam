/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 13:18:53 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/14 13:46:55 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// I created a different strlen to end on '\n' as well '\0' as all lines, except
// for the last one contain a '\n'.
int	ft_linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	clear_gnl(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
	}
}