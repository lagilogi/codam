/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:16:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/26 15:08:55 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	sleeping(t_philo *philo)
{
	long	current_time;

	current_time = ft_gettime();
	print_status(philo->info, "is sleeping", philo->id);
	precise_usleep(current_time + philo->info->tt_sleep);
}

static void	grab_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_status(philo->info, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_status(philo->info, "has taken a fork", philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		print_status(philo->info, "has taken a fork", philo->id);
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		print_status(philo->info, "has taken a fork", philo->id);
	}
}

static void	eating(t_philo *philo)
{
	grab_forks(philo);
	pthread_mutex_lock(&philo->eatlock);
	philo->last_meal = ft_gettime();
	pthread_mutex_unlock(&philo->eatlock);
	print_status(philo->info, "is eating", philo->id);
	precise_usleep(philo->last_meal + philo->info->tt_eat);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->eatlock);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eatlock);
}

void	*simul(void *data)
{
	t_philo	*philo;

	philo = data;
	while (ft_gettime() < philo->info->time_to_start)
		usleep(500);
	if (philo->id % 2 == 0
		|| (philo->id % 2 == 1 && philo->id == philo->info->philos))
	{
		print_status(philo->info, "is thinking", philo->id);
		precise_usleep(philo->info->time_to_start + (philo->info->tt_eat / 2));
	}
	while (!check_end(philo->info))
	{
		eating(philo);
		sleeping(philo);
		print_status(philo->info, "is thinking", philo->id);
		if (philo->info->odd == true)
			if (philo->info->tt_eat >= (philo->info->tt_sleep / 1.1))
				usleep((philo->info->tt_eat) * 1000);
	}
	return (NULL);
}

void	*solo_simul(void *data)
{
	t_philo	*philo;
	long	time_of_death;

	philo = data;
	time_of_death = philo->last_meal + philo->info->tt_die;
	while (ft_gettime() < philo->info->time_to_start)
		usleep(500);
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	print_status(philo->info, "has taken a fork", philo->id);
	while (ft_gettime() < time_of_death)
		usleep(1000);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	return (NULL);
}
