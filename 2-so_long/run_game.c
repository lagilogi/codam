/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:55:11 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/29 18:21:56 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collectible_remover(t_game *game, int y, int x)
{
	printf("iterate\n");
	int		y_axis;
	int		x_axis;
	int		i;
	t_coin 	*tmp;

	y_axis = y * IMG_H;
	x_axis = x * IMG_W;
	tmp = game->coin;
	while (tmp != NULL)
	{
		printf("iterate\n");
		printf(">%d<\n", tmp->y);

		if (tmp->y == y_axis && tmp->x == x_axis && tmp->z != -1000)
		{
			printf("%d\n", tmp->instance);
			i = tmp->instance;
			game->image.coin->instances[i].z = -1000;
			tmp->z = -1000;
			break ;
		}
		else
			tmp = tmp->next;		
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
				ft_printf("Congrats! You Escaped!\nClosing game now..\n");
				exit (EXIT_SUCCESS);
			}
		}
		game->player.y = y;
		game->player.x = x;
		return (1);
	}
	else
	{
		ft_printf("Nice try! You can't move into the wall, dummy!\n");
		return (0);
	}
}

void	movement(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && tile_check(game, -1, 0) == 1)
	{
		game->image.player->instances[0].y -= IMG_H;
		ft_printf("Moves: %d\n", ++game->moves);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS	&& tile_check(game, 1, 0) == 1)
	{
		game->image.player->instances[0].y += IMG_H;
		ft_printf("Moves: %d\n", ++game->moves);	
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS	&& tile_check(game, 0, -1) == 1)
	{
		game->image.player->instances[0].x -= IMG_W;
		ft_printf("Moves: %d\n", ++game->moves);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS	&& tile_check(game, 0, 1) == 1)
	{
		game->image.player->instances[0].x += IMG_W;
		ft_printf("Moves: %d\n", ++game->moves);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		kill_game(game, "Closing Game!");
}

void	run_game(t_game *game)
{
	mlx_key_hook(game->mlx, &movement, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
