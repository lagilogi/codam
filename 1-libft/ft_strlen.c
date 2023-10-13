/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:34:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/08 15:03:32 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
typedef unsigned long size_t;

size_t ft_strlen(const char* s){
	unsigned long c;

	c = 0;
	while (s[c] != '\0')
		c++;

	return c;
}
