/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:21:26 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/02 13:18:23 by wsonepou      ########   odam.nl         */
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
# define FILE_ERROR		"ERROR: Couldn't open file!"
# define EMPTY_MAP		"ERROR: Empty map!"
# define COLUMN_ERROR	"ERROR: Uneven columns!"
# define MALLOC_ERROR	"ERROR: Failed to malloc map data!"
# define ELEM_ERROR		"ERROR: Incorrect Player, Coins or Exit amount!"
# define CHAR_ERROR		"ERROR: Invalid character found in map!"
# define SUCCESS		"Congrats! You Escaped!\nClosing game now.."


// STRUCTS
// Struct for loaded textures
typedef struct s_image {
	mlx_image_t	*floor;
	mlx_image_t *wall;
	mlx_image_t *player;
	mlx_image_t *coin;
	mlx_image_t *exit;
}	t_image;


// Struct for the player
typedef struct s_player {
	int	x;
	int	y;
}	t_player;


// Struct for Coins
typedef struct s_coin {
	int				x;
	int				y;
	int				z;
	int				instance;
	struct s_coin	*next;
}	t_coin;


// Struct for map data
typedef struct s_map {
	char	**grid;
	int		columns;
	int		rows;
	int		coins;
	int		exit;
	int		player;
	int		elements;
}	t_map;


// Struct containing all game elements
typedef struct s_game {
	mlx_t		*mlx;
	t_image		image;
	t_map		map;
	t_player	player;
	t_coin		*coin;
	int			moves;
}	t_game;


// FUNCTIONS
// Running the game, looping and key-hooking
void	load_map(t_game *game, char *argv);
void	map_checker(t_game *game);
void	build_game(t_game *game);
void	add_coin_to_list(t_game *game, int y, int x, int i);
void	run_game(t_game *game);
void	kill_game(t_game *game, char *message, int i);

#endif