/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 12:58:14 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/08 13:53:12 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *s, int c){
	while(*s != '\0')
	{
		if (s == c)
			return (char *)s;
		s++;
	}
	if (*s == '\0')
		return (char *)s;

	return (0);
}

int main(){
	char hay[] = "Haystack";
	char ndl = '\0';
	printf("%p\n", ft_strchr(hay, ndl));
	printf("%p\n\n", strchr(hay, ndl));
	printf("%s\n", ft_strchr(hay, ndl));
	printf("%s", strchr(hay, ndl));

	return 0;
}