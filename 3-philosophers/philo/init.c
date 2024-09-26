/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/26 11:57:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/26 15:11:24 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	parsing_input(t_info *info, char **argv)
{
	info->philos = ft_atol(argv[1]);
	if (info->philos == 0 || info->philos > 200)
		return (input_error(4, argv[1]));
	info->tt_die = ft_atol(argv[2]);
	info->tt_eat = ft_atol(argv[3]);
	info->tt_sleep = ft_atol(argv[4]);
	if (info->tt_die == -1 || info->tt_eat == -1
		|| info->tt_sleep == -1)
		return (input_error(5, NULL));
	if (argv[5] != NULL)
	{
		info->max_eat = ft_atol(argv[5]);
		if (info->max_eat == -1)
			input_error(5, NULL);
	}
	if (argv[5] == NULL || info->max_eat == 0)
		info->max_eat = -1;
	return (0);
}

static int	getting_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc((info->philos) * sizeof(pthread_mutex_t));
	if (info->forks == NULL)
		return (clean_up(info, "Failed to malloc forks", errno));
	while (i < info->philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (destroy_mutexes(info, i - 1, 0));
		i++;
	}
	return (0);
}

static int	getting_philos(t_info *info, long tt_start)
{
	int	i;

	i = 0;
	info->philo = malloc((info->philos) * sizeof(t_philo));
	if (info->philo == NULL)
		return (clean_up(info, "Failed mallocing philos", errno));
	while (i < info->philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->philos;
		info->philo[i].info = info;
		info->philo[i].last_meal = tt_start;
		info->philo[i].times_eaten = 0;
		if (pthread_mutex_init(&info->philo[i].eatlock, NULL))
			return (destroy_mutexes(info, i - 1, 1));
		info->philo[i].full = false;
		i++;
	}
	info->time_to_start = tt_start;
	if (info->philos % 2 == 1)
		info->odd = true;
	else
		info->odd = false;
	return (0);
}

int	init_simulation(t_info *info, char **argv)
{
	if (parsing_input(info, argv))
		return (1);
	info->full = 0;
	info->stop = false;
	info->forks = NULL;
	info->philo = NULL;
	if (pthread_mutex_init(&info->printlock, NULL))
		return (clean_up(info, "Failed creating printlock mutex", errno));
	if (pthread_mutex_init(&info->stoplock, NULL))
		return (clean_up(info, "Failed creating stoplock mutex", errno));
	if (getting_forks(info))
		return (errno);
	if (getting_philos(info, ft_gettime() + 1000))
		return (errno);
	return (0);
}
