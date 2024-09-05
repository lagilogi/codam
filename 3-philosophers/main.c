/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/05 18:41:25 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void setting_info(t_info *info, char **argv)
{
    info->input->philos = ft_atoi(argv[1]);
    info->input->tt_die = ft_atoi(argv[2]);
    info->input->tt_eat = ft_atoi(argv[3]);
    info->input->tt_sleep = ft_atoi(argv[4]);
    info->input->max_eat = ft_atoi(argv[5]);
	info->forks = malloc(info->input->philos * sizeof(int));
}

void	creating_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->input->philos)
	{
		
		i++;
	}
}

int main(int argc, char **argv)
{
    t_info  info;
	t_input	input;

    if (argc != 6)
        return (1);
	info.input = &input;
    setting_info(&info, argv);
	creating_philos(&info);


    return (0);
}



// Usable functions:
// pthread_create
// pthread_detach
// pthread_join
// pthread_mutex_init
// pthread_mutex_destroy
// pthread_mutex_lock
// pthread_mutex_unlock
// usleep
// gettimeofday
// memset
// printf
// malloc
// free
// write
