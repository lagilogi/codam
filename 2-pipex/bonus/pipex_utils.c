/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 14:36:21 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 14:23:36 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doccer()
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL) // str != NULL && something else
	{
		free (str);
		str = get_next_line(0);
	}
}