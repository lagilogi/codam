/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 17:53:36 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 17:45:29 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// To load in the textures of the enemies and set them to images. We delete the
// texture at the end as we don't need them anymore.
static void	enemy_loader(t_game *game, t_txtr *txtr, t_image *img)
{
	txtr->enemy = mlx_load_png("./assets/enemy.png");
	txtr->enemy2 = mlx_load_png("./assets/enemy2.png");
	if (txtr->enemy == NULL || txtr->enemy2 == NULL)
		kill_game(game, "ERROR\nCouldn't load Enemy PNGs!", 1);
	img->t = mlx_texture_to_image(game->mlx, txtr->enemy);
	img->t2 = mlx_texture_to_image(game->mlx, txtr->enemy2);
	if (img->t == NULL || img->t2 == NULL)
		kill_game(game, "ERROR\nCouldn't set Enemy textures to image!", 1);
	mlx_delete_texture(txtr->enemy);
	mlx_delete_texture(txtr->enemy2);
}

// Here we draw the enemies onto the screen. We first load them with the
// enemy_loader function. We then go through the 2D array and place an enemy at
// every spot we found a T (which stands for Threat, as E was already taken for
// Exit). We place the 2nd frame of the enemy outside of our vision. 
void	draw_enemies(t_game *game, mlx_t *mlx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	enemy_loader(game, &game->txtr, &game->img);
	while (y < game->map.row)
	{
		while (x < game->map.col)
		{
			if (game->map.grid[y][x] == 'T')
			{
				mlx_image_to_window(mlx, game->img.t, x * IMGW, y * IMGH);
				mlx_image_to_window(mlx, game->img.t2, x * IMGW, y * IMGH);
				game->img.t2->instances[i].y = -100;
				i++;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
