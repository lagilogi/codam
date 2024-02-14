/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 12:54:01 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/14 12:54:47 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Here we free the malloc'd map when closing the program.
static void	free_map(t_game *game)
{
	int	i;

	i = game->map.mallocs;
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

// This function is solely used to be able to use the mlx_close_hook function
// and to exit the program in a clean way when pressing the X in the upper
// right of the window.
void	kill_game_wrapper(void *param)
{
	t_game	*game;

	game = param;
	kill_game(game, "Closed Game by clicking the X..", 0);
}

// This is the main function for closing the game. We use mlx_terminate, to
// clean up all stuff that mlx needed to function. We then clean up the map
// that we malloc'd into a 2d array. And finally we print the message that
// was sent as argument.
void	kill_game(t_game *game, char *message, int i)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.grid != NULL)
		free_map(game);
	ft_printf("%s\n", message);
	if (i == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
