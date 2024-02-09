/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 13:36:31 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/09 16:47:28 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_initilization(t_game *game)
{
	int	width;
	int	height;

	width = game->map.col * IMGW;
	height = game->map.row * IMGH;
	game->mlx = mlx_init(width, height, "Escape The Moon", false);
	if (!game->mlx)
		kill_game(game, "ERROR: Couldn't initialize MLX!", 1);
}

static void	game_initilization(t_game *game)
{
	game->mlx = NULL;
	game->img.f = NULL;
	game->img.w = NULL;
	game->img.p = NULL;
	game->img.c = NULL;
	game->img.e = NULL;
	game->img.t = NULL;
	game->map.grid = NULL;
	game->map.col = 0;
	game->map.row = 0;
	game->map.player = 0;
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.enemies = 0;
	game->map.elements = 0;
	game->coin = NULL;
	game->win = 0;
	game->mc = NULL;
	game->moves = 0;
	game->enemy = NULL;
}

static int	arg_check(int argc, const char *map_file)
{
	int		i;
	int		len;
	char	*extension;

	if (argc != 2)
		return (ft_printf("ERROR: Incorrect amount of arguments given!\n"), 1);
	i = 3;
	len = ft_strlen(map_file);
	if (len <= 4)
		return (ft_printf("Map too short\n"), 0);
	extension = ".ber";
	while (i >= 0)
	{
		if (map_file[len - 1] != extension[i])
			return (0);
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
