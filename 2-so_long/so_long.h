/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:21:26 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/05 18:14:30 by wsonepou      ########   odam.nl         */
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
# define IMGW 80
# define IMGH 80
# define BPP 4

typedef struct s_txtr
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;
}	t_txtr;

typedef struct s_image
{
	mlx_image_t	*f;
	mlx_image_t	*w;
	mlx_image_t	*p;
	mlx_image_t	*c;
	mlx_image_t	*e;
}	t_image;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_coin
{
	int				x;
	int				y;
	int				z;
	int				instance;
	struct s_coin	*next;
}	t_coin;

typedef struct s_map
{
	char	**grid;
	int		col;
	int		row;
	int		coins;
	int		exit;
	int		player;
	int		elements;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_image		img;
	t_map		map;
	t_player	player;
	t_coin		*coin;
	int			moves;

}	t_game;

void	load_map(t_game *game, char *argv);
void	map_checker(t_game *game);
void	build_game(t_game *game);
void	add_coin_to_list(t_game *game, int y, int x, int i);
void	run_game(t_game *game);
void	kill_game(t_game *game, char *message, int i);
void	put_string_to_screen(t_game *game);

#endif