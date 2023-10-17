/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:57:32 by wsonepou      #+#    #+#                 */
/*   Updated: 2023/10/17 15:12:08 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int c)
{
	if(c >= 65 && c <= 90)
		c += 32;
	return c;
}