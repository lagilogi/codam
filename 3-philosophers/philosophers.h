/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/05 18:44:12 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "./libft/libft.h"

// Struct that every philo has
typedef struct s_philo
{
	int	num;
	int	tt_die;
    int	tt_eat;
    int	tt_sleep;
    int	max_eat;
}	t_philo;

// Struct for given input
typedef struct s_input
{
    int	philos;
    int	tt_die;
    int	tt_eat;
    int	tt_sleep;
    int	max_eat;	
}	t_input;


// Main struct
typedef struct s_info
{
	t_input	*input;
	int		*forks;
}   t_info;



#endif