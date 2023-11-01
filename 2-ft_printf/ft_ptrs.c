/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ptrs.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 16:55:00 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/01 12:16:03 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lencheck(unsigned long long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_putnbr(unsigned long long n, char *base)
{
	int					i;
	int					o;

	o = ft_lencheck(n);
	if (n >= 16)
		ft_putnbr(n / 16, base);
	n = n % 16;
	i = base[n];
	write(1, &i, 1);
	return (o);
}

int	ft_ptrs(void *n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n == NULL)
		return (ft_putstr("(nil)"));
	else
	{
		ft_putstr("0x");
		return (ft_putnbr((unsigned long long) n, base) + 2);
	}
}
