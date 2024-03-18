/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 14:53:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/03/18 21:20:06 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_info(t_info *info)
{
	info->rot_a = 0;
	info->rev_rot_a = 0;
	info->rot_b = 0;
	info->rev_rot_b = 0;
	info->rot_a_b = 0;
	info->rev_rot_a_b = 0;
	info->min_moves = info->size_a + info->size_b;
}

void	set_info(int a, int b, t_info *info)
{
	// printf("a = %d / b = %d\n", a, b);  // For testing purposes
	if (a > info->size_a / 2)
		a = a - info->size_a;
	if (b > info->size_b / 2)
		b = b - info->size_b;
	if (a > 0)
		info->rot_a = a;
	else
		info->rev_rot_a = a * -1;
	if (b > 0)
		info->rot_b = b;
	else
		info->rev_rot_b = b * -1;
	while (info->rot_a > 0 && info->rot_b > 0)
	{
		info->rot_a_b++;
		info->rot_a--;
		info->rot_b--;
	}
	while (info->rev_rot_a > 0 && info->rev_rot_b > 0)
	{
		info->rev_rot_a_b++;
		info->rev_rot_a--;
		info->rev_rot_b--;
	}
	// if (info->rev_rot_a_b > 0 || info->rot_a_b > 0) // For testing purposes
	// 	printf("HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n"); // For testing purposes
}

int	check_moves(int a, int b, t_info *info)
{
	if (a > info->size_a)
		a = a - info->size_a;
	if (b > info->size_b)
		b = b - info->size_b;
    if (a >= 0 && b >= 0)
    {
      if (a >= b)
        return (b + (a - b));
      else
        return (a + (b - a));
    }
    else if (a < 0 && b < 0)
    {
      a = a * -1;
      b = b * -1;
      if (a >= b)
        return (b + (a - b));
      else
        return (a + (b - a));
    }
    else if (a < 0 && b >= 0)
        return ((a * -1) + b);
    return (a + (b * -1));
}

bool	smallest_check(t_stack *stackb, int num)
{
	while(stackb != NULL)
	{
		if (num > stackb->data)
			return (false);
		stackb = stackb->next;
	}
	return (true);
}

bool	biggest_check(t_stack *stacka, int num)
{
	while(stacka != NULL)
	{
		if (num < stacka->data)
			return (false);
		stacka = stacka->next;
	}
	return (true);
}