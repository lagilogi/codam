/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:27:05 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 15:14:39 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

typedef unsigned long size_t;

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s = (unsigned char *) src;
	unsigned char	*d = dest;
	size_t	i;

	i = 0;
	if(dest < src)
	{
		while(i < n)
		{
		d[i] = s[i];
		i++;
		}
	}
	else
	{
		n -= 1;
		while (n > 0)
		{
			d[n] = s[n];
			n--;
		}
		d[0] = s[0];
	}
	return (char *) dest;		
}

// int main(void){
// 	char dest[] = "1234!";
// 	char src[] = "There";
// 	char dest2[] = "1234!";
// 	char src2[] = "There";
// 	ft_memmove(dest, src, 7);
// 	memmove(dest2, src2, 7);
// 	printf("%s\n", dest);
// 	printf("%s", dest2);

// 	return 0;
// }