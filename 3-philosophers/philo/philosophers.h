/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/17 18:12:59 by wsonepou      ########   odam.nl         */
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
	unsigned long	time_of_death;
	unsigned long	last_meal;
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
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	long			max_eat;
	unsigned long	time_to_start;
	long			full;
	bool			stop;
	pthread_mutex_t	stoplock;
	pthread_mutex_t	printlock;
}	t_info;

// 1. Running simulation
void			starting_simulation(t_info *info, int i);
void			monitoring(t_info *info);

// 2. Ending and error handling
void			kill_program(t_info *info, char *msg, int exit_code);
void			input_error(int i, char *arg);
void			destroy_mutexes(t_info *info, int i, int x);

// 3. Utils
long			ft_atol(char *num_str);
unsigned long	atol_unsigned(char *num_str);
unsigned long	ft_gettime(void);
bool			print_status(t_info *info, char *msg, int id);
// unsigned long	ft_passtime(unsigned long end_time);

#endif
