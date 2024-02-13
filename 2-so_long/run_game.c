/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:55:11 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 19:14:29 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// When the player over a coin we need to remove this coin from the game and 
// also change the value in the grid at that coordinate. Else the player can
// keep moving over the same tile and keep getting coins. The player only gets a
// coin when the tile has a 'C' so we change the value to 'c'. To know which
// instance of the coin it is we go through the grid with a while loop
// incrementing every time time we find a 'C' or a 'c'.
static void	coin_remover(t_game *game, int y, int x)
{
	int	i;
	int	o;
	int	p;

	i = 0;
	o = 0;
	p = 0;
	while (o < game->map.row)
	{
		while (p < game->map.col)
		{
			if (o == y && p == x)
			{
				game->img.c->instances[i].z = 0;
				game->map.grid[y][x] = 'c';
			}
			else if (game->map.grid[o][p] == 'C' || game->map.grid[o][p] == 'c')
				i++;
			p++;
		}
		o++;
		p = 0;
	}
	game->map.coins--;
	ft_printf("You got a coin! You need %d more coins!\n", game->map.coins);
}

// When the player moves we need to know what we're going to move to. If it's
// a wall then we shouldn't be able to move, if it is a coin we need to pick
// it up and remove it from the game. If it's an enemy we need to lose or, if 
// we have all coins and we move toward the exit, we should win. That is what
// we check here. We get as arguments from the calling function, the changed
// X or Y value which gets added to the player location and then checked with
// if statements.
int	tile_check(t_game *game, int y_axis, int x_axis)
{
	int	y;
	int	x;

	y = game->player.y + y_axis;
	x = game->player.x + x_axis;
	if (game->map.grid[y][x] != '1')
	{
		if (game->map.grid[y][x] == 'C')
			coin_remover(game, y, x);
		else if (game->map.grid[y][x] == 'T')
			lose (game);
		else if (game->map.grid[y][x] == 'E')
		{
			if (game->map.coins == 0)
				win(game);
		}
		game->player.y = y;
		game->player.x = x;
		return (1);
	}
	else
		return (ft_printf("You can't move into the wall, dummy!\n"), 0);
}

// This function is for creating animation, enemy movements and the win
// animation.
// Mlx->delta_time is the time between every frame, which is around 0.016s.
// This is very useful as we can use it to increment a variable up to a 
// certain value, after which something happens like the enemy moving,
// the animation of our character and enemy or the rocket ship flying up
// when the win condition is met.
void	time_passage(void *param)
{
	t_game	*game;

	game = param;
	game->time.delta_enemy_move += game->mlx->delta_time;
	game->time.delta_animation += game->mlx->delta_time;
	if (game->time.delta_enemy_move > 1 && game->win == 0)
	{
		enemy_move(game);
		game->time.delta_enemy_move = 0;
	}
	if (game->time.delta_animation > 0.3 && game->win == 0)
	{
		player_animation(game);
		enemy_animation(game);
		game->time.delta_animation = 0;
	}
	if (game->win == 1 && game->img.e2->instances[0].y > -100)
	{
		win_animation(game);
	}
}

// This is where the interactivity of the game begins. We have a couple of hooks
// that take care of different things.
// - Loop_hook - This hook updates everything within the hook every frame of 
// the screen. We use this hook to update the passage of time and everything
// that to be updated automatically after a certain amount of time like
// animations and enemy movements.
// - Key_hook - This hook is used for the movement of the player. Everytime 
// certain keys are pressed (or held down) something happens, like moving around
// or exiting the game when pressing Esc.
// - Close_hook - This is used simply to close the game in clean way when
// pressing the cross of the window.
// - Mlx_loop - This mlx function keeps the window open and lets us use the 
// other hooks for interactivity.
void	run_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &time_passage, game);
	mlx_key_hook(game->mlx, &movement, game);
	mlx_close_hook(game->mlx, &kill_game_wrapper, game);
	mlx_loop(game->mlx);
}
