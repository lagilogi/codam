/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:51:24 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/15 17:26:20 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// As our map can only have specific elements, we don't want any other elements
// that don't do anything for us. Therefor we check every element and if needed
// we increment the amount of a certain element.
// - 'P' = Player - As we now know where the player is we save the coordinates 
// in our player struct. Besided we increment the amount of players so if there 
// are more than 1, we kill the program.
// - 'E' = Exit - Same as for player, there can only be 1 exit. If more are
// found we kill the program.
// - 'C' = Coin - We need to keep track of how many coins there are so we 
// increment the coins. In the game the player needs to gather this many coins
// to escape and win.
// - 'T' = Threat/Enemy - We keep track of the amount of enemies so we can cycle
// through the enemy instances when moving 
// - '1' and '0' = Walls and Floors - We use the ! NOT statements to save lines.
// Lastly we put the element in our 2D array with the last line.
static void	element_checker(t_game *game, char *line, int y, int x)
{
	if (line[x] == 'P')
	{
		game->map.player++;
		game->player.x = x;
		game->player.y = y;
		if (game->map.player != 1)
			kill_game(game, "ERROR\nInvalid character found in map!", 1);
	}
	else if (line[x] == 'E')
	{
		game->map.exit++;
		if (game->map.exit != 1)
			kill_game(game, "ERROR\nInvalid character found in map!", 1);
	}
	else if (line[x] == 'C')
		game->map.coins++;
	else if (line[x] == 'T')
		game->map.enemies++;
	else if (line[x] != '1' && line[x] != '0')
		kill_game(game, "ERROR\nInvalid character found in map!", 1);
	game->map.grid[y][x] = line[x];
}

// We now go through the map file again with Get_Next_Line to read and place 
// every map element in our 2D array. We go through each line, checking 
// every element with element_checker.
static void	placing_elements(t_game *game, char *argv)
{
	int		fd;
	int		y;
	int		x;
	char	*line;

	y = -1;
	x = -1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, "ERROR\nCouldn't open file!", 1);
	while (++y < game->map.row)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (++x < game->map.col)
			element_checker(game, line, y, x);
		x = -1;
		free (line);
	}
	line = NULL;
	close(fd);
}

// Now that we know the size of the map we can start creating the 2D array
// by mallocing enough space for every element in every line. We keep track
// of how many times we malloc'd in case a malloc fails and we need to free
// all mallocs before the failure. We then call the placing_elements 
// function to start placing all elements in the 2D array.
static void	loading_map_data(t_game *game, char *argv)
{
	int	y;

	y = 0;
	while (y < game->map.row)
	{
		game->map.grid[y] = malloc(game->map.col * sizeof(char));
		if (!game->map.grid)
			kill_game(game, "ERROR\nFailed to malloc map data!", 1);
		game->map.mallocs++;
		y++;
	}
	placing_elements(game, argv);
}

// Here we check how many rows and columns are in the map that we chose to
// load in. We do this by using Get_Next_Line. Every line that gets
// returned counts as a row. In every line we check the length until "\n"
// or EOF. If any line has more or less characters in it, it means the 
// map is not rectangular and will quit and give an error.
static void	rows_columns_check(t_game *game, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, "ERROR\nCouldn't open file!", 1);
	line = get_next_line(fd);
	if (!line)
		kill_game(game, "ERROR\nEmpty map file!", 1);
	game->map.row = 0;
	game->map.col = ft_linelen(line);
	free (line);
	while (++game->map.row)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_linelen(line) != game->map.col)
		{
			clear_gnl(line, fd);
			kill_game(game, "ERROR\nMap not rectangular!", 1);
		}
		free (line);
	}
	close(fd);
}

// The load_map function contains only 2 functions to keep the functions clear
// and organized. After the first function we check whether the map is big
// enough to to be even played before we start mallocing our 2D array for the
// map. We also malloc the amount of rows * sizeof(char *) to save lines in the 
// next function.
void	load_map(t_game *game, char *argv)
{
	rows_columns_check(game, argv);
	if (game->map.row < 3 || game->map.col < 3)
		kill_game(game, "ERROR\nMap is too small!", 1);
	else if (game->map.row * game->map.col < 15)
		kill_game(game, "ERROR\nMap is too small!", 1);
	game->map.grid = malloc(game->map.row * sizeof(char *));
	if (!game->map.grid)
		kill_game(game, "ERROR\nFailed to malloc map data!", 1);
	loading_map_data(game, argv);
}
