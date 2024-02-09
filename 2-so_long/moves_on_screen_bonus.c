/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves_on_screen_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 17:40:28 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/06 17:38:48 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves_text(t_game *game)
{
	mlx_image_t	*moves;

	moves = mlx_put_string(game->mlx, "Moves:", 15, 35);
	if (moves == NULL)
		kill_game (game, "ERROR: Failed generating *Moves:* image!", 1);
	if (!mlx_resize_image(moves, moves->width * 2, moves->height * 2))
		kill_game (game, "ERROR: Failed resizing *Moves:* image!", 1);
}

void	moves_count(t_game *game)
{
	char		*moves;
	mlx_image_t	*m_count;

	moves = ft_itoa(++game->moves);
	if (game->mc != NULL)
		mlx_delete_image(game->mlx, game->mc);
	game->mc = mlx_put_string(game->mlx, moves, 170, 35);
	if (game->mc == NULL)
		kill_game(game, "ERROR: Failed generating Moves Count image!", 1);
	if (!mlx_resize_image(game->mc, game->mc->width * 2, game->mc->height * 2))
		kill_game(game, "ERROR: Failed resizing Move count image!", 1);
	free(moves);
	ft_printf("Moves: %d\n", game->moves);
}
