/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 11:26:48 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/02 15:34:22 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(t_game *game, char **mapcpy, int o)
{
	int	i;

	i = game->map.rows - 1;
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
		kill_game(game, MALLOC_ERROR, 1);
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
	floodfill(game, y+1, x, mapcpy);
	floodfill(game, y-1, x, mapcpy);
	floodfill(game, y, x+1, mapcpy);
	floodfill(game, y, x-1, mapcpy);
}

static char **map_copier(t_game *game)
{
	int		y;
	int		x;
	char	**mapcpy;
	
	y = 0;
	x = 0;
	mapcpy = malloc(game->map.rows * sizeof(char *));
	if (!mapcpy)
		free_map_copy(game, mapcpy, 1);
	while (y < game->map.rows)
	{
		mapcpy[y] = malloc(game->map.columns * sizeof(char));
		if (!mapcpy[y])
			free_map_copy(game, mapcpy, 1);
		while (x < game->map.columns)
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
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map.rows)
	{
		while (x < game->map.columns)
		{
			if ((y == 0 || y == game->map.rows - 1) && game->map.grid[y][x] != '1')
				kill_game(game, "ERROR: Map not surrounded by walls!", 1);
			if ((x == 0 || x == game->map.columns - 1) && game->map.grid[y][x] != '1')
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
		kill_game(game, ELEM_ERROR, 1);
	wall_check(game);
	mapcpy = map_copier(game);
	floodfill(game, game->player.y, game->player.x, mapcpy);
	if (game->map.elements != game->map.coins + game->map.exit)
		kill_game(game, "ERROR: Can't reach every Coin or the Exit!", 1);
	free_map_copy(game, mapcpy, 0);
}