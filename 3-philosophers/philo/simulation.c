/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:16:20 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/20 09:44:55 by ubuntu        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static bool	sleeping(t_philo *philo)
// {
// 	long	current_time;
// 	long	wake_up_time;

// 	current_time = ft_gettime();
// 	wake_up_time = current_time + philo->info->tt_sleep;
// 	if (print_status(philo->info, "is sleeping", philo->id))
// 		return (true);
// 	precise_usleep(wake_up_time);
// 	return (false);
// }


// // static bool	taking_forks(t_philo *philo)
// // {
// // 	if (philo->id % 2 == 1)
// // 	{
// // 		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
// // 		if (print_status(philo->info, "has taken a fork", philo->id) || philo->info->philos == 1)
// // 		{
// // 			pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
// // 			while (philo->info->philos == 1 && ft_gettime() < philo->death_time)
// // 				usleep(1000);
// // 			return (true);
// // 		}
// // 	}
// // 	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
// // 	if (philo->id % 2 == 0)
// // 		if (print_status(philo->info, "has taken a fork", philo->id))
// // 		{
// // 			pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
// // 			return (true);
// // 		}
// // 	if (philo->id % 2 == 0)
// // 		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
// // 	return (false);
// // }

// static bool	odd_forks(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
// 	if (print_status(philo->info, "has taken a fork", philo->id) || philo->info->philos == 1)
// 	{
// 		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
// 		while (philo->info->philos == 1 && ft_gettime() < philo->death_time)
// 			usleep(1000);
// 		return (true);
// 	}
// 	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
// 	if (print_status(philo->info, "has taken a fork", philo->id))
// 	{
// 		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
// 		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
// 		return (true);
// 	}
// 	return (false);
// }

// static bool	even_forks(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
// 	if (print_status(philo->info, "has taken a fork", philo->id))
// 	{
// 		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
// 		return (true);
// 	}
// 	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
// 	if (print_status(philo->info, "has taken a fork", philo->id))
// 	{
// 		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
// 		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
// 		return (true);
// 	}
// 	return (false);
// }

// static bool	eating(t_philo *philo)
// {
// 	long	done_eating_time;

// 	if (philo->id % 2 == 1 && odd_forks(philo))
// 		return (true);
// 	else if (philo->id % 2 == 0 && even_forks(philo))
// 		return (true);
// 	pthread_mutex_lock(&philo->eatlock);
// 	philo->last_meal = ft_gettime();
// 	philo->times_eaten++;
// 	pthread_mutex_unlock(&philo->eatlock);
// 	if (print_status(philo->info, "is eating", philo->id))
// 	{
// 		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
// 		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
// 		return (true);
// 	}
// 	done_eating_time = philo->last_meal + philo->info->tt_eat;
// 	precise_usleep(done_eating_time);
// 	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
// 	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
// 	return (false);
// }

// void	*simul(void *data)
// {
// 	t_philo	*philo;

// 	philo = data;
// 	while (ft_gettime() < philo->info->time_to_start)
// 		usleep(500);
// 	if (philo->id % 2 == 0)
// 		precise_usleep(philo->info->time_to_start + (philo->info->tt_eat / 2));
// 	while (!check_end(philo->info))
// 	{
// 		if (eating(philo))
// 			break ;
// 		if (sleeping(philo))
// 			break ;
// 		if (print_status(philo->info, "is thinking", philo->id))
// 			break ;
// 		if (philo->info->odd == true)
// 			precise_usleep((philo->info->tt_die / 2) * 1000);
// 	}
// 	return (NULL);
// }


static void	sleeping(t_philo *philo)
{
	long	current_time;

	current_time = ft_gettime();
	print_status(philo->info, "is sleeping", philo->id);
	precise_usleep(current_time + philo->info->tt_sleep);
}

static void	eating(t_philo *philo)
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
	pthread_mutex_lock(&philo->eatlock);
	philo->last_meal = ft_gettime();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eatlock);
	print_status(philo->info, "is eating", philo->id);
	precise_usleep(philo->last_meal + philo->info->tt_eat);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
}

void	*simul(void *data)
{
	t_philo	*philo;

	philo = data;
	while (ft_gettime() < philo->info->time_to_start)
		usleep(500);
	if (philo->id % 2 == 0)
		precise_usleep(philo->info->time_to_start + (philo->info->tt_eat / 2));
	while (!check_end(philo->info))
	{
		eating(philo);
		sleeping(philo);
		print_status(philo->info, "is thinking", philo->id);
		if (philo->info->odd == true)
			precise_usleep((philo->info->tt_die / 2) * 1000);
	}
	return (NULL);
}

void	*solo_simul(void *data)
{
	t_philo	*philo;

	philo = data;
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	if (print_status(philo->info, "has taken a fork", philo->id) || philo->info->philos == 1)
	{
		while (philo->info->philos == 1 && ft_gettime() < philo->death_time)
			usleep(1000);
	}
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	return (NULL);
}
