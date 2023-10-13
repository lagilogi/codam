/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 15:56:23 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/13 10:39:14 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdint.h>

char *ft_substr(char const *s, unsigned int start, size_t len){
	char	*sub;
	size_t	i;

	i = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	while(len > 0)
		{
			sub[i] = s[start];
			i++;
			start++;
			len--;
		}
	sub[i] = '\0';

	return sub;
}

int main(){
    char s[] = "Hallo";
    size_t i = 1;
    size_t o = 3;
    
    char *q = ft_substr(s, i, o);
    printf("%p\n", q);
    printf("%s", q);

    return 0;
}