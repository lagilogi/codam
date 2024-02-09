/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coin_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:39:58 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/02/09 16:37:45 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coin	*ft_listlast(t_coin *node)
{
	t_coin	*tmp;

	tmp = node;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		else
			tmp = tmp->next;
	}
	return (tmp);
}

void	add_coin_to_list(t_game *game, int y, int x, int i)
{
	t_coin	*new;
	t_coin	*last;

	new = malloc(sizeof(t_coin));
	if (!new)
		kill_game(game, "ERROR: Malloc failed creating coin list!", 1);
	new->x = x * IMGW;
	new->y = y * IMGH;
	new->z = 0;
	new->instance = i;
	new->next = NULL;
	if (game->coin == NULL)
		game->coin = new;
	else
	{
		last = ft_listlast(game->coin);
		last->next = new;
	}
}
