/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 18:10:06 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 16:54:19 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while(i != n)
	{
		if (s1[i] != s2[i])
			return (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return 0;
}

// int main(){
// 	char s1[] = "abcdeesdasdasd";
// 	char s2[] = "abcdees";
// 	printf("%d\n", ft_strncmp(s1, s2, 10));
// 	printf("%d", strncmp(s1, s2, 10));

// 	return 0;
// }