/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 15:07:28 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/10 18:41:04 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int size);
int		ft_nlcheck(char *str);
size_t	ft_strlen(const char *s);
char	*ft_printstr(char *str);
char	*ft_reader(int fd, char *rem);
char	*ft_remainder(char *str);

#endif