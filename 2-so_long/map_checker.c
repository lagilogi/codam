/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 11:26:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/05 15:01:38 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(t_game *game, char **mapcpy, int o)
{
	int	i;

	i = game->map.row - 1;
	while (i >= 0 && mapcpy != NULL)
	{
		free(mapcpy[i]);
		mapcpy[i] = NULL;
		i--;
	}
	if (mapcpy != NULL)
	{
		free(mapcpy);
		mapcpy = NULL;
	}
	if (o == 0)
		return ;
	else
		kill_game(game, "ERROR: Failed to malloc map data!", 1);
}

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

static char	**map_copier(t_game *game)
{
	int		y;
	int		x;
	char	**mapcpy;

	y = 0;
	x = 0;
	mapcpy = malloc(game->map.row * sizeof(char *));
	if (!mapcpy)
		free_map_copy(game, mapcpy, 1);
	while (y < game->map.row)
	{
		mapcpy[y] = malloc(game->map.col * sizeof(char));
		if (!mapcpy[y])
			free_map_copy(game, mapcpy, 1);
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
				kill_game(game, "ERROR: Map not surrounded by walls!", 1);
			if ((x == 0 || x == map.col - 1) && map.grid[y][x] != '1')
				kill_game(game, "ERROR: Map not surrounded by walls!", 1);
			x++;
		}
		y++;
		x = 0;
	}
}

void	map_checker(t_game *game)
{
	char	**mapcpy;

	if (game->map.player != 1 || game->map.exit != 1 || game->map.coins < 1)
		kill_game(game, "ERROR: Incorrect Player, Coin or Exit amount!", 1);
	wall_check(game);
	mapcpy = map_copier(game);
	floodfill(game, game->player.y, game->player.x, mapcpy);
	if (game->map.elements != game->map.coins + game->map.exit)
		kill_game(game, "ERROR: Can't reach every Coin or the Exit!", 1);
	free_map_copy(game, mapcpy, 0);
}
