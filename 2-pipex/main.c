/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:59:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/25 18:15:57 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_paths(char **envp)
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
		kill_program(NULL, "Couldn't find env paths", errno);
	return (NULL);
}

static char	**getting_paths(char **envp)
{
	char	*paths_str;
	char	**paths;

	paths_str = find_paths(envp);
	paths = ft_split(paths_str, ':');
	if (paths == NULL)
		kill_program(paths, "Getting paths", errno);
	return (paths);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	pid_t	pid;
	int		fds[2];
	int		status;

	paths = NULL;
	if (argc != 5)
		return (1);
	paths = getting_paths(envp);
	if (pipe(fds) == -1)
		kill_program(paths, "Pipe 1", errno);	
	cmd_1(paths, argv, fds, envp);
	pid = cmd_2(paths, argv, fds, envp);
	waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	if (WIFEXITED(status) == true)
		status = WEXITSTATUS(status);
	free_paths(paths);
	return (status);
}
