/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 10:44:25 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/02 19:06:41 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_nlcheck(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *rem, char *buffer)
{
	char	*new;
	int		i;
	int		o;

	o = 0;
	if (rem == NULL)
		i = ft_strlen(buffer);
	else
		i = ft_strlen(rem) + ft_strlen(buffer);
	new = malloc(i + 1);
	if (!new)
		return (ft_free(&rem));
	i = 0;
	while (rem != NULL && rem[i])
	{
		new[i] = rem[i];
		i++;
	}
	while (buffer[o])
		new[i++] = buffer[o++];
	new[i] = '\0';
	ft_free (&rem);
	return (new);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
