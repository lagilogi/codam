/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:45:56 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/26 13:17:01 by wsonepou      ########   odam.nl         */
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

long	ft_gettime(void)
{
	struct timeval	time;
	long			current_ms_time;

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

void	precise_usleep(long end_time)
{
	while (ft_gettime() < end_time - 1)
		usleep(800);
	while (ft_gettime() < end_time)
		;
}

bool	print_status(t_info *info, char *msg, int id)
{
	long	time;

	pthread_mutex_lock(&info->printlock);
	time = ft_gettime() - info->time_to_start;
	if (!check_end(info))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&info->printlock);
	return (false);
}
