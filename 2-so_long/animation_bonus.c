/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 14:08:19 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/13 19:06:13 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Here we switch between the 2 different enemy frames when a certain amount has
// passed. When a certain amount of time has passed we swap the y values of each
// frame so that one of the frames becomes visible and the other is moved out of
// sight. We set the y value of the one out of sight to -1000, because when
// moving the character down, would sometimes show the out-of-bounds frame
// running back in from the top. -1000 is a very safe distance away to prevent
// this from happening
void	player_animation(t_game *game)
{
	if (game->player.frame == 0)
	{
		game->img.p->instances[0].y = -1000;
		game->img.p2->instances[0].y = game->player.y * IMGH;
		game->player.frame = 1;
	}
	else if (game->player.frame == 1)
	{
		game->img.p->instances[0].y = game->player.y * IMGH;
		game->img.p2->instances[0].y = -1000;
		game->player.frame = 0;
	}
}

// Here we switch between the 2 different enemy frames when a certain amount has
// passed. When a certain amount of time has passed we swap the y values of each
// frame so that one of the frames becomes visible and the other is moved out of
// sight.
void	enemy_animation(t_game *game)
{
	int		i;
	int		y;

	i = 0;
	while (i < game->map.enemies)
	{
		if (game->img.t->instances[i].y > 0)
			y = game->img.t->instances[i].y;
		else
			y = game->img.t2->instances[i].y;
		if (game->enemy_frame == 0)
		{
			game->img.t->instances[i].y = -1000;
			game->img.t2->instances[i].y = y;
			game->enemy_frame = 1;
		}
		else if (game->enemy_frame == 1)
		{
			game->img.t->instances[i].y = y;
			game->img.t2->instances[i].y = -1000;
			game->enemy_frame = 0;
		}
		i++;
	}
}
