/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/18 13:55:11 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/09 19:08:04 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	win(t_game *game)
{
	mlx_image_t	*win;
	int			x;
	int			y;

	x = (game->mlx->width / 2) - (IMGW * 1.85);
	y = game->mlx->height / 2.5;
	game->win = 1;
	game->img.p->instances[0].z = -1000;
	win = mlx_put_string(game->mlx, "You Escaped!", x, y);
	ft_printf("Congrats! You escaped!\nPress Esc to exit the game..\n");
	if (win == NULL)
		return ;
	if (!mlx_resize_image(win, win->width * 2.5, win->height * 2.5))
		return ;
}

void	lose(t_game *game)
{
	mlx_image_t	*lose;
	int			x;
	int			y;

	x = (game->mlx->width / 2) - (IMGW * 1.85);
	y = game->mlx->height / 2.5;
	game->win = 1;
	game->img.p->instances[0].z = -1000;
	lose = mlx_put_string(game->mlx, "Awwh, You Died!", x, y);
	ft_printf("You died!\nPress Esc to exit the game..\n");
	if (lose == NULL)
		return ;
	if (!mlx_resize_image(lose, lose->width * 2.5, lose->height * 2.5))
		return ;
}

static void	coin_remover(t_game *game, int y, int x)
{
	int		y_axis;
	int		x_axis;
	int		i;
	t_coin	*tmp;

	y_axis = y * IMGH;
	x_axis = x * IMGW;
	tmp = game->coin;
	while (tmp != NULL)
	{
		if (tmp->y == y_axis && tmp->x == x_axis && tmp->z != -1000)
		{
			i = tmp->instance;
			game->img.c->instances[i].z = -1000;
			tmp->z = -1000;
			break ;
		}
		else
			tmp = tmp->next;
	}
	game->map.coins--;
	game->map.grid[y][x] = '0';
	ft_printf("You got a coin! You have %d coins left!\n", game->map.coins);
}

static int	tile_check(t_game *game, int y_axis, int x_axis)
{
	int	y;
	int	x;

	y = game->player.y + y_axis;
	x = game->player.x + x_axis;
	if (game->map.grid[y][x] != '1')
	{
		if (game->map.grid[y][x] == 'C')
			coin_remover(game, y, x);
		else if (game->map.grid[y][x] == 'T')
			lose(game);		
		else if (game->map.grid[y][x] == 'E')
		{
			if (game->map.coins == 0)
				win(game);
		}
		game->player.y = y;
		game->player.x = x;
		return (1);
	}
	else
		return (ft_printf("You can't move into the wall, dummy!\n"), 0);
}

void	time_passage(void *param)
{
	t_game	*game;
	int		y;
	int		x;

	game = param;
	y = game->player.y;
	x = game->player.x;
	game->time.passed = mlx_get_time();
	game->time.frames = game->time.passed / 0.01;
	if (game->time.frames % 50 == 0 && game->win == 0)
		enemy_move(game);
}

static void	movement(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		y;
	int		x;

	game = param;
	y = game->player.y;
	x = game->player.x;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		kill_game(game, "Closing Game!", 0);
	else if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (game->win == 0)
		{
			if (keydata.key == MLX_KEY_W && tile_check(game, -1, 0) == 1)
				game->img.p->instances[0].y -= IMGH;
			else if (keydata.key == MLX_KEY_S && tile_check(game, 1, 0) == 1)
				game->img.p->instances[0].y += IMGH;
			else if (keydata.key == MLX_KEY_A && tile_check(game, 0, -1) == 1)
				game->img.p->instances[0].x -= IMGW;
			else if (keydata.key == MLX_KEY_D && tile_check(game, 0, 1) == 1)
				game->img.p->instances[0].x += IMGW;
			if (x != game->player.x || y != game->player.y)
				moves_count(game);
		}
	}
}

void	run_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &time_passage, game);
	mlx_key_hook(game->mlx, &movement, game);
	mlx_close_hook(game->mlx, &kill_game_wrapper, game);
	mlx_loop(game->mlx);
}


