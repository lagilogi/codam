/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:51:24 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/02 15:03:15 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}


static void	element_checker(t_game *game, char *line, int y, int x)
{
	if (line[x] == 'P')
	{
		game->map.player++;
		game->player.x = x;
		game->player.y = y;
		if (game->map.player != 1)
			kill_game(game, CHAR_ERROR, 1);
	}
	else if (line[x] == 'E')
	{
		game->map.exit++;
		if (game->map.exit != 1)
			kill_game(game, CHAR_ERROR, 1);
	}
	else if (line[x] == 'C')
		game->map.coins++;
	else if (line[x] != '1' && line[x] != '0')
		kill_game(game, CHAR_ERROR, 1);
	game->map.grid[y][x] = line[x];
}


static void	loading_map_data(t_game *game, char *argv)
{
	int		fd;
	int		y;
	int 	x;
	char	*line;

	y = -1;
	x = -1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, FILE_ERROR, 1);
	while (++y < game->map.rows)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map.grid[y] = malloc(game->map.columns * sizeof(char));
		if (!game->map.grid[y])
			kill_game(game, MALLOC_ERROR, 1);
		while (++x < game->map.columns)
			element_checker(game, line, y, x);
		x = -1;
		free (line);
	}
	close(fd);
}


static void	rows_columns_check(t_game *game, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, FILE_ERROR, 1);
	line = get_next_line(fd);
	if (!line)
		kill_game(game, EMPTY_MAP, 1);
	game->map.rows = 0;
	game->map.columns = ft_linelen(line);
	free (line);
	while (++game->map.rows)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_linelen(line) != game->map.columns)
			kill_game(game, COLUMN_ERROR, 1);
		free (line);
	}
	close(fd);
	game->map.grid = malloc(game->map.rows * sizeof(char *));
	if (!game->map.grid)
		kill_game(game, MALLOC_ERROR, 1);
}


void	load_map(t_game *game, char *argv)
{
	rows_columns_check(game, argv);
	loading_map_data(game, argv);
}
