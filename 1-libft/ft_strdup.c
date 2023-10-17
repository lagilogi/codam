/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 14:29:03 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 15:14:07 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(const char *s)
{
	size_t	c;
	size_t	i;
	char	*pS;

	c = strlen(s);
	i = c + 1;
	pS = malloc(i);
	while(i > 0)
	{
		*pS = *s;
		s++;
		i--;
		if (i > 0)
			pS++;
	}
	return (pS - c);
}

// int main(){
// 	int i = 0;
// 	char s[] = "Hey";
// 	printf("%p\n", s);

// 	char *q = ft_strdup(s);
// 	printf("%p\n", q);
// 	printf("%s", q);

// 	return 0;
// }