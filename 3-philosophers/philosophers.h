#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "./libft/libft.h"

typedef struct s_info
{
    int     philos;
    double  tt_die;
    double  tt_eat;
    double  tt_sleep;
    int     max_eat;
}   t_info;



#endif