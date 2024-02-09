/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 17:53:36 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/09 19:07:44 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(t_game *game)
{
	int	y;
	int	x;
	int	i;
	int	random;

	i = 0;
	while (i < game->map.enemies)
	{
		y = game->img.t->instances[i].y / IMGH;
		x = game->img.t->instances[i].x / IMGW;
		srand(rand());
		random = (rand() % 4) + 1;
		if (random == 1 && (game->map.grid[y+1][x] == '0' || game->map.grid[y+1][x] == 'P'))
		{
			game->map.grid[y][x] = '0';
			game->img.t->instances[i].y += IMGH;
			game->map.grid[y+1][x] = 'T';
		}
		else if (random == 2 && (game->map.grid[y-1][x] == '0' || game->map.grid[y-1][x] == 'P'))
		{
			game->map.grid[y][x] = '0';
			game->img.t->instances[i].y -= IMGH;
			game->map.grid[y-1][x] = 'T';
		}
		else if (random == 3 && (game->map.grid[y][x-1] == '0' || game->map.grid[y][x-1] == 'P'))
		{
			game->map.grid[y][x] = '0';
			game->img.t->instances[i].x -= IMGW;
			game->map.grid[y][x-1] = 'T';
		}
		else if (random == 4 && (game->map.grid[y][x+1] == '0' || game->map.grid[y][x+1] == 'P'))
		{
			game->map.grid[y][x] = '0';
			game->img.t->instances[i].x += IMGW;
			game->map.grid[y][x+1] = 'T';
		}
		i++;
	}
	if (game->map.grid[y][x] == 'T')
		lose(game);
}

void	draw_enemies(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->map.row)
	{
		while (x < game->map.col)
		{
			if (game->map.grid[y][x] == 'T')
				mlx_image_to_window(game->mlx, game->img.t, x * IMGW, y * IMGH);
			x++;
		}
		y++;
		x = 0;
	}	
}
