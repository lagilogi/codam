/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:51:24 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/24 15:47:20 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_rowlen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}


static void	element_checker(t_game *game, char c)
{
	if (c == 'P')
	{
		game->map.player++;
		if (game->map.player != 1)
			kill_game(game, PLAYERERR);
	}
	else if (c == 'E')
	{
		game->map.exit++;
		if (game->map.exit != 1)
			kill_game(game, EXITERR);
	}
	else if (c == 'C')
		game->map.collectibles++;
	else if (c == '1')
		return ;
	else if (c == '0')
		return ;
	else
		kill_game(game, ELEMERROR);
}


static void	loading_map_data(t_game *game, char *argv)
{
	int		fd;
	int		y;
	int 	x;
	char	*row;

	y = 0;
	x = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, FILE_ERROR);
	while (y < game->map.rows)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		game->map.grid[y] = malloc(game->map.columns * sizeof(char));
		if (!game->map.grid[y])
			kill_game(game, MALLOCERR);
		while (x < game->map.columns)
		{
			element_checker(game, row[x]);
			game->map.grid[y][x] = row[x];
			x++;
		}
		x = 0;
		y++;
		free (row);
	}
	close(fd);
	// printf("grid 1-1: [%c]\n", game->map.grid[1][1]);
}


static void	rows_columns_check(t_game *game, char *argv)
{
	char	*row;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, FILE_ERROR);
	row = get_next_line(fd);
	if (!row)
		kill_game(game, EMPTYMAP);
	game->map.rows = 1;
	game->map.columns = ft_rowlen(row);
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		game->map.rows++;
		if (ft_rowlen(row) != game->map.columns)
			kill_game(game, COLUMNERR);
		free (row);
	}
	close(fd);
	game->map.grid = malloc(game->map.rows * sizeof(char *));
	if (!game->map.grid)
		kill_game(game, MALLOCERR);
}


void	load_map(t_game *game, char *argv)
{
	rows_columns_check(game, argv);
	loading_map_data(game, argv);
}
