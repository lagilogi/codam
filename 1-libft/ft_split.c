/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:26:24 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/16 18:13:04 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_free(int i, char **p)
{
	while (i >= 0)
	{
		free(p[i]);
		if (i != 0)
			i--;
	}
}

int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			o++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (o);
}

int	ft_wordlength(const char *s, char c)
{
	int	o;

	o = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		o++;
	}
	return (o);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		l;
	char	**p;

	i = 0;
	p = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		l = ft_wordlength(s, c);
		p[i] = malloc((l + 1) * sizeof(char));
		if (p[i] == NULL)
		{
			ft_free(i, p);
			return (NULL);
		}
		ft_strlcpy(p[i++], s, l + 1);
		s += l;
	}
	p[i] = NULL;
	return (p);
}

// int main (){
// 	int i = 0;
// 	char str[] = "De spin loopt over de boom naar een andere tak";
// 	char del = ' ';

// 	int o = ft_wordcount(str, del);
// 	char **p = ft_split(str, del);
// 	while(i < o)
// 	{
// 		printf("%s\n", p[i]);
// 		i++;
// 	}
// 	return 0;
// }
