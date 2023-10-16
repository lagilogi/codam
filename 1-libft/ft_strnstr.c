/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 11:19:31 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/16 16:02:33 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

char * ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int o;

	i = 0;
	o = 0;
	if (little[0] == '\0')
		return (char *) big;
	while (i < len)
	{
		if (big[i] != little[o])
			i++;
		else
		{
			while (big[i] == little[o] && i < len)
			{
				i++;
				o++;
			}
			if (little[o] == '\0')
				return (char *)(big + (i - o));
			i = i - o;
			o = 0;
			i++;
		}
	}
	return 0;
}

int main(){
	char hay[] = "Needle in ah the aaah Haystack";
	char ndl[] = "aah";
	int len = 21;
	printf("%s\n", ft_strnstr(hay, ndl, len));
	printf("%p\n\n", ft_strnstr(hay, ndl, len));
	printf("%s\n", strnstr(hay, ndl, len));
	printf("%p", strnstr(hay, ndl, len));

	return 0;
}