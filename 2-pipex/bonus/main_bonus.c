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

#include "pipex_bonus.h"

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
	info->argc = argc;
	info->current_cmd = 1;
	info->outfile = argv[argc - 1];
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		info->heredoc = true;
		info->cmds = argc - 4;
		info->limiter = argv[2];
		info->limiter_len = ft_strlen(info->limiter);
	}
	else
	{
		info->infile = argv[1];
		info->cmds = argc - 3;
		info->heredoc = false;
		info->limiter = NULL;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	pid_t	wpid;
	int		status;

	if (argc < 5)
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
	return (WEXITSTATUS(status));
}
