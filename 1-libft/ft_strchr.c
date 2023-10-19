/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 12:58:14 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/19 14:19:51 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = c % 256;
	if (c < 0 || c > 127)
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

// int main(){
// 	char hay[] = "tripouille";
// 	int ndl = 5000;
// 	printf("%p\n", ft_strchr(hay, ndl));
// 	printf("%p\n\n", strchr(hay, ndl));
// 	printf("%s\n", ft_strchr(hay, ndl));
// 	printf("%s", strchr(hay, ndl));

// 	return 0;
// }