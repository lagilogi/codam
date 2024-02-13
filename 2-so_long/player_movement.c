/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 16:38:33 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 19:13:47 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_up(t_game *game)
{
	game->img.p->instances[0].y -= IMGH;
	game->img.p2->instances[0].y -= IMGH;
}

static void	ft_down(t_game *game)
{
	game->img.p->instances[0].y += IMGH;
	game->img.p2->instances[0].y += IMGH;
}

static void	ft_left(t_game *game)
{
	game->img.p->instances[0].x -= IMGW;
	game->img.p2->instances[0].x -= IMGW;
}

// Need to move both instances of course.
static void	ft_right(t_game *game)
{
	game->img.p->instances[0].x += IMGW;
	game->img.p2->instances[0].x += IMGW;
}

// This function we use to move the character around (or close the game
// with Esc). When pressing a key to move, we check what key we pressed
// and go into the tile_check function to check if can move to where we
// want to go. If we can then that means our player's x or y value 
// changed and we increment our move count.
void	movement(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		y;
	int		x;

	game = param;
	y = game->player.y;
	x = game->player.x;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		kill_game(game, "Closing Game!", 0);
	else if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (game->win == 0)
		{
			if (keydata.key == MLX_KEY_W && tile_check(game, -1, 0) == 1)
				ft_up(game);
			else if (keydata.key == MLX_KEY_S && tile_check(game, 1, 0) == 1)
				ft_down(game);
			else if (keydata.key == MLX_KEY_A && tile_check(game, 0, -1) == 1)
				ft_left(game);
			else if (keydata.key == MLX_KEY_D && tile_check(game, 0, 1) == 1)
				ft_right(game);
			if (x != game->player.x || y != game->player.y)
				moves_count(game);
		}
	}
}
