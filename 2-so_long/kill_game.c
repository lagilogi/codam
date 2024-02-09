/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 12:54:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/06 17:43:09 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_nodes(t_game *game)
{
	t_coin	*tmp;

	if (!game->coin)
		return ;
	while (game->coin)
	{
		tmp = game->coin->next;
		free(game->coin);
		game->coin = tmp;
	}
	game->coin = NULL;
}

static void	free_map(t_game *game)
{
	int	i;

	i = game->map.row - 1;
	while (i >= 0 && game->map.grid != NULL)
	{
		free(game->map.grid[i]);
		game->map.grid[i] = NULL;
		i--;
	}
	if (game->map.grid != NULL)
	{
		free(game->map.grid);
		game->map.grid = NULL;
	}
}

void	kill_game_wrapper(void *param)
{
	t_game	*game;

	game = param;
	kill_game(game, "Closed Game by clicking the X..", 0);
}

void	kill_game(t_game *game, char *message, int i)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_nodes(game);
	free_map(game);
	ft_printf("%s\n", message);
	if (i == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
