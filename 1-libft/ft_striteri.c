/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 11:02:05 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 15:13:58 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}

// int main(){
// 	char *s = "Hello World!";
// 	printf("%s", functie);

// 	return 0;
// }