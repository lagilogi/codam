/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   win_lose.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 14:09:52 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 18:38:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// This is the animation that makes the rocket fly up in different stages, going
// from slow to fast and faster, by checking the value of the delta_animation,
// which gets incremented by the time between every frame.
void	win_animation(t_game *game)
{
	if (game->time.delta_animation < 0.5)
		game->img.e2->instances[0].y -= 2;
	else if (game->time.delta_animation < 1)
		game->img.e2->instances[0].y -= 4;
	else
		game->img.e2->instances[0].y -= 10;
}

// In the win function we set stop the game by setting the game-win value
// to 1. To make it look like we won we removed the player from the screen
// and replace the rocket with the other rocket that looks like its flying
// with the character inside. We also print text to the middle of the
// window and make it bigger and more readable with mlx_resize_image.
void	win(t_game *game)
{
	mlx_image_t	*win;
	int			x;
	int			y;
	int			tmp;

	x = (game->mlx->width / 2) - (IMGW * 1.85);
	y = game->mlx->height / 2.5;
	game->win = 1;
	game->img.p->instances[0].z = -1000;
	game->img.p2->instances[0].z = -1000;
	win = mlx_put_string(game->mlx, "You Escaped!", x, y);
	ft_printf("Congrats! You escaped!\nPress Esc to exit the game..\n");
	if (win == NULL)
		return ;
	if (!mlx_resize_image(win, win->width * 2.5, win->height * 2.5))
		return ;
	tmp = game->img.e->instances[0].y;
	game->img.e->instances[0].y = -100;
	game->img.e2->instances[0].y = tmp;
	game->time.delta_animation = 0;
}

// In the lose function we stop the game by setting the game->win value to 1.
// To make it look like we lost and the game is over, we remove the player
// from view and print text to the middle of the window.
// We use the mlx_resize_image to make the text bigger.
void	lose(t_game *game)
{
	mlx_image_t	*lose;
	int			x;
	int			y;

	x = (game->mlx->width / 2) - (IMGW * 1.85);
	y = game->mlx->height / 2.5;
	game->win = 1;
	game->img.p->instances[0].z = -1000;
	game->img.p2->instances[0].z = -1000;
	lose = mlx_put_string(game->mlx, "Awwh, You Died!", x, y);
	ft_printf("You died!\nPress Esc to exit the game..\n");
	if (lose == NULL)
		return ;
	if (!mlx_resize_image(lose, lose->width * 2.5, lose->height * 2.5))
		return ;
}
