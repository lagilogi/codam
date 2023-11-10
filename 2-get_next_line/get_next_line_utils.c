/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 15:13:32 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/10 15:50:00 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2, int size)
{
	int		i;
	int		o;
	char	*p;

	i = 0;
	if (s1 == NULL)
		o = ft_strlen(s2);
	else
		o = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((o + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		p[i] = *s2++;
		i++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}
