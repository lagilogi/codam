/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 16:43:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/05 13:59:19 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_loader(t_game *game)
{
	t_txtr	txtr;

	txtr.floor = mlx_load_png("./assets/floor.png");
	txtr.wall = mlx_load_png("./assets/wall.png");
	txtr.player = mlx_load_png("./assets/player.png");
	txtr.coin = mlx_load_png("./assets/coin.png");
	txtr.exit = mlx_load_png("./assets/exit.png");
	if (txtr.floor == NULL || txtr.wall == NULL || txtr.player == NULL
		|| txtr.coin == NULL || txtr.exit == NULL)
		kill_game(game, "ERROR: Couldn't load png!", 1);
	game->img.f = mlx_texture_to_image(game->mlx, txtr.floor);
	game->img.w = mlx_texture_to_image(game->mlx, txtr.wall);
	game->img.p = mlx_texture_to_image(game->mlx, txtr.player);
	game->img.c = mlx_texture_to_image(game->mlx, txtr.coin);
	game->img.e = mlx_texture_to_image(game->mlx, txtr.exit);
	if (game->img.f == NULL || game->img.w == NULL
		|| game->img.p == NULL || game->img.c == NULL
		|| game->img.e == NULL)
		kill_game(game, "ERROR: Couldn't set png to image!", 1);
	mlx_delete_texture(txtr.floor);
	mlx_delete_texture(txtr.wall);
	mlx_delete_texture(txtr.player);
	mlx_delete_texture(txtr.coin);
	mlx_delete_texture(txtr.exit);
}

static void	draw_player(t_game *game)
{
	int		x;
	int		y;
	bool	drawn;

	x = 0;
	y = 0;
	drawn = false;
	while (y < game->map.row)
	{
		while (x < game->map.col)
		{
			if (game->map.grid[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->img.p, x * IMGW, y * IMGH);
				drawn = true;
				break ;
			}
			x++;
		}
		if (drawn)
			break ;
		y++;
		x = 0;
	}
}

static void	draw_coins(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (y < game->map.row)
	{
		while (x < game->map.col)
		{
			if (game->map.grid[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx, game->img.c, x * IMGW, y * IMGH);
				add_coin_to_list(game, y, x, i);
				i++;
			}
			x++;
		}
		y++;
		x = 0;
	}
}

static void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.row)
	{
		while (x < game->map.col)
		{
			if (game->map.grid[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img.w, x * IMGW, y * IMGH);
			else if (game->map.grid[y][x] == '0')
				mlx_image_to_window(game->mlx, game->img.f, x * IMGW, y * IMGH);
			else if (game->map.grid[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, game->img.f, x * IMGW, y * IMGH);
				mlx_image_to_window(game->mlx, game->img.e, x * IMGW, y * IMGH);
			}
			else
				mlx_image_to_window(game->mlx, game->img.f, x * IMGW, y * IMGH);
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
