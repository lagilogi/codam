/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/26 12:30:28 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	starting_solo_simulation(t_info *info)
{
	if (pthread_create(&info->philo[0].th, NULL, &solo_simul, &info->philo[0]))
	{
		pthread_mutex_destroy(&info->stoplock);
		pthread_mutex_destroy(&info->printlock);
		return (clean_up(info, "failed creating threads", errno));
	}
	monitoring(info);
	pthread_join(info->philo[0].th, NULL);
	pthread_mutex_destroy(&info->stoplock);
	pthread_mutex_destroy(&info->printlock);
	return (clean_up(info, NULL, 0));
}

static int	starting_full_simulation(t_info *info, int i)
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
			pthread_mutex_destroy(&info->stoplock);
			pthread_mutex_destroy(&info->printlock);
			return (clean_up(info, "failed creating threads", errno));
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
	return (clean_up(info, NULL, 0));
}

static int	input_check(int argc, char **argv)
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
			return (input_error(2, argv[i]));
		if (argv[i][o] == '+')
			o++;
		while (argv[i][o])
		{
			if (argv[i][o] < '0' || argv[i][o] > '9')
				return (input_error(3, argv[i]));
			o++;
		}
		o = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		if (input_error(1, NULL) == 1)
			return (1);
	if (input_check(argc, argv))
		return (1);
	if (init_simulation(&info, argv))
		return (errno);
	if (info.philos == 1)
	{
		if (starting_solo_simulation(&info))
			return (errno);
	}
	else
		if (starting_full_simulation(&info, 0))
			return (errno);
	return (0);
}
