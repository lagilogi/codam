/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:55:11 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/26 19:40:30 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collectible_remover(t_game *game, int y, int x)
{
	int	i;
	int	y_axis;
	int	x_axis;
	bool check;

	i = 0;
	y_axis = 0;
	x_axis = 0;
	check = false;
	while (y_axis < game->map.rows)
	{
		while (x_axis < game->map.columns)
		{
			if (game->map.grid[y_axis][x_axis] == 'C' && game->image.oil->instances[i].x == x * IMG_W && game->image.oil->instances[i].y == y * IMG_H)
			{
				printf("oil instance: %d\n", i);
				game->image.oil->instances[i].z = 1000;
				check = true;
				break ;
			}
			else if (game->map.grid[y_axis][x_axis] == 'C')
			{
				printf("WRONG oil: %d\n", i);
				i++;
			}
			x_axis++;
		}
		if (check == true)
			break ;
		y_axis++;
		x_axis = 0;
	}
	game->map.collectibles--;
	game->map.grid[y][x] = '0';
	ft_printf("You got a collectible! You have %d collectibles left!\n", game->map.collectibles);
}

int	tile_check(t_game *game, int y_axis, int x_axis)
{
	int	y;
	int	x;
	
	y = game->player.y + y_axis;
	x = game->player.x + x_axis;
	if (game->map.grid[y][x] != '1')
	{
		if (game->map.grid[y][x] == 'C')
			collectible_remover(game, y, x);
		else if (game->map.grid[y][x] == 'E')
		{
			if (game->map.collectibles == 0)
			{
				ft_printf("Congrats! You Won!\n Closing game now..\n");
				exit (EXIT_SUCCESS);
			}
		}
		game->player.y = y;
		game->player.x = x;
		return 1;
	}
	else
	{
		ft_printf("Nice try! You can't move into the wall, dummy!\n");
		return 0;
	}
}

void	movement(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && tile_check(game, -1, 0) == 1)
	{
		game->image.player->instances[0].y -= IMG_H;
		ft_printf("Moves: %d, x: %d, y: %d\n", ++game->moves, game->image.player->instances[0].x, game->image.player->instances[0].y);	
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && tile_check(game, 1, 0) == 1)
	{
		game->image.player->instances[0].y += IMG_H;
		ft_printf("Moves: %d, x: %d, y: %d\n", ++game->moves, game->image.player->instances[0].x, game->image.player->instances[0].y);		
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && tile_check(game, 0, -1) == 1)
	{
		game->image.player->instances[0].x -= IMG_W;
		ft_printf("Moves: %d, x: %d, y: %d\n", ++game->moves, game->image.player->instances[0].x, game->image.player->instances[0].y);	
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && tile_check(game, 0, 1) == 1)
	{
		game->image.player->instances[0].x += IMG_W;
		ft_printf("Moves: %d, x: %d, y: %d\n", ++game->moves, game->image.player->instances[0].x, game->image.player->instances[0].y);		
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		kill_game(game, "Closing Game!");
}

void	run_game(t_game *game)
{
	// printf("Player moves: %d\n", game->moves);
	mlx_key_hook(game->mlx, &movement, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
