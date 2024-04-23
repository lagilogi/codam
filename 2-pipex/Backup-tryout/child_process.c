/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:23:30 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 17:45:48 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



static void	child_process(t_info *info, char *cmd, char **envp)
{
	int		i;
	char	**cmds;
	char	*cmd_path;

	i = 0;
	cmds = ft_split(cmd, ' ');
	if (cmds == NULL || cmds[0] == NULL)
		kill_program(info, errno);
	cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
	while (cmd_path != NULL && access(cmd_path, F_OK | X_OK) == -1)
	{
		free(cmd_path);
		cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
		i++;
	}
	if (cmd_path == NULL && !access(cmd, F_OK | X_OK))
		free_command(cmds, &cmd_path);
	else
		execve(cmd_path, cmds, envp);
	kill_program(info, errno);
}

static pid_t	last_child(t_info *info, char **argv, char **envp)
{
	int			open_flags;
	const pid_t	pid = fork();

	if (pid == -1)
		kill_program(info, errno);
	else if (pid == 0)
	{
		if (info->heredoc == true)
			open_flags = O_CREAT | O_APPEND | O_WRONLY;
		else
			open_flags = O_CREAT | O_TRUNC | O_WRONLY;
		info->outfile = open(argv[info->argc - 1], open_flags, 0777);
		if (info->outfile == -1)
			kill_program(info, errno);
		if (dup2(info->outfile, STDOUT_FILENO) == -1)
			kill_program(info, errno);
		close(info->outfile);
		child_process(info, argv[info->argc - 2], envp);
	}
	return (pid);
}

static void	mid_child(t_info *info, char *argv, int *fds, char **envp)
{
	const pid_t	pid = fork();

	if (pid == -1)
		kill_program(info, errno);
	else if (pid == 0)
	{
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			kill_program(info, errno);
		closing_fds(fds);
		child_process(info, argv, envp);
	}
	if (dup2(fds[0], STDIN_FILENO))
	{
		closing_fds(fds);
		kill_program(info, errno);
	}
}

static void	first_child(t_info *info, char **argv, int *fds, char **envp)
{
	const pid_t	pid = fork();
	int			i;

	if (pipe(fds) == -1)
		kill_program(info, errno);
	if (pid == -1)
		kill_program(info, errno);
	else if (pid == 0)
	{
		if (info->heredoc == true)
			i = 3;
		else
		{
			info->infile = open(argv[1], O_RDONLY);
			if (info->infile == -1)
				kill_program(info, errno);
			if (dup2(info->infile, STDIN_FILENO) == -1)
				kill_program(info, errno);
			i = 2;
		}
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			kill_program(info, errno);
		closing_fds(fds);
		child_process(info, argv[i], envp);
	}
	closing_fds(fds);
}

pid_t	creating_childs(t_info *info, char **argv, char **envp)
{
	int		i;
	int		fds[2];
	pid_t	pid;
	
	if (info->heredoc == true)
		i = 3;
	else
		i = 2;
	while (i < info->argc - 2)
	{
		if (pipe(fds) == -1)
			kill_program(info, errno);
		if (info->child_nr == 1)
			first_child(info, argv, fds, envp);
		else
			mid_child(info, argv[i], fds, envp);
		i++;
		info->child_nr++;
	}
	pid = last_child(info, argv, envp);
	return (pid);
}

