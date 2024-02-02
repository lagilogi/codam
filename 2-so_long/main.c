/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 13:36:31 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/02 17:48:39 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_initilization(t_game *game)
{
	int	width;
	int	height;

	width = game->map.columns * IMG_W;
	height = game->map.rows * IMG_H;
	game->mlx = mlx_init(width, height, "Grand Theft Auto 7", false);
}

static void	game_initilization(t_game *game)
{
	game->mlx = NULL;
	game->image.floor = NULL;
	game->image.wall = NULL;
	game->image.player = NULL;
	game->image.coin = NULL;
	game->image.exit = NULL;
	game->map.grid = NULL;
	game->map.columns = 0;
	game->map.rows = 0;
	game->map.player = 0;
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.elements = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->coin = NULL;
	game->moves = 0;
}

static int	arg_check(int argc, const char *map_file)
{
	int		i;
	int		len;
	char	*extension;

	if (argc != 2)
		return (ft_printf("ERROR: Incorrect amount of arguments given!\n"), 1);
	i = 3;
	len = strlen(map_file);
	if (len <= 4)
		return (ft_printf("Map too short\n"), 0);
	extension = ".ber";
	while (i >= 0)
	{
		if (map_file[len-1] != extension[i])
			return(0);
		i--;
		len--;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_game	game;

	arg_check(argc, argv[1]);
	game_initilization(&game);
	load_map(&game, argv[1]);
	map_checker(&game);
	window_initilization(&game);
	build_game(&game);
	run_game(&game);
	return (0);
}
