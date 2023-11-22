/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 10:45:59 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/22 15:57:58 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *rem);
char	*ft_rem(char *rem, char **line);
char	*ft_line(char *rem);
char	*ft_strjoin(char *s1, char *s2);
int		ft_nlcheck(char *str);
int		ft_strlen(char *s);
char	*ft_free(char **str);

#endif