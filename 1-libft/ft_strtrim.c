/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 11:23:49 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 17:30:21 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

size_t ft_setchecker(char const *set, int c)
{
	size_t	i;

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
	int		i;
	int		k;
	char	*p;

	i = 0;
	k = 0;
	while (ft_setchecker(set, *s1) == 1)
		s1++;
	while(s1[i] != '\0')
		i++;
	while (ft_setchecker(set, s1[i]) == 1 || s1[i] == '\0')
		i--;
	p = malloc((i + 2) * sizeof(char));
	while (k <= i)
	{
		p[k] = s1[k];
		k++;
	}
	p[k] = '\0';
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


// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		i;
// 	int		o;
// 	int		k;
// 	char	*p;

// 	i = 0;
// 	k = 0;
// 	o = ft_strlen(set);
// 	while (ft_setchecker(set, *s1, o) == 1)
// 		s1++;
// 	while(s1[i] != '\0')
// 		i++;
// 	while (ft_setchecker(set, s1[i], o) == 1 || s1[i] == '\0')
// 		i--;
// 	p = malloc((i + 2) * sizeof(char));
// 	while (k <= i)
// 	{
// 		p[k] = s1[k];
// 		k++;
// 	}
// 	p[k] = '\0';
// 	return (p);
// }
