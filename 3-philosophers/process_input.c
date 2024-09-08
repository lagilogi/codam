/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 14:35:37 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/08 16:48:51 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void parsing_input(t_info *info, char **argv)
{
    info->input->philos = ft_atoi(argv[1]);
	if (info->input->philos == 0)
		exit (0);
	else if (info->input->philos > 200)
		input_error(4, argv[1]);
    info->input->tt_die = atol_unsigned(argv[2]);
	if (info->input->tt_die > INT_MAX)
		input_error(5, argv[2]);
    info->input->tt_eat = atol_unsigned(argv[3]);
	if (info->input->tt_eat > INT_MAX)
		input_error(5, argv[3]);
    info->input->tt_sleep = atol_unsigned(argv[4]);
	if (info->input->tt_sleep > INT_MAX)
		input_error(5, argv[4]);
	if (argv[5] != NULL)
	{
    	info->input->max_eat = atol_unsigned(argv[5]);
		if (info->input->max_eat > INT_MAX)
			input_error(5, argv[5]);
	}
	else
		info->input->max_eat = 0;
	info->forks = NULL;
	info->philos = NULL;
}

static void	input_check(int argc, char **argv)
{
	int	i;
	int	o;

	i = 1;
	o = 0;
	while (i < argc)
	{
		while (argv[i][o] == ' ' || (argv[i][o] >= 9 && argv[i][o] <= 13))
			o++;
		if (argv[i][0] == '-')
			input_error(2, argv[i]);
		if (argv[i][o] == '+')
			o++;
		while (argv[i][o])
		{
			if (argv[i][o] < '0' || argv[i][o] > '9')
				input_error(3, argv[i]);
			o++;
		}
		o = 0;
		i++;
	}
}

// Creating the fork array
static void	getting_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc((info->input->philos + 1) * sizeof(t_fork *)); // Malloc-ing fork array
	if (info->forks == NULL)
		kill_program(info, "Failed to malloc info->forks", errno);
	info->forks[info->input->philos] = NULL; // setting last pointer to NULL
	while (i < info->input->philos)
	{
		info->forks[i] = malloc(sizeof(t_fork));
		if (info->forks[i] == NULL)
			free_failed_fork_array(info, i);
		info->forks[i]->fork_id = i;
		pthread_mutex_init(&info->forks[i]->fork_lock, NULL);
		i++;
	}
}

static void	summon_philos(t_info *info)
{
	int	i;

	i = 0;
	info->philos = malloc((info->input->philos + 1) * sizeof(t_philo *));
	if (info->philos == NULL)
		kill_program(info, "Failed mallocing info->philos", errno);
	info->philos[info->input->philos] = NULL;
	while (i < info->input->philos)
	{
		info->philos[i] = malloc(sizeof(t_philo));
		if (info->philos[i] == NULL)
			free_failed_philo_array(info, i);
		info->philos[i]->philo_id = i + 1;
		info->philos[i]->tt_die = info->input->tt_die;
		info->philos[i]->tt_eat = info->input->tt_eat;
		info->philos[i]->tt_sleep = info->input->tt_sleep;
		info->philos[i]->max_eat = info->input->max_eat;
		info->philos[i]->left_fork = info->forks[i];
		info->philos[i]->time_to_start = ft_gettime() + 2000; // To set start time for all philos to start
		if (i + 1 != info->input->philos)
			info->philos[i]->right_fork = info->forks[i + 1];
		else
			info->philos[i]->right_fork = info->forks[0];
		i++;
	}
}

void	process_input(t_info *info, int argc, char **argv)
{
	input_check(argc, argv);
	parsing_input(info, argv);
	getting_forks(info);
	summon_philos(info);
}