/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:34:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/16 14:07:22 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	unsigned long	c;

	c = 0;
	if (s == NULL)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
}
