/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 12:52:55 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/13 13:25:46 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void ft_putendl_fd(char *s, int fd)
{
	char n; 
	
	n = '\n';	
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, &n, 1);
}

// int main(){
// 	char x[] = "Ssdfsdfsdf";
// 	int fd = open("easie.txt", O_RDWR);
// 	ft_putendl_fd(x, fd);
// 	close(fd);

// 	return 0;
// }