/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 17:49:28 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/10 19:21:01 by wsonepou      ########   odam.nl         */
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
		printf("%s: Too many philos trying to eat (Max. 200)\n", arg);
	else if (i == 5)
		printf("%s: Number bigger than unsigned int\n", arg);	
	exit(EXIT_FAILURE);
}

void	kill_program(t_info *info, char *msg, int exit_code)
{
	int	i;

	i = 0;
	while(info->forks != NULL && info->forks[i] != NULL)
	{
		pthread_mutex_destroy(info->forks[i]);
		free(info->forks[i++]);
	}
	free(info->forks);
	i = 0;
	while(info->philos != NULL && info->philos[i] != NULL)
		free(info->philos[i++]);
	free(info->philos);
	if (msg != NULL)
		printf("%s\n", msg);
	exit(exit_code);
}

void free_failed_philo_array(t_info *info, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		pthread_mutex_destroy(&info->philos[i]->stoplock);
		free(info->philos[i]);
		i++;
	}
	free(info->philos);
	info->philos = NULL;
	kill_program(info, "Failed mallocing info->fork[i]", errno);
}

void free_failed_fork_array(t_info *info, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		pthread_mutex_destroy(info->forks[i]);
		free(info->forks[i]);
		i++;
	}
	free(info->forks);
	info->forks = NULL;
	kill_program(info, "Failed mallocing info->fork[i]", errno);
}
