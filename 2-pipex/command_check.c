/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_check.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/08 17:01:44 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/10 16:56:39 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_pathjoin(char const *s1, char const *s2)
{
	int		i;
	int		o;
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	o = ft_strlen(s1) + ft_strlen(s2);
	p = malloc((o + 2) * sizeof(char));
	if (!p)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	p[i] = '/';
	i++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

static char	*find_paths(t_info *info, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	if (envp[i] == NULL)
		kill_program(info, "ERROR: Couldn't find paths!", 1);
	return (NULL);
}

void	getting_paths(t_info *info, char **envp)
{
	char	*paths;

	paths = find_paths(info, envp);
	info->paths = ft_split(paths, ':');
	if (info->paths == NULL)
		kill_program(info, "ERROR: Couldn't split paths!", 1);
	
}





// forking(char *argv)
// {
// 	const int pid = fork();
	
// 	if (pid == 0)
// 		child_proc(argv)
// 	else
// 		parent()		
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	while (argc)
// 	{
// 		forking(argv[i]);

// 	}
// }