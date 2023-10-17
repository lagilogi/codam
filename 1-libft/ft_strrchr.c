/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 13:55:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 17:13:19 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	int 		i;
	char	*p;

	p = (char *)s;
	i = ft_strlen(p);
	while (i >= 0)
	{
		if (p[i] == c)
			return (p + i);
		i--;
	}

	return (0);
}

int main(){
	char hay[] = "haystacks";
	char ndl = 'h';
	printf("%p\n", ft_strrchr(hay, ndl));
	printf("%p\n", strrchr(hay, ndl));
	
	return 0;
}