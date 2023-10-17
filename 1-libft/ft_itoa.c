/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 16:10:24 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 15:15:00 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int ft_lencheck(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len++;
		return len;
	}
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return len;
}

char *ft_itoa(int n)
{
	int	i;
	char *p;

	if (n == -2147483648)
		return ("-2147483648\0");
	i = ft_lencheck(n);
	p = malloc((i + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	p[i] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		p[0] = n + '0';
	else
		while (n > 0)
		{
			i--;
			p[i] = n % 10 + '0';
			n = n / 10;
		}
	return (p);
}

// int main(){
// 	int i = -2147483648;
// 	printf("%s\n", ft_itoa(i));
	
// 	return 0;
// }
