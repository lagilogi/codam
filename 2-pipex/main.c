/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:59:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/26 16:52:35 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	getting_paths(t_info *info, char **envp)
{
	int		i;
	char	*paths;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (envp[i] == NULL)
		kill_program(info, "envp", 1);
	info->paths = ft_split(paths, ':');
	if (info->paths == NULL)
		kill_program(info, "paths", errno);
}

static void	init_info(t_info *info, int argc, char **argv)
{
	info->paths = NULL;
	info->outfile = argv[argc - 1];
	info->infile = argv[1];
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	pid_t	wpid;
	int		status;

	if (argc != 5)
		return (1);
	init_info(&info, argc, argv);
	getting_paths(&info, envp);
	pid = creating_children(&info, argv, envp);
	wpid = waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	if (wpid == -1)
		kill_program(&info, "wpid", errno);
	closing_fds(info.fds);
	if (info.paths != NULL)
		free_paths(&info);
	if (WIFEXITED(status) == true)
		return (WEXITSTATUS(status));
	return (0);
}
