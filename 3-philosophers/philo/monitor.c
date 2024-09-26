/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 18:33:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/26 14:55:58 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_death(t_info *info, int id)
{
	long	time_of_death;

	pthread_mutex_lock(&info->philo[id].eatlock);
	time_of_death = info->philo[id].last_meal + info->tt_die;
	pthread_mutex_unlock(&info->philo[id].eatlock);
	if (ft_gettime() > time_of_death)
	{
		pthread_mutex_lock(&info->printlock);
		pthread_mutex_lock(&info->stoplock);
		printf("%lu %d died\n", ft_gettime() - info->time_to_start, id + 1);
		info->stop = true;
		pthread_mutex_unlock(&info->stoplock);
		pthread_mutex_unlock(&info->printlock);
		return (true);
	}
	return (false);
}

bool	check_full(t_info *info, int id)
{
	if (info->max_eat == -1 || info->philo[id].full == true)
		return (false);
	pthread_mutex_lock(&info->philo[id].eatlock);
	if (info->philo[id].times_eaten >= info->max_eat)
	{
		info->philo[id].full = true;
		info->full++;
	}
	if (info->full == info->philos)
	{
		pthread_mutex_lock(&info->stoplock);
		info->stop = true;
		pthread_mutex_unlock(&info->stoplock);
		pthread_mutex_unlock(&info->philo[id].eatlock);
		return (true);
	}
	pthread_mutex_unlock(&info->philo[id].eatlock);
	return (false);
}

void	monitoring(t_info *info)
{
	int	i;

	i = 0;
	usleep(50000);
	while (info->stop == false)
	{
		usleep (1000);
		while (i < info->philos)
		{
			if (check_death(info, i))
				break ;
			if (check_full(info, i))
				break ;
			i++;
		}
		i = 0;
	}
}
