/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 14:36:21 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/08/06 17:05:37 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	setting_io(t_info *info)
{
	int	infile;

	if (info->current_cmd == 1 && info->heredoc == false)
	{
		infile = open(info->infile, O_RDONLY);
		if (infile == -1)
			kill_program(info, "infile", errno);
		if (dup2(infile, STDIN_FILENO) == -1)
			kill_program(info, "dup2 infile", errno);
		if (close(infile) == -1)
			perror("infile");
	}
	if (dup2(info->fds[1], STDOUT_FILENO) == -1)
		kill_program(info, "dup2 info->fds[1]", errno);
	closing_fds(info->fds);
}

char	*ft_pathjoin(char const *s1, char const *s2)
{
	int		i;
	int		o;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	o = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((o + 2) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	p[i] = '/';
	i++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}
