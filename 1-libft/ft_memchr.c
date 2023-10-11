/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 10:27:52 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/10 13:27:15 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void *ft_memchr(const void *s, int c, size_t n){
	int	i;
	unsigned char *hay = (unsigned char *) s;
	

	i = 0;
	while (i < n)
	{
		if (*hay == (unsigned char) c)
			return (hay);
		else
			hay++;
			i++;
	}
	return (0);
}

int main(){
	char s[50] = "This is a string";
	char c = '.';
	printf("%p\n", ft_memchr(s, c, 20));
	printf("%p", memchr(s, c, 20));

	return 0;
}