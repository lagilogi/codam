/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/19 19:24:58 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	parsing_input(t_info *info, char **argv)
{
	info->philos = ft_atol(argv[1]);
	if (info->philos == 0 || info->philos > 200)
		input_error(4, argv[1]);
	info->tt_die = atol_unsigned(argv[2]);
	info->tt_eat = atol_unsigned(argv[3]);
	info->tt_sleep = atol_unsigned(argv[4]);
	if (info->tt_die > INT_MAX || info->tt_eat > INT_MAX
		|| info->tt_sleep > INT_MAX)
		input_error(5, NULL);
	if (argv[5] != NULL)
	{
		info->max_eat = ft_atol(argv[5]);
		if (info->max_eat > INT_MAX || info->max_eat == -1)
			input_error(5, NULL);
	}
	if (argv[5] == NULL || info->max_eat == 0)
		info->max_eat = -1;
	info->full = 0;
	info->stop = false;
	info->forks = NULL;
	info->philo = NULL;
	if (pthread_mutex_init(&info->printlock, NULL))
		kill_program(info, "Failed creating stop- or printlock mutex", errno);
	if (pthread_mutex_init(&info->stoplock, NULL))
		kill_program(info, "Failed creating stop- or stoplock mutex", errno);
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

static void	getting_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc((info->philos) * sizeof(pthread_mutex_t));
	if (info->forks == NULL)
		kill_program(info, "Failed to malloc info->forks", errno);
	while (i < info->philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			destroy_mutexes(info, i - 1, 0);
		i++;
	}
}

static void	getting_philos(t_info *info, unsigned long tt_start)
{
	int	i;

	i = 0;
	info->philo = malloc((info->philos) * sizeof(t_philo));
	if (info->philo == NULL)
		kill_program(info, "Failed mallocing info->philos", errno);
	while (i < info->philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->philos;
		info->philo[i].info = info;
		info->philo[i].last_meal = tt_start;
		info->philo[i].times_eaten = 0;
		if (pthread_mutex_init(&info->philo[i].eatlock, NULL))
			destroy_mutexes(info, i - 1, 1);
		info->philo[i].full = false;
		i++;
	}
	info->time_to_start = tt_start;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		input_error(1, NULL);
	input_check(argc, argv);
	parsing_input(&info, argv);
	getting_forks(&info);
	getting_philos(&info, ft_gettime() + 1000);
	starting_simulation(&info, 0);
	kill_program(&info, NULL, 0);
	return (0);
}

// Order of work;

// SETUP							--CHECK--
// 1. Check input 					-CHECK-
//
// 2. Parse input					-CHECK-
//
// 2. Create fork struct array		-CHECK-
//
// 3. Set fork array data			-CHECK-
//
// 4. Create philo struct array		-CHECK-
//
// 5. Set philo struct array data	-CHECK-

// ROUTINE
// 6. Make threads per philo										-CHECK-
//
// 7. Make philos able to 'pick up' a fork							-CHECK-
//
// 8. Make sure philos start at same time by getting time of day	-CHECK-
// 
// 9. print timestamps												-CHECK-
//
// 10. Make philo's check how long they are busy with an activity	-CHECK-
// 
// 11. Set initial time of death for philos							-CHECK-
// 
// 12. Make monitor able to check time of death of philo			-CHECK-
// 
// 13. Make routine end on moment that all philos have eaten enough	
// 	   with optional argument
//
// 14. figure out how to deal with uneven amount of philos			
// 
// 15. Get 1 philo input to end instead of stuck on waiting for last 
//
// Print functie & print lock
// philo struct -> info struct
// Philo stop & stoplock uit philo struct and info->stop gebruiken
// 
