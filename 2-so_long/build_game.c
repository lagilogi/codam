/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 16:43:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 17:45:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Here we load all textures and put them to images that we have room for. As
// you can see that is for the floors, walls and the exit.
static void	images_loader(t_txtr *txtr, t_image *img, t_game *game)
{
	txtr->floor = mlx_load_png("./assets/floor.png");
	txtr->wall = mlx_load_png("./assets/wall.png");
	txtr->exit = mlx_load_png("./assets/exit.png");
	txtr->exit2 = mlx_load_png("./assets/exit2.png");
	if (txtr->floor == NULL || txtr->wall == NULL || txtr->exit == NULL
		|| txtr->exit2 == NULL)
		kill_game(game, "ERROR\nCouldn't load PNG!", 1);
	img->f = mlx_texture_to_image(game->mlx, txtr->floor);
	img->w = mlx_texture_to_image(game->mlx, txtr->wall);
	img->e = mlx_texture_to_image(game->mlx, txtr->exit);
	img->e2 = mlx_texture_to_image(game->mlx, txtr->exit2);
	if (img->f == NULL || img->w == NULL || img->e == NULL
		|| img->e2 == NULL)
		kill_game(game, "ERROR\nCouldn't set texture to image!", 1);
	mlx_delete_texture(txtr->floor);
	mlx_delete_texture(txtr->wall);
	mlx_delete_texture(txtr->exit);
	mlx_delete_texture(txtr->exit2);
}

// We start with loading the player PNGs into textures and then set the
// textures to images. We then delete the textures again as we don't need
// them anymore.
// In load_map.c we found and saved the coordinates of the player
// starting position. We will now use that to draw the player in the
// correct spot by multiplying the coordinates * the width/height of the
// images. To save on line length we created 2 variables that will contain
// the results for the X and Y coordinates.
// Frame 2 of the player is set to -1000 as you don't want both frames visible
// at the same moment so we place it out of sight. The 2nd frame is used to to
// animate our character.
static void	draw_player(t_game *game, t_txtr *txtr, t_image *img)
{
	int		x;
	int		y;

	txtr->player = mlx_load_png("./assets/player.png");
	txtr->player2 = mlx_load_png("./assets/player2.png");
	if (txtr->player == NULL || txtr->player2 == NULL)
		kill_game(game, "ERROR\nCouldn't load Player png's!", 1);
	img->p = mlx_texture_to_image(game->mlx, txtr->player);
	img->p2 = mlx_texture_to_image(game->mlx, txtr->player2);
	if (img->p == NULL || img->p2 == NULL)
		kill_game(game, "ERROR\nCouldn't set Player textures to image!", 1);
	mlx_delete_texture(txtr->player);
	mlx_delete_texture(txtr->player2);
	x = game->player.x * IMGW;
	y = game->player.y * IMGH;
	mlx_image_to_window(game->mlx, game->img.p, x, y);
	mlx_image_to_window(game->mlx, game->img.p2, x, -1000);
	game->map.grid[game->player.y][game->player.x] = '0';
}

// Here we load the Coin PNG into a texture and then set the texture to an
// image. We then delete the texture as we don't need that anymore.
// Then we go through the map and start drawing the coins from the image
// onto the coordinates where the 'C' is found in the 2D array.
static void	draw_coins(t_game *game, t_txtr *txtr, t_image *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	txtr->coin = mlx_load_png("./assets/coin.png");
	if (txtr->coin == NULL)
		kill_game(game, "ERROR\nCouldn't load Coin png!", 1);
	img->c = mlx_texture_to_image(game->mlx, txtr->coin);
	if (img->f == NULL)
		kill_game(game, "ERROR\nCouldn't set Coin texture to image!", 1);
	mlx_delete_texture(txtr->coin);
	while (y < game->map.row)
	{
		while (x < game->map.col)
		{
			if (game->map.grid[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img.c, x * IMGW, y * IMGH);
			x++;
		}
		y++;
		x = 0;
	}
}

// Here we draw the map by going through the 2D array. Everytime a '1' is
// found we draw a map at the location of the Y, X coordinate * the width
// and heigth of our images (which is 80*80).
// When we find an 'E' we draw both versions of the exit. We draw the floor
// first and then the version of the exit that stays still. We do it in this
// order to draw the exit on top of the floor. We also draw the flying version
// of the rocket but out of sight of the player as we don't need it until the
// player wins.
// For all other elements found we will simply place a floor already. Everything
// that gets drawn later will appear on top of the floor.
static void	draw_map(t_game *game, mlx_t *mlx)
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
				mlx_image_to_window(mlx, game->img.w, x * IMGW, y * IMGH);
			else if (game->map.grid[y][x] == 'E')
			{
				mlx_image_to_window(mlx, game->img.f, x * IMGW, y * IMGH);
				mlx_image_to_window(mlx, game->img.e, x * IMGW, y * IMGH);
				mlx_image_to_window(mlx, game->img.e2, x * IMGW, -100);
			}
			else
				mlx_image_to_window(mlx, game->img.f, x * IMGW, y * IMGH);
			x++;
		}
		y++;
		x = 0;
	}
}

// We have loaded the map and checked its validity. We are now going to put 
// visuals on the screen. We do this by loading our PNGs and then drawing them
// in a specific order on the screen.
// 1. We start by drawing the map which contain the Walls, Floors and the
// Exit. We added game->mlx as an additional argument to save on line length
// 2. We then draw the coins. I did this because of the line limit in the
// draw_map function. We added additional arguments to save on line length in
// the function.
// 3. We draw the player after the map (and coins) so that it is always in front
// of the floor elements.
// 4. We now draw the enemies. This could've been done before or after player.
// 5. We finally draw the text for "Moves: " so that it appears in front of
// everything. This is just the text and not the changing number that you'll
// see when moving around. This function can be found in the 
// moves_on_screen_bonus.c file
void	build_game(t_game *game)
{
	images_loader(&game->txtr, &game->img, game);
	draw_map(game, game->mlx);
	draw_coins(game, &game->txtr, &game->img);
	draw_player(game, &game->txtr, &game->img);
	draw_enemies(game, game->mlx);
	moves_text(game);
}
