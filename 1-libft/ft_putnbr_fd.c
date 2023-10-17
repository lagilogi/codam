/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 09:49:37 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 15:14:22 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	q;
	int		i;

	q = '-';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0)
	{
		write(fd, &q, 1);
		n = n * -1;
	}
	if (n > 10)
		ft_putnbr_fd(n / 10, fd);
	n = n % 10;
	i = n + '0';
	write(fd, &i, 1);
}

// int main(){
// 	long int x = 15;
// 	int fd = open("nmbrtest.txt", O_RDWR);
// 	ft_putnbr_fd(x, fd);
// 	close(fd);

// 	return 0;
// }