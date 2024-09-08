/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/08 16:41:24 by wsonepou      ########   odam.nl         */
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


// struct for every fork
typedef struct s_fork
{
	int				fork_id;
	pthread_mutex_t	fork_lock;
}	t_fork;


// Struct that every philo has
typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned long	max_eat;
	t_fork			*left_fork;
	t_fork			*right_fork;
	unsigned long	time_to_start;
}	t_philo;


// Struct for given input
typedef struct s_input
{
    int				philos;
	unsigned long	tt_die;
	unsigned long	tt_eat;
	unsigned long	tt_sleep;
	unsigned long	max_eat;	
}	t_input;


// Main struct
typedef struct s_info
{
	t_input			*input;
	t_fork			**forks;
	t_philo			**philos;
}   t_info;

// 1. Parsing
void			process_input(t_info *info, int argc, char **argv);

// 2. Running simulation
void			tabling_philos(t_info *info, int philo);

// 3. Ending and error handling
void			kill_program(t_info *info, char *msg, int exit_code);
void			input_error(int i, char *arg);
void 			free_failed_philo_array(t_info *info, int i);
void 			free_failed_fork_array(t_info *info, int i);

// 4. Utils
int				ft_atoi(char *num_str);
unsigned long	atol_unsigned(char *num_str);
unsigned long	ft_gettime();

#endif