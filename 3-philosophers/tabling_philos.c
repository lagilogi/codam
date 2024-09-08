/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tabling_philos.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:16:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/08 16:44:41 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*dinner_simulation(void *data)
{
	t_philo			*philo;

	philo = data;
	while (ft_gettime() < philo->time_to_start)
		continue ;
	printf("Philo %d starting at %ld\n", philo->philo_id, ft_gettime());





	return (NULL);
}

void	tabling_philos(t_info *info, int philo)
{

	// 6. Making threads per philo
	while (philo < info->input->philos)
	{
		if (pthread_create(&info->philos[philo]->thread, NULL, &dinner_simulation, info->philos[philo]))
		{
			while (philo != 0)
			{
				philo--;
				pthread_join(info->philos[philo]->thread, NULL);
			}
			kill_program(info, "failed creating threads", errno);
		}
		philo++;
	}
	philo = 0;
	while (philo < info->input->philos)
	{
		pthread_join(info->philos[philo]->thread, NULL);
		philo++;
	}
	kill_program(info, NULL, 0);
}
