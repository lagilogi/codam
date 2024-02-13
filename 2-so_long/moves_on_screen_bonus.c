/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves_on_screen_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 17:40:28 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 18:55:19 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Here we simply place the text "Moves: " in the upper left corner and resize
// the image to make it a little bigger and better readable.
void	moves_text(t_game *game)
{
	mlx_image_t	*moves;

	moves = mlx_put_string(game->mlx, "Moves:", 15, 35);
	if (moves == NULL)
		kill_game (game, "ERROR\nFailed generating *Moves:* image!", 1);
	if (!mlx_resize_image(moves, moves->width * 2, moves->height * 2))
		kill_game (game, "ERROR\nFailed resizing *Moves:* image!", 1);
}

// Here we create the move count. As we get the number as an integer we need to
// make it a char/string to use the mlx_put_string function to put it on the
// screen. As every new count is a different image we need to delete the older
// image to remove it from the screen and then place the new number there
// instead. We also still print the amount of moves in the terminal.
void	moves_count(t_game *game)
{
	char		*moves;
	mlx_image_t	*m_count;

	moves = ft_itoa(++game->moves);
	if (game->mc != NULL)
		mlx_delete_image(game->mlx, game->mc);
	game->mc = mlx_put_string(game->mlx, moves, 170, 35);
	if (game->mc == NULL)
		kill_game(game, "ERROR\nFailed generating Moves Count image!", 1);
	if (!mlx_resize_image(game->mc, game->mc->width * 2, game->mc->height * 2))
		kill_game(game, "ERROR\nFailed resizing Move count image!", 1);
	free(moves);
	ft_printf("Moves: %d\n", game->moves);
}
