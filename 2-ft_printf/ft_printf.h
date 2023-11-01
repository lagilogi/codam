/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 15:41:27 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/11/01 12:13:38 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_nmbrs(long n, char *base);
int	ft_ptrs(void *n);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif