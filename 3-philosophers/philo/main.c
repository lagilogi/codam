/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/06 13:59:41 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/09/10 19:20:25 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_tester(t_info *info)
{
	printf("\nGIVEN INPUT:");
	printf("\nPhilos:   %ld", info->input->philos);
	printf("\ntt_die:   %lu", info->input->tt_die);
	printf("\ntt_eat:   %lu", info->input->tt_eat);
	printf("\ntt_sleep: %lu", info->input->tt_sleep);
	printf("\nmax_eat:  %ld\n\n", info->input->max_eat);

	// Can't be tested because forks no longer have a struct with a fork_id
	// int i = 0;
	// printf("PHILOS AND FORKS\n");
	// while (i < info->input->philos)
	// {
	// 	printf("Philo %d, has lfork %d and rfork %d\n", info->philos[i]->philo_id, info->philos[i]->left_fork->fork_id, info->philos[i]->right_fork->fork_id);
	// 	i++;
	// }
}


int main(int argc, char **argv)
{
    t_info  info;
	t_input	input;

    if (argc < 5 || argc > 6)
		input_error(1, NULL);
	info.input = &input;
	process_input(&info, argc, argv);
	tabling_philos(&info, 0);


	// philo_tester(&info); // tester


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
// 6. Make threads per philo
//
// 7. Make philos able to 'pick up' a fork
//
// 8. Make sure philos start at same time by getting time of day
//
// 9. Make philo's check how long they are busy with an activity
//
// 10. print timestamps
//
// 11. figure out how to deal with uneven amount of philos





// Usable functions:
//
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
