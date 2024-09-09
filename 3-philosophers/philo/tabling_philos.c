/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tabling_philos.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:16:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/09 16:37:16 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ending_dinner(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	done_eating_time;

	current_time = ft_gettime();
	done_eating_time = current_time + philo->tt_eat;
	printf("%lu %d is eating\n", current_time, philo->id);
	while (ft_gettime() < done_eating_time)
		continue ;
}




void	sleeping(t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	wake_up_time;

	current_time = ft_gettime();
	wake_up_time = current_time + philo->tt_sleep;
	printf("%lu %d is sleeping\n", current_time, philo->id);
	while (ft_gettime() < wake_up_time)
		continue ;
}





static void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = data;
	while (ft_gettime() < philo->time_to_start)
		continue ;
	// printf("Philo %d starting at %ld\n", philo->id, ft_gettime()); // start time test
	// while (philo->stop == false)
	// {
	// 	eating(philo);
	// 	sleeping(philo);
	// }
	for (int i = 0; i < 5; i++)
	{
		eating(philo);
		sleeping(philo);
	}

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
}
