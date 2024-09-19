/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:45:56 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/19 20:16:41 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(char *num_str)
{
	long	i;
	long	o;

	i = 0;
	o = 0;
	while (num_str[i] == ' ' || (num_str[i] >= '\t' && num_str[i] <= '\r'))
		i++;
	if (num_str[i] == '+')
		i++;
	while (num_str[i] >= '0' && num_str[i] <= '9')
	{
		o = o * 10 + (num_str[i] - '0');
		if (o > INT_MAX)
			return (-1);
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
		if (o > INT_MAX)
			return (-1);
		i++;
	}
	return (o);
}


unsigned long	ft_gettime(void)
{
	struct timeval	time;
	unsigned long	current_ms_time;

	gettimeofday(&time, NULL);
	current_ms_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_ms_time);
}

bool	check_end(t_info *info)
{
	pthread_mutex_lock(&info->stoplock);
	if (info->stop == true)
	{
		pthread_mutex_unlock(&info->stoplock);
		return (true);
	}
	pthread_mutex_unlock(&info->stoplock);
	return (false);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

bool	print_status(t_info *info, char *msg, int id)
{
	unsigned long	time;

	pthread_mutex_lock(&info->printlock);
	time = ft_gettime() - info->time_to_start;
	if (check_end(info))
	{
		pthread_mutex_unlock(&info->printlock);
		return (true);
	}
	printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&info->printlock);
	return (false);
}
