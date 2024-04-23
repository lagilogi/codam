/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 14:36:21 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 17:40:57 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closing_fds(int *fds)
{
	if (close(fds[0]) == -1)
		perror("fds[0]");
	if (close(fds[1]) == -1)
		perror("fds[1]");
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

void	ft_heredoc()
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL) // str != NULL && something else
	{
		free (str);
		str = get_next_line(0);
	}
}
