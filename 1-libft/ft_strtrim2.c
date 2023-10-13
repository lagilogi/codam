/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 11:23:49 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/12 15:56:19 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

char    *ft_strtrim(char const *s1, char const *set)
{
    char	*p;
    char	*end;
	size_t 	i;

    while (ft_strrchr(set, *s1))
        s1++;
    end = s1 + strlen(s1);
    while (s1 < end && ft_strrchr(set, *end))
        end--;
	i = end - s1 + 1;
    p = malloc((i + 1) * sizeof(char));
    ft_strlcpy(p, s1, i + 1);
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