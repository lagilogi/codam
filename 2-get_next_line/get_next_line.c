/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line3.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 12:55:27 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/10 18:44:23 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str[i + 1] = '\0';
	return (str);
}

int	ft_nlcheck(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		else if (str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_reader(int fd, char *rem)
{
	char	*str;
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	str = ft_strjoin(rem, buffer, BUFFER_SIZE);
	while (ft_nlcheck(buffer) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (str);
}

char	*ft_remainder(char *str)
{
	char	*rem;
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (*str != '\n' && *str != '\0')
		str++;
	str++;
	while (str[i] != '\0')
		i++;
	if (i > 0)
	{
		rem = malloc(i + 1);
		if (rem == NULL)
			return (NULL);
		while (str[o])
		{
			rem[o] = str[o];
			o++;
		}
		rem[o] = '\0';
		return (rem);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rem = 0;
	char		*str;
	char		*buffer;
	int			bytes_read;

	// ft_remcheck -----------------------------Hier ff goed naar kijken
	if (rem != NULL)
	{
		if (ft_nlcheck(rem) > -1)
			return (ft_printstr(rem));
	}



	// ft_reader -------------------------------Dit lijkt prima te werken
	str = ft_reader(fd, rem);
	if (str == NULL)
		return (NULL);



	// ft_remainder
	rem = ft_remainder(str);
	if (rem == NULL)
		return (NULL);



	// ft_printstr
	str = ft_printstr(str);



	return (str);
}

int	main(void)
{
	int		fd;
	char	*l;

	fd = open("textfile.txt", O_RDONLY);
	if (fd == -1)
		printf("Couldn't open file - Make sure the path is correct.");
	l = get_next_line(fd);
	printf("%s", l);
	free (l);
	l = get_next_line(fd);
	printf("%s", l);
	free (l);

	return (0);
}

