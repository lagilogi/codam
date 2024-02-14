/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 11:26:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/14 13:49:15 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// We free the map copy as we no longer need it as well as set all pointers to
// NULL so we have no dangling pointers.
static void	free_map_copy(t_game *game, char **mapcpy, int y, int o)
{
	while (y >= 0 && mapcpy != NULL)
	{
		free(mapcpy[y]);
		mapcpy[y] = NULL;
		y--;
	}
	if (mapcpy != NULL)
	{
		free(mapcpy);
		mapcpy = NULL;
	}
	if (o == 0)
		return ;
	else
		kill_game(game, "ERROR\nFailed to malloc mapcpy data!", 1);
}

// To check if we can get to all coins and the exit we use the floodfill
// algorithm.
// We start at the point of the player and move everywhere where there is not
// a '1'.
// When we find a 'C' or an 'E' we increment the amount of elements found.
// After we've been to a place, we then put a '1' in that spot as we don't need
// to go there anymore and this will refrain us to do so.
static void	floodfill(t_game *game, int y, int x, char **mapcpy)
{
	if (game->map.elements == game->map.coins + game->map.exit)
		return ;
	else if (mapcpy[y][x] == '1')
		return ;
	else if (mapcpy[y][x] == 'C' || mapcpy[y][x] == 'E')
		game->map.elements++;
	mapcpy[y][x] = '1';
	floodfill(game, y + 1, x, mapcpy);
	floodfill(game, y - 1, x, mapcpy);
	floodfill(game, y, x + 1, mapcpy);
	floodfill(game, y, x - 1, mapcpy);
}

// We simply recreate the map like we did in load_map.c
static char	**map_copier(t_game *game)
{
	int		y;
	int		x;
	char	**mapcpy;

	y = 0;
	x = 0;
	mapcpy = malloc(game->map.row * sizeof(char *));
	if (!mapcpy)
		kill_game(game, "ERROR\nFailed to malloc mapcpy data!", 1);
	while (y < game->map.row)
	{
		mapcpy[y] = malloc(game->map.col * sizeof(char));
		if (!mapcpy[y])
			free_map_copy(game, mapcpy, y - 1, 1);
		while (x < game->map.col)
		{
			mapcpy[y][x] = game->map.grid[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	return (mapcpy);
}

// We check here if the map is surrounded by walls. We do this by checking the
// if the first row and last row is only '1', and we do the same for the first
// and lasts column. If any other char is found we kill the program.
static void	wall_check(t_game *game)
{
	int		y;
	int		x;
	t_map	map;

	y = 0;
	x = 0;
	map = game->map;
	while (y < map.row)
	{
		while (x < map.col)
		{
			if ((y == 0 || y == map.row - 1) && map.grid[y][x] != '1')
				kill_game(game, "ERROR\nMap not surrounded by walls!", 1);
			if ((x == 0 || x == map.col - 1) && map.grid[y][x] != '1')
				kill_game(game, "ERROR\nMap not surrounded by walls!", 1);
			x++;
		}
		y++;
		x = 0;
	}
}

// In the map_checker we check if the map is valid by testing a couple of this.
// 1. With the function call of wall_check we check if the map is surrounded
// by walls.
// 2. We make a double pointer here to that we pass to map_copier to make a
// copy of the map and then in the "floodfill" function we will test if the
// player can get to all coins and the exit. We check this by comparing the
// amount of elements found in this function to the amount of coins + exit
// we found when loading the map. We then free the copy of the map as we no
// no longer need it.
void	map_checker(t_game *game)
{
	char	**mapcpy;

	if (game->map.player != 1 || game->map.exit != 1 || game->map.coins < 1)
		kill_game(game, "ERROR\nIncorrect Player, Coin or Exit amount!", 1);
	wall_check(game);
	mapcpy = map_copier(game);
	floodfill(game, game->player.y, game->player.x, mapcpy);
	if (game->map.elements != game->map.coins + game->map.exit)
		kill_game(game, "ERROR\nCan't reach every Coin or the Exit!", 1);
	free_map_copy(game, mapcpy, game->map.row - 1, 0);
}
