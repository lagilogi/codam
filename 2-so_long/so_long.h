/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:21:26 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/01/26 13:05:17 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <memory.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "libft/libft.h"


// Defines for width/height of window and images
# define IMG_W 80
# define IMG_H 80
# define BPP sizeof(int32_t)

// Defines error messages
# define FILE_ERROR	"ERROR: Couldn't open file!"
# define EMPTYMAP	"ERROR: Empty map!"
# define COLUMNERR	"ERROR: Uneven columns!"
# define MALLOCERR	"ERROR: Failed to malloc map data!"
# define PLAYERERR	"ERROR: Player amount error!"
# define EXITERR	"ERROR: Exit amount error!"
# define ELEMERROR	"ERROR: Invalid element found in map!"


// STRUCTS
// Struct for loaded textures
typedef struct s_image {
	mlx_image_t	*floor;
	mlx_image_t *wall;
	mlx_image_t *player;
	mlx_image_t *oil;
	mlx_image_t *exit;
}	t_image;

// Struct for the player --- PROBABLY DONT NEED
typedef struct s_player {
	int	x;
	int	y;
}	t_player;

// Struct for map data
typedef struct s_map {
	char	**grid;
	int		columns;
	int		rows;
	int		collectibles;
	int		exit;
	int		player;
}	t_map;

// Struct containing all game elements
typedef struct s_game {
	mlx_t		*mlx;
	t_image		image;
	t_map		map;
	t_player	player;
	int			moves;
}	t_game;


// FUNCTIONS
// Running the game, looping and key-hooking
void	run_game(t_game *game);
void	load_map(t_game *game, char *argv);
void	kill_game(t_game *game, char *error);
void	build_game(t_game *game);

#endif