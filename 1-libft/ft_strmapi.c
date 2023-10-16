/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 17:43:03 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/16 18:40:00 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char functie(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c - 1);
	else
		return (c + 1);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*p;

	i = 0;
	p = malloc((ft_strlen(s) + 1) * sizeof(char));
	while(p[i] != '\0')
	{
		p[i] = f(i, p[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

int main(){
	char *result = ft_strmapi("Hello", functie);
	printf("%s", result);

	return 0;
}
