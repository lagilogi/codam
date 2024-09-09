/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:45:56 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/08 16:26:22 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *num_str)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (num_str[i] == ' ' || (num_str[i] >= '\t' && num_str[i] <= '\r'))
		i++;
	if (num_str[i] == '+')
		i++;
	while (num_str[i] >= '0' && num_str[i] <= '9')
	{
		o = o * 10 + (num_str[i] - '0');
		i++;
	}
	return (o);
}

unsigned long	atol_unsigned(char *num_str)
{
	int				i;
	unsigned long	o;

	i = 0;
	o = 0;
	while (num_str[i] == ' ' || (num_str[i] >= '\t' && num_str[i] <= '\r'))
		i++;
	if (num_str[i] == '-' || num_str[i] == '+')
		i++;
	while (num_str[i] >= '0' && num_str[i] <= '9')
	{
		o = o * 10 + (num_str[i] - '0');
		i++;
	}
	return (o);
}

unsigned long	ft_gettime()
{
	struct timeval	time;
	unsigned long	current_ms_time;

	gettimeofday(&time, NULL);
	current_ms_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_ms_time);
}