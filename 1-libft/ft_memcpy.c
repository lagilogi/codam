/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:25:36 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/16 11:06:45 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	unsigned char *s = (unsigned char *) src;
	int i;

	i = 0;
	while (i < n)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}

	return (char *) dest;
}

int main(void){
	char dest[] = "1234!";
	char src[] = "There";
	char dest2[] = "1234!";
	char src2[] = "There";
	ft_memcpy(dest, src, 6);
	memcpy(dest2, src2, 6);
	printf("%s\n", dest);
	printf("%s", dest2);

	return 0;
}