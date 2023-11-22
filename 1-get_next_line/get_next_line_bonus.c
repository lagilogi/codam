/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 10:45:04 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/22 15:57:21 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rem(char *rem, char **line)
{
	char	*new;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (rem[i] == '\n')
		i++;
	if (rem[i] == '\0')
		return (ft_free(&rem));
	new = malloc(ft_strlen(rem) - i + 1);
	if (!new)
	{
		ft_free(&rem);
		return (ft_free(line));
	}
	while (rem[i])
		new[i2++] = rem[i++];
	new[i2] = '\0';
	ft_free(&rem);
	return (new);
}

char	*ft_line(char *rem)
{
	char	*line;
	int		i;
	int		o;

	i = 0;
	o = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (rem[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (o < i)
	{
		line[o] = rem [o];
		o++;
	}
	line[o] = '\0';
	return (line);
}

char	*ft_read(int fd, char *rem)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&rem));
	bytes_read = 1;
	while (ft_nlcheck(rem) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			rem = ft_strjoin(rem, buffer);
			if (!rem)
				return (ft_free(&buffer));
		}
	}
	ft_free (&buffer);
	if (bytes_read < 0)
		return (ft_free(&rem));
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*rem[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	rem[fd] = ft_read(fd, rem[fd]);
	if (rem[fd] == NULL)
		return (NULL);
	line = ft_line(rem[fd]);
	if (!line)
		return (ft_free(&rem[fd]));
	rem[fd] = ft_rem(rem[fd], &line);
	return (line);
}

// int main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int 	i;

// 	i = i;
// 	fd = open("textfile.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("Opening file failed");
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("call %d: %s", i, line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }