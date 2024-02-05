/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:51:24 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/05 14:28:17 by wsonepou      ########   odam.nl         */
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
			kill_game(game, "ERROR: Invalid character found in map!", 1);
	}
	else if (line[x] == 'E')
	{
		game->map.exit++;
		if (game->map.exit != 1)
			kill_game(game, "ERROR: Invalid character found in map!", 1);
	}
	else if (line[x] == 'C')
		game->map.coins++;
	else if (line[x] != '1' && line[x] != '0')
		kill_game(game, "ERROR: Invalid character found in map!", 1);
	game->map.grid[y][x] = line[x];
}

static void	loading_map_data(t_game *game, char *argv)
{
	int		fd;
	int		y;
	int		x;
	char	*line;

	y = -1;
	x = -1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, "ERROR: Couldn't open file!", 1);
	while (++y < game->map.row)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map.grid[y] = malloc(game->map.col * sizeof(char));
		if (!game->map.grid[y])
			kill_game(game, "ERROR: Failed to malloc map data!", 1);
		while (++x < game->map.col)
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
		kill_game(game, "ERROR: Couldn't open file!", 1);
	line = get_next_line(fd);
	if (!line)
		kill_game(game, "ERROR: Empty map!", 1);
	game->map.row = 0;
	game->map.col = ft_linelen(line);
	free (line);
	while (++game->map.row)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_linelen(line) != game->map.col)
			kill_game(game, "ERROR: Uneven map!", 1);
		free (line);
	}
	close(fd);
	game->map.grid = malloc(game->map.row * sizeof(char *));
	if (!game->map.grid)
		kill_game(game, "ERROR: Failed to malloc map data!", 1);
}

void	load_map(t_game *game, char *argv)
{
	rows_columns_check(game, argv);
	loading_map_data(game, argv);
}
