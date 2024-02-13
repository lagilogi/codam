/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:51:24 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 17:44:23 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// I created a different strlen to end on '\n' as well '\0' as all lines, except
// for the last one contain a '\n'.
static int	ft_linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

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

// Now that we know the size of the map we can start creating the 2D array
// that will contain our map elements. We now go through the map file again
// with Get_Next_Line to read and place every map element in our 2D array.
// We do this by mallocing a char array for char * that we malloc'd before.
// We then go through each line, checking every element with element_checker.
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
		kill_game(game, "ERROR\nCouldn't open file!", 1);
	while (++y < game->map.row)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map.grid[y] = malloc(game->map.col * sizeof(char));
		if (!game->map.grid[y])
			kill_game(game, "ERROR\nFailed to malloc map data!", 1);
		while (++x < game->map.col)
			element_checker(game, line, y, x);
		x = -1;
		free (line);
	}
	close(fd);
}

// Here we check how many rows and columns are in the map that we chose to
// load in. We do this by using Get_Next_Line. Every line that gets
// returned counts as a row. In every line we check the length until "\n"
// or EOF. If any line has more or less characters in it, it means the 
// map is not rectangular and will quit and give an error. We also malloc
// the amount of rows * sizeof(char *) to save lines in the next function.
static void	rows_columns_check(t_game *game, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		kill_game(game, "ERROR\nCouldn't open file!", 1);
	line = get_next_line(fd);
	if (!line)
		kill_game(game, "ERROR\nEmpty map!", 1);
	game->map.row = 0;
	game->map.col = ft_linelen(line);
	free (line);
	while (++game->map.row)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_linelen(line) != game->map.col)
			kill_game(game, "ERROR\nUneven map!", 1);
		free (line);
	}
	close(fd);
	game->map.grid = malloc(game->map.row * sizeof(char *));
	if (!game->map.grid)
		kill_game(game, "ERROR\nFailed to malloc map data!", 1);
}

// The load_map function contains only 2 functions to keep the functions clear
// and organized.
void	load_map(t_game *game, char *argv)
{
	rows_columns_check(game, argv);
	loading_map_data(game, argv);
}
