/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 12:54:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/24 14:48:52 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.grid != NULL && game->map.grid[i] != NULL)
	{
		free(game->map.grid[i]);
		i++;
	}
	if (game->map.grid != NULL)
		free(game->map.grid);
}

// static void	assets_cleanup(t_game *game)
// {
// 	mlx_delete_texture(game->);
// }

void	kill_game(t_game *game, char *message)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	// assets_cleanup(game);
	free_map(game);
	ft_printf("%s\n", message);
	exit(1);
}