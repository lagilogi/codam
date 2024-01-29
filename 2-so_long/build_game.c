/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 16:43:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/29 18:59:55 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	images_loader(t_game *game)
{
	mlx_texture_t *txtr_floor = mlx_load_png("./assets/floor.png");
	mlx_texture_t *txtr_wall = mlx_load_png("./assets/wall.png");
	mlx_texture_t *txtr_player = mlx_load_png("./assets/player.png");
	mlx_texture_t *txtr_coin = mlx_load_png("./assets/coin.png");
	mlx_texture_t *txtr_exit = mlx_load_png("./assets/exit.png");
	if (txtr_floor == NULL || txtr_wall == NULL || txtr_player == NULL
		|| txtr_coin == NULL || txtr_exit == NULL)
		kill_game(game, "ERROR: Couldn't load png!");	
	game->image.floor = mlx_texture_to_image(game->mlx, txtr_floor);
	game->image.wall = mlx_texture_to_image(game->mlx, txtr_wall);
	game->image.player = mlx_texture_to_image(game->mlx, txtr_player);
	game->image.coin = mlx_texture_to_image(game->mlx, txtr_coin);
	game->image.exit = mlx_texture_to_image(game->mlx, txtr_exit);
	if (game->image.floor == NULL || game->image.wall == NULL
		|| game->image.player == NULL || game->image.coin == NULL
		|| game->image.exit == NULL)
		kill_game(game, "ERROR: Couldn't set png to image!");
}

static void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.rows)
	{
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->image.player, x*IMG_W, y*IMG_H);
				game->player.x = x;
				game->player.y = y;
				break ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_coins(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;
	t_coin	*temp;

	x = 0;
	y = 0;
	i = 0;
	while (y < game->map.rows)
	{
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, game->image.coin, x*IMG_W, y*IMG_H);
				add_coin_to_list(game, y, x, i);
				i++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	j = 0;
	temp = game->coin;
	while (temp)
	{
		printf("Instance %i: %d\n", j, temp->instance);
		printf("y: %d\n", temp->y);
		printf("x: %d\n", temp->x);
		j++;
		temp = temp->next;
	}
}

static void	draw_map(t_game *game)
{
	int x = 0;
	int y = 0;
	while (y < game->map.rows)
	{
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == '1')
				mlx_image_to_window(game->mlx, game->image.wall, x*IMG_W, y*IMG_H);
			else if (game->map.grid[y][x] == '0')
				mlx_image_to_window(game->mlx, game->image.floor, x*IMG_W, y*IMG_H);
			else if (game->map.grid[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, game->image.floor, x*IMG_W, y*IMG_H);
				mlx_image_to_window(game->mlx, game->image.exit, x*IMG_W, y*IMG_H);
			}
			else
				mlx_image_to_window(game->mlx, game->image.floor, x*IMG_W, y*IMG_H);
			x++;
		}
		y++;
		x = 0;
	}
}

void	build_game(t_game *game)
{
	images_loader(game);
	draw_map(game);
	draw_coins(game);
	draw_player(game);
}