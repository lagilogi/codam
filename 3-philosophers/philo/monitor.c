/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 18:33:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/10 19:30:04 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	stopping_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->input->philos)
	{
		pthread_mutex_lock(&info->philos[i]->stoplock);
		info->philos[i]->stop = true;
		pthread_mutex_unlock(&info->philos[i]->stoplock);
		i++;
	}	
}

void	monitoring(t_info *info, int i)
{
	while (ft_gettime() < info->philos[0]->time_to_start)
		continue ;
	while (info->stop == false)
	{
		while (i < info->input->philos)
		{
			if (info->input->max_eat != -1 && info->philos[i]->full == false && info->philos[i]->times_eaten >= info->input->max_eat)
			{
				info->philos[i]->full = true;
				printf("Philo %d is full\n", i);
				info->full++;
			}
			if (info->philos[i]->stop == true || info->full == info->input->max_eat)
			{
				if (info->philos[i]->stop == true)
					printf("%lu %d died\n", ft_gettime(), i);
				info->stop = true;
				break ;
			}
			i++;
		}
		if (info->stop == true)
			break ;
		i = 0;
	}
	stopping_philos(info);
}
