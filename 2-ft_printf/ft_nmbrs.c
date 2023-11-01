/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nmbrs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 16:55:00 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/31 18:07:20 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lencheck(long n, int count)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (count == 10)
	{
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	else
	{
		while (n > 0)
		{
			n /= 16;
			len++;
		}
	}
	return (len);
}

static int	ft_putnbr(long n, char *base)
{
	int		i;
	int		o;
	int		count;

	count = 0;
	while (base[count])
		count++;
	o = ft_lencheck(n, count);
	if (n >= count)
		ft_putnbr(n / count, base);
	n = n % count;
	i = base[n];
	write(1, &i, 1);
	return (o);
}

int	ft_nmbrs(long n, char *base)
{
	int	i;
	int	o;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		i++;
		n = n * -1;
	}
	o = ft_putnbr(n, base);
	return (o + i);
}
