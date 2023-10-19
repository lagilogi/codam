/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 13:55:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/19 14:22:29 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c = c % 256;
	if (c < 0 || c > 127)
		return ((char *)s);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

// int main(){
// 	char hay[] = "haystacks";
// 	char ndl = 'h';
// 	printf("%p\n", strrchr(hay, ndl));
// 	printf("%p\n", ft_strrchr(hay, ndl));
// 	return 0;
// }