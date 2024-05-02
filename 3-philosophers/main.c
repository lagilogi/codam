#include "philosophers.h"

static void setting_info(t_info *info, char **argv)
{
    info->philos = ft_atoi(argv[1]);
    // info->tt_die = ft_atoi_double(argv[2]);
    // info->tt_eat = ft_atoi_double(argv[3]);
    // info->tt_sleep = ft_atoi_double(argv[4]);
    info->max_eat = ft_atoi(argv[5]);
}

int main(int argc, char **argv)
{
    t_info  info;

    if (argc != 6)
        return (1);
    setting_info(&info, argv);


    return (0);
}