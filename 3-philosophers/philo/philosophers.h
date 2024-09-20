/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/20 09:20:47 by ubuntu        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_info;

// Struct that every philo has
typedef struct s_philo
{
	pthread_t		th;
	struct s_info	*info;
	int				id;
	int				left_fork;
	int				right_fork;
	long			death_time;
	long			last_meal;
	long			times_eaten;
	bool			full;
	pthread_mutex_t	eatlock;
}	t_philo;

// Main struct
typedef struct s_info
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	long			philos;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	long			max_eat;
	long			full;
	long			time_to_start;
	bool			stop;
	pthread_mutex_t	stoplock;
	pthread_mutex_t	printlock;
	bool			odd;
}	t_info;

// 1. Initalization
int		init_simulation(t_info *info, char **argv);

// 2. Running simulation
void	*solo_simul(void *data);
void	*simul(void *data);
void	monitoring(t_info *info);
bool	check_end(t_info *info);

// 3. Ending and error handling
int		clean_up(t_info *info, char *msg, int exit_code);
int		input_error(int i, char *arg);
int		destroy_mutexes(t_info *info, int i, int x);

// 4. Utils
long	ft_atol(char *num_str);
long	ft_gettime(void);
void	precise_usleep(long duration);
bool	print_status(t_info *info, char *msg, int id);

#endif
