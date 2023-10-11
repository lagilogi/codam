/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 13:55:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/08 14:19:20 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (char *)&s[i];
		i--;
	}

	return (0);
}

int main(){
	char hay[] = "haystacks";
	char ndl = '\0';
	printf("%p\n", ft_strrchr(hay, ndl));
	printf("%p\n\n", strrchr(hay, ndl));
	
	return 0;
}