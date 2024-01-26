/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 10:45:59 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/27 14:52:03 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *rem);
char	*ft_rem(char *rem, char **line_address);
char	*ft_line(char *rem);
char	*ft_strjoin(char *s1, char *s2);
int		ft_nlcheck(char *str);
int		ft_strlen(char *s);
char	*ft_free(char **str);

#endif