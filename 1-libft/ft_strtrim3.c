/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 11:23:49 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/12 18:03:34 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);
size_t ft_strlcpy(char *dest, const char *src, size_t size);

int	ft_setchecker(char const *set, int c, size_t n)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == (unsigned char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		o;
	char	*p;

	o = ft_strlen(set);
	while (ft_setchecker(set, *s1, o) == 1)
		s1++;
	const char *s2 = s1 + strlen(s1) + 1;
	while(s1 < s2 && ft_setchecker(set, *s2, o))
		s2--;
	p = malloc((str + ) * sizeof(char));
	ft_strlcpy(p, s1, i);
	return (p);
}

int main(){
	char s1[] = "osooHelloso";
	char set[] = "os";

	char* q = ft_strtrim(s1, set);
	printf("%s\n", q);
	printf("%p", q);

	return 0;
}