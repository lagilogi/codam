/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 17:49:28 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/17 20:22:07 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	input_error(int i, char *arg)
{
	if (i == 1)
	{
		printf("Incorrect amount of arguments.\n-> [philos] [time to die] ");
		printf("[time to eat] [time to sleep] ([max_eat])\n");
	}
	else if (i == 2)
		printf("%s: Cannot be negative\n", arg);
	else if (i == 3)
		printf("%s: Not a number\n", arg);
	else if (i == 4)
		printf("%s: Incorrect amount of philos (Min. 1 - Max. 200)\n", arg);
	else if (i == 5)
		printf("Number too big\n");
	exit(EXIT_FAILURE);
}

void	kill_program(t_info *info, char *msg, int exit_code)
{
	int	i;

	i = 0;
	while (info->forks != NULL && i < info->philos)
		pthread_mutex_destroy(&info->forks[i++]);
	i = 0;
	while (info->philo != NULL && i < info->philos)
		pthread_mutex_destroy(&info->philo[i++].eatlock);
	if (info->forks != NULL)
		free(info->forks);
	if (info->philo != NULL)
		free(info->philo);
	if (msg != NULL)
		printf("%s\n", msg);
	exit(exit_code);
}

void	destroy_mutexes(t_info *info, int i, int x)
{
	if (x == 0)
	{
		while (i >= 0)
			pthread_mutex_destroy(&info->forks[i]);
		free(info->forks);
		info->forks = NULL;
	}
	else
	{
		while (i >= 0)
			pthread_mutex_destroy(&info->philo[i++].eatlock);
		free(info->philo);
		info->philo = NULL;
	}
	kill_program(info, "Failed to initialize mutex", errno);
}
