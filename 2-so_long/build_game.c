/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 16:43:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/26 18:22:02 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void texture_to_image(t_game *game)
// {
// 	game->image.floor = mlx_texture_to_image(game->mlx, txtr_floor);
// 	game->image.wall = mlx_texture_to_image(game->mlx, txtr_wall);
// 	game->image.player = mlx_texture_to_image(game->mlx, txtr_player);
// 	game->image.oil = mlx_texture_to_image(game->mlx, txtr_oil);
// 	game->image.exit = mlx_texture_to_image(game->mlx, txtr_exit);
// }

static void	images_loader(t_game *game)
{
	mlx_texture_t *txtr_floor = mlx_load_png("./assets/floor.png");
	mlx_texture_t *txtr_wall = mlx_load_png("./assets/wall.png");
	mlx_texture_t *txtr_player = mlx_load_png("./assets/player.png");
	mlx_texture_t *txtr_oil = mlx_load_png("./assets/oil.png");
	mlx_texture_t *txtr_exit = mlx_load_png("./assets/exit.png");
	if (txtr_floor == NULL || txtr_wall == NULL || txtr_player == NULL
		|| txtr_oil == NULL || txtr_exit == NULL)
		kill_game(game, "ERROR: Couldn't load png!");


		
	game->image.floor = mlx_texture_to_image(game->mlx, txtr_floor);
	if (game->image.floor == NULL)
		kill_game(game, "ERROR: Couldn't set png to image!");
	game->image.wall = mlx_texture_to_image(game->mlx, txtr_wall);
	game->image.player = mlx_texture_to_image(game->mlx, txtr_player);
	game->image.oil = mlx_texture_to_image(game->mlx, txtr_oil);
	game->image.exit = mlx_texture_to_image(game->mlx, txtr_exit);

	// texture_to_image(game)
}

static void	draw_player(t_game *game)
{
	int x = 0;
	int y = 0;
	while (y < game->map.rows)
	{
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->image.floor, x*IMG_W, y*IMG_H);
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
			else if (game->map.grid[y][x] == 'C')
			{	
				mlx_image_to_window(game->mlx, game->image.floor, x*IMG_W, y*IMG_H);
				mlx_image_to_window(game->mlx, game->image.oil, x*IMG_W, y*IMG_H);
			}
			else if (game->map.grid[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, game->image.floor, x*IMG_W, y*IMG_H);
				mlx_image_to_window(game->mlx, game->image.exit, x*IMG_W, y*IMG_H);
			}
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
	draw_player(game);
}