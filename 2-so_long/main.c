/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 13:36:31 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/15 12:17:28 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// This function is to initialize the window, as well as setting the width and
// height of it by calculating the rows and columns of the map * the size each
// sprite has.
static void	window_initilization(t_game *game)
{
	int	width;
	int	height;

	width = game->map.col * IMGW;
	height = game->map.row * IMGH;
	game->mlx = mlx_init(width, height, "Escape The Moon", true);
	if (!game->mlx)
		kill_game(game, "ERROR: Couldn't initialize MLX!", 1);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

// This function sets all important pointers to NULL before setting them to
// another value. Besides the pointers, we set all variables that will be
// incremented to 0.
static void	game_initilization(t_game *game)
{
	game->mlx = NULL;
	game->map.grid = NULL;
	game->map.col = 0;
	game->map.row = 0;
	game->map.player = 0;
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.enemies = 0;
	game->map.elements = 0;
	game->map.mallocs = -1;
	game->win = 0;
	game->mc = NULL;
	game->moves = 0;
	game->time.delta_enemy_move = 0;
	game->time.delta_animation = 0;
	game->player.frame = 0;
	game->enemy_frame = 0;
}

// The arg_check first checks how many arguments are given in the terminal when
// starting the game. This can only be 2. The 1st is the game itself, the 2nd
// is the path towards the map that we want loaded. More or less than 2 gives
// an error.
// Then we check if the map has the correct extension, which is .ber.
// lastly we check the map name length. This can't be shorter or equal to the 
// length of the extension.
static void	arg_check(t_game *game, int argc, const char *map_file)
{
	int		i;
	int		len;
	char	*extension;

	if (argc != 2)
		kill_game(game, "ERROR\nIncorrect amount of arguments given!", 1);
	i = 3;
	len = strlen(map_file);
	extension = ".ber";
	while (i >= 0)
	{
		if (map_file[len - 1] != extension[i])
			kill_game(game, "ERROR\nWrong map extension!", 1);
		i--;
		len--;
	}
	i = 0;
	len = strlen(map_file);
	while (len > 0 && map_file[len - 1] != '/')
	{
		i++;
		len--;
	}
	if (i <= 4)
		kill_game(game, "ERROR\nMap name too short!", 1);
}

// From the main every function for checking, loading, building & running
// the game are being called in an organized order.
int	main(int argc, char **argv)
{
	t_game	game;

	game_initilization(&game);
	arg_check(&game, argc, argv[1]);
	load_map(&game, argv[1]);
	map_checker(&game);
	window_initilization(&game);
	build_game(&game);
	run_game(&game);
	return (0);
}
