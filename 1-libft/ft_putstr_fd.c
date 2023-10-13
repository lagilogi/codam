/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 12:30:51 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/13 12:51:57 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void ft_putstr_fd(char *s, int fd)
{
	while(*s)
	{
		write(fd, s, sizeof(char));
		s++;
	}
}

// int main(){
// 	char str[] = "bbhbhbhgv hg";
// 	int fd = open("easy.txt", O_RDWR);
// 	if (fd == -1)
// 		printf("Error opening file");
// 	ft_putstr_fd(str, fd);
// 	close(fd);

// 	return 0;
// }