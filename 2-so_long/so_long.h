/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:21:26 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/09 19:08:12 by wsonepou      ########   odam.nl         */
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
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# define IMGW 80
# define IMGH 80
# define BPP 4

typedef	struct s_time
{
	double	passed;
	int		frames;
} t_time;

typedef struct s_txtr
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;
	mlx_texture_t	*enemy;
}	t_txtr;

typedef struct s_image
{
	mlx_image_t	*f;
	mlx_image_t	*w;
	mlx_image_t	*p;
	mlx_image_t	*c;
	mlx_image_t	*e;
	mlx_image_t	*t;
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

typedef struct s_enemy
{
	int				x;
	int				y;
	int				instance;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_map
{
	char	**grid;
	int		col;
	int		row;
	int		coins;
	int		exit;
	int		player;
	int		enemies;
	int		elements;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_image		img;
	t_map		map;
	t_player	player;
	t_coin		*coin;
	mlx_image_t	*mc;
	int			moves;
	int			win;
	t_enemy		*enemy;
	t_time		time;
}	t_game;

void	load_map(t_game *game, char *argv);
void	map_checker(t_game *game);
void	build_game(t_game *game);
void	add_coin_to_list(t_game *game, int y, int x, int i);
t_coin	*ft_listlast(t_coin *node);
void	run_game(t_game *game);
void	kill_game(t_game *game, char *message, int i);
void	kill_game_wrapper(void *param);
void	moves_count(t_game *game);
void	moves_text(t_game *game);
void	draw_enemies(t_game *game);
void	time_passage(void *param);
void	enemy_move(t_game *game);
void	lose(t_game *game);

#endif