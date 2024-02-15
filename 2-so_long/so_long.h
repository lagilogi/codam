/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:21:26 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/15 12:54:53 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# define IMGW 80
# define IMGH 80
# define BPP 4

typedef struct s_time
{
	double	passed;
	double	delta_enemy_move;
	double	delta_animation;
}	t_time;

typedef struct s_txtr
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*player2;
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit2;
	mlx_texture_t	*enemy;
	mlx_texture_t	*enemy2;
}	t_txtr;

typedef struct s_image
{
	mlx_image_t	*f;
	mlx_image_t	*w;
	mlx_image_t	*p;
	mlx_image_t	*p2;
	mlx_image_t	*c;
	mlx_image_t	*e;
	mlx_image_t	*e2;
	mlx_image_t	*t;
	mlx_image_t	*t2;
}	t_image;

typedef struct s_player
{
	int	x;
	int	y;
	int	frame;
}	t_player;

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
	int		mallocs;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_image		img;
	t_map		map;
	t_player	player;
	mlx_image_t	*mc;
	int			moves;
	int			win;
	t_time		time;
	t_txtr		txtr;
	int			enemy_frame;
}	t_game;

void	load_map(t_game *game, char *argv);
int		ft_linelen(char *line);
void	map_checker(t_game *game);
void	build_game(t_game *game);
void	run_game(t_game *game);
void	movement(mlx_key_data_t keydata, void *param);
int		tile_check(t_game *game, int y_axis, int x_axis);
void	win(t_game *game);
void	lose(t_game *game);
void	kill_game(t_game *game, char *message, int i);
void	kill_game_wrapper(void *param);
void	moves_count(t_game *game);
void	moves_text(t_game *game);
void	draw_enemies(t_game *game, mlx_t *mlx);
void	enemy_move(t_game *game);
void	enemy_animation(t_game *game);
void	player_animation(t_game *game);
void	win_animation(t_game *game);

#endif