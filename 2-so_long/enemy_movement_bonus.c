/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_movement_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 17:53:36 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/15 12:14:36 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_up(t_game *game, int y, int x, int i)
{
	game->map.grid[y][x] = '0';
	game->img.t->instances[i].y -= IMGH;
	game->img.t2->instances[i].y -= IMGH;
	game->map.grid[y - 1][x] = 'T';
	if (y - 1 == game->player.y && x == game->player.x)
		lose(game);
}

static void	ft_down(t_game *game, int y, int x, int i)
{
	game->map.grid[y][x] = '0';
	game->img.t->instances[i].y += IMGH;
	game->img.t2->instances[i].y += IMGH;
	game->map.grid[y + 1][x] = 'T';
	if (y + 1 == game->player.y && x == game->player.x)
		lose(game);
}

static void	ft_left(t_game *game, int y, int x, int i)
{
	game->map.grid[y][x] = '0';
	game->img.t->instances[i].x -= IMGW;
	game->img.t2->instances[i].x -= IMGW;
	game->map.grid[y][x - 1] = 'T';
	if (y == game->player.y && x - 1 == game->player.x)
		lose(game);
}

// To make the player lose when it hits an enemy, we need to keep moving the 'T'
// around. So when an enemy moves, the previous tile he was on is set to '0' in
// the 2D array, and the one he moves to becomes a 'T'. If the player X and Y
// values are the same as that of a 'T', the player loses.
static void	ft_right(t_game *game, int y, int x, int i)
{
	game->map.grid[y][x] = '0';
	game->img.t->instances[i].x += IMGW;
	game->img.t2->instances[i].x += IMGW;
	game->map.grid[y][x + 1] = 'T';
	if (y == game->player.y && x + 1 == game->player.x)
		lose(game);
}

// In this function we make the enemy move in a random direction after
// a certain amount of time has passed. When the enemy is about to move,
// we need to check which frame is the right one, so we don't mess up the 
// Y value and teleport the enemy itself out of bounds.
// We then use srand(rand) to generate a random number, which will then be used
// to generate a random number between 1-4, which then decides what way the
// enemy moves in case that tile is a floor tile.
void	enemy_move(t_game *game)
{
	int	y;
	int	x;
	int	i;
	int	random;

	i = 0;
	while (i < game->map.enemies)
	{
		if (game->img.t->instances[i].y > 0)
			y = game->img.t->instances[i].y / IMGH;
		else
			y = game->img.t2->instances[i].y / IMGH;
		x = game->img.t->instances[i].x / IMGW;
		random = (rand() % 4) + 1;
		if (random == 1 && game->map.grid[y + 1][x] == '0')
			ft_down(game, y, x, i);
		else if (random == 2 && game->map.grid[y - 1][x] == '0')
			ft_up(game, y, x, i);
		else if (random == 3 && game->map.grid[y][x - 1] == '0')
			ft_left(game, y, x, i);
		else if (random == 4 && game->map.grid[y][x + 1] == '0')
			ft_right(game, y, x, i);
		i++;
	}
}
