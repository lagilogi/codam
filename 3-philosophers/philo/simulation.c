/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:16:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/19 20:26:37 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	sleeping(t_philo *philo)
{
	unsigned long	current_time;
	unsigned long	wake_up_time;

	current_time = ft_gettime();
	wake_up_time = current_time + philo->info->tt_sleep;
	if (print_status(philo->info, "is sleeping", philo->id))
		return (true);
	while (ft_gettime() < wake_up_time)
		usleep(200);
	// usleep((wake_up_time - ft_gettime()) * 1000);
	return (false);
}




static bool	taking_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		if (print_status(philo->info, "has taken a fork", philo->id) || philo->info->philos == 1)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
			while (philo->info->philos == 1 && ft_gettime() < philo->death_time)
				usleep(1000);
			return (true);
		}
	}
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	if (philo->id % 2 == 0)
		if (print_status(philo->info, "has taken a fork", philo->id))
		{
			pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
			return (true);
		}
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	return (false);
}

static bool	eating(t_philo *philo)
{
	unsigned long	done_eating_time;

	if (taking_forks(philo))
		return (true);
	pthread_mutex_lock(&philo->eatlock);
	philo->last_meal = ft_gettime();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eatlock);
	if (print_status(philo->info, "is eating", philo->id))
	{
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		return (true);
	}
	done_eating_time = philo->last_meal + philo->info->tt_eat;
	while (ft_gettime() < done_eating_time)
		usleep(200);
	// usleep((done_eating_time - ft_gettime()) * 1000);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	return (false);
}





static void	*simul(void *data)
{
	t_philo	*philo;

	philo = data;
	while (ft_gettime() < philo->info->time_to_start)
		usleep(500);
	if (philo->id % 2 == 0)
	{
		while (ft_gettime() < philo->info->time_to_start + 30)
			usleep(100);
	}
	while (1)
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (print_status(philo->info, "is thinking", philo->id))
			break ;
	}
	return (NULL);
}

void	starting_simulation(t_info *info, int i)
{
	while (i < info->philos)
	{
		if (pthread_create(&info->philo[i].th, NULL, &simul, &info->philo[i]))
		{
			while (i != 0)
			{
				i--;
				pthread_join(info->philo[i].th, NULL);
			}
			kill_program(info, "failed creating threads", errno);
		}
		i++;
	}
	monitoring(info);
	i = 0;
	while (i < info->philos)
	{
		pthread_join(info->philo[i].th, NULL);
		i++;
	}
	pthread_mutex_destroy(&info->stoplock);
	pthread_mutex_destroy(&info->printlock);
}
