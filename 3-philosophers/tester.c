# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*priming(void *arg)
{
	printf("%d\n", (int) arg);
}


int	main(int argc, char **argv)
{
	pthread_t	th[10];

	for (int i = 0; i < 10; i++)
		if (pthread_create(&th[i], NULL, &priming, &th[i]) != 0)
			return (1);

	

	for (int i = 0; i < 10; i++)
		if (pthred_join(th[i], NULL) == -1)
			return (2);
	return (0);
}


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
