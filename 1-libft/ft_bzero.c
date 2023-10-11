/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 15:36:42 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/11 14:06:00 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *p = s;

	while(n > 0)
	{
		*p = 0;
		n--;
		if (n > 0)
			p++;
	}
}

int main(){
	char str[] = "testcase";
	printf("%s\n", str);
	printf("%d", ft_bzero(str, 3));

	return 0;
}