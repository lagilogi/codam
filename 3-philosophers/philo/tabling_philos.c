/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tabling_philos.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:16:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/10 19:12:53 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	taking_fork(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%lu %d has taken a fork\n", ft_gettime(), philo->id);
	}
	
	pthread_mutex_lock(philo->right_fork);
	if (philo->id % 2 == 0)
		printf("%lu %d has taken a fork\n", ft_gettime(), philo->id);

	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_fork);
}

void	eating(t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	done_eating_time;

	taking_fork(philo);
	if (philo->stop == true)
		return ;
	current_time = ft_gettime();
	done_eating_time = current_time + philo->input->tt_eat;
	philo->time_of_death = current_time + philo->input->tt_die;
	printf("%lu %d is eating\n", current_time, philo->id);
	while (ft_gettime() < done_eating_time)
	{
		// usleep(1000);
		current_time = ft_gettime();
		if (current_time > philo->time_of_death)
		{
			pthread_mutex_lock(&philo->stoplock);
			philo->stop = true;
			pthread_mutex_unlock(&philo->stoplock);
			break ;
		}
	}
	philo->times_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}




void	sleeping(t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	wake_up_time;

	current_time = ft_gettime();
	wake_up_time = current_time + philo->input->tt_sleep;
	printf("%lu %d is sleeping\n", current_time, philo->id);
	while (current_time < wake_up_time)
	{
		// usleep(1000);
		current_time = ft_gettime();
		if (current_time > philo->time_of_death)
		{
			pthread_mutex_lock(&philo->stoplock);
			philo->stop = true;
			pthread_mutex_unlock(&philo->stoplock);
			break ;
		}
	}
}





static void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = data;
	while (ft_gettime() < philo->time_to_start)
		continue ;
	if (philo->id % 2 == 1)
	{
		printf("%lu %d is thinking\n", ft_gettime(), philo->id);
		while (ft_gettime() < philo->time_to_start + 10)
			continue ;
	}
	while (philo->stop == false)
	{
		eating(philo);
		if (philo->stop == true)
			break ;
		sleeping(philo);
		if (philo->stop == true)
			break ;
		printf("%lu %d is thinking\n", ft_gettime(), philo->id);
	}
	pthread_mutex_destroy(&philo->stoplock);
	return (NULL);
}

void	tabling_philos(t_info *info, int i)
{
	while (i < info->input->philos)
	{
		if (pthread_create(&info->philos[i]->thread, NULL, &dinner_simulation, info->philos[i]))
		{
			while (i != 0)
			{
				i--;
				pthread_join(info->philos[i]->thread, NULL);
			}
			kill_program(info, "failed creating threads", errno);
		}
		i++;
	}
	monitoring(info, 0);
	i = 0;
	while (i < info->input->philos)
	{
		pthread_join(info->philos[i]->thread, NULL);
		i++;
	}
}
