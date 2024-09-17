/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 18:33:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/17 18:12:40 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_death(t_info *info, int id)
{
	unsigned long	time_of_death;

	time_of_death = info->philo[id].last_meal + info->tt_die;
	if (ft_gettime() > time_of_death)
	{
		if (ft_gettime() > info->philo[id].time_of_death)
			print_status(info, "died", id + 1);
		pthread_mutex_lock(&info->stoplock);
		info->stop = true;
		pthread_mutex_unlock(&info->stoplock);
	}
}

void	check_full(t_info *info, int id)
{
	if (info->max_eat == -1 || info->philo[id].full == true)
		return ;
	if (info->philo[id].times_eaten >= info->max_eat)
	{
		printf("Philo %d is full\n", id + 1);
		info->philo[id].full = true;
		info->full++;
	}
	if (info->full == info->philos)
	{
		pthread_mutex_lock(&info->stoplock);
		info->stop = true;
		pthread_mutex_unlock(&info->stoplock);
	}
}

void	monitoring(t_info *info)
{
	int	i;

	i = 0;
	while (ft_gettime() < info->time_to_start)
	{
		usleep(100);
		continue ;
	}
	while (info->stop == false)
	{
		while (i < info->philos)
		{
			usleep (2000);
			check_full(info, i);
			check_death(info, i);
			i++;
		}
		i = 0;
	}
}
