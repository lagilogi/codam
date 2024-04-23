/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:23:30 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 14:20:53 by wsonepou      ########   odam.nl         */
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

static void	child_process(char **paths, char *cmd, char **envp)
{
	int		i;
	char	**cmds;
	char	*cmd_path;

	i = 0;
	cmds = ft_split(cmd, ' ');
	if (cmds == NULL || cmds[0] == NULL || cmds[0][0] == '\0')
		kill_program(paths, cmd, errno);
	cmd_path = ft_pathjoin(paths[i], cmds[0]);
	while (cmd_path != NULL && access(cmd_path, F_OK | X_OK) == -1)
	{
		free(cmd_path);
		cmd_path = ft_pathjoin(paths[i], cmds[0]);
		i++;
	}
	if (cmd_path == NULL && access(cmd, F_OK | X_OK) == -1) // Testing if a cmd/program is found in current directory
	{
		free_command(cmds, &cmd_path);
		kill_program(paths, cmd, 127);
	}
	else
		execve(cmd_path, cmds, envp);
	kill_program(paths, cmd, errno);
}

pid_t	cmd_2(char **paths, char **argv, int *fds, char **envp)
{
	int			outfile;
	const pid_t	pid = fork();
	
	if (pid == -1)
		kill_program(paths, "Fork child 2", errno);
	if (pid == 0)
	{
		outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
		if (outfile == -1)
			kill_program(paths, argv[4], errno);
		if (dup2(fds[0], STDIN_FILENO) == -1)
			kill_program(paths, "Dup fds[0] cmd2", errno);
		if (dup2(outfile, STDOUT_FILENO) == -1)
			kill_program(paths, "Dup outfile cmd2", errno);
		close (fds[0]);
		close (fds[1]);
		close (outfile);
		child_process(paths, argv[3], envp);
	}
	close(fds[1]);
	return (pid);
}

void	cmd_1(char **paths, char **argv, int *fds, char **envp)
{
	int			infile;
	const pid_t	pid = fork();

	if (pid == -1)
		kill_program(paths, "Fork child 1", errno);
	if (pid == 0)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			kill_program(paths, argv[1], errno);
		if (dup2(infile, STDIN_FILENO) == -1)
			kill_program(paths, "Dup infile cmd1", errno);
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			kill_program(paths, "Dup fds[1] cmd1", errno);
		close (fds[0]);
		close (fds[1]);
		close (infile);
		child_process(paths, argv[2], envp);
	}
	close(fds[1]);
}
