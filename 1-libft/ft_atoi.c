/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 13:32:29 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/10 16:18:27 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *nptr){
	int	i;
	int min;
	int	o;
	const char *s = nptr;

	i = 0;
	min = 0;
	o = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if(s[i] == '-')
			min = 1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		o = o * 10 + (s[i] - 48);
		i++;
	}
	if (min == 1)
		return o * -1;
	return o;
}

int main(){
	char str[] = "     -----+--+21474832423";
	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	
	return 0;
}