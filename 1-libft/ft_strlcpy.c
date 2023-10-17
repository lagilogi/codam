/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:28:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 14:59:22 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

typedef unsigned long size_t;

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (ft_strlen(src));
}

// int main(){
// 	char dest[] = "Hello";
// 	char src[] = "By";
// 	char dest1[] = "Hello";
// 	char src1[] = "By";
// 	printf("%lu\n", ft_strlcpy(dest, src, 6));
// 	printf("%lu\n\n", strlcpy(dest1, src1, 6));
// 	printf("%s\n", dest);
// 	printf("%s", dest1);

// 	return 0;
// }