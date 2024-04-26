/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:23:30 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/26 17:18:32 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_info *info, char *cmd, char **envp)
{
	int		i;
	char	**cmds;
	char	*cmd_path;

	i = 0;
	cmds = ft_split(cmd, ' ');
	if (cmds == NULL || cmds[0] == NULL || cmds[0][0] == '\0')
	{
		free_command(cmds, NULL);
		kill_program(info, cmd, errno);
	}
	cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
	while (cmd_path != NULL && access(cmd_path, F_OK | X_OK) == -1)
	{
		free(cmd_path);
		cmd_path = ft_pathjoin(info->paths[i++], cmds[0]);
	}
	if (cmd_path == NULL && access(cmd, F_OK | X_OK) == -1)
	{
		free_command(cmds, &cmd_path);
		kill_program(info, cmd, 127);
	}
	else
		execve(cmd_path, cmds, envp);
	kill_program(info, cmd, errno);
}

static pid_t	last_child(t_info *info, char *argv, char **envp)
{
	const pid_t	pid = fork();
	int			outfile;

	if (pid == -1)
		kill_program(info, "last child fork", errno);
	if (pid == 0)
	{
		if (info->heredoc == true)
			outfile = open(info->outfile, O_CREAT | O_APPEND | O_WRONLY, 0777);
		else
			outfile = open(info->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0777);
		if (outfile == -1)
			kill_program(info, "outfile", EXIT_FAILURE);
		if (dup2(outfile, STDOUT_FILENO) == -1)
			kill_program(info, "last child dup2 outfile", errno);
		if (close(outfile) == -1)
			perror("outfile");
		exec_cmd(info, argv, envp);
	}
	close(STDIN_FILENO);
	return (pid);
}

static void	child(t_info *info, char *argv, char **envp)
{
	const pid_t	pid = fork();

	if (pid == -1)
		kill_program(info, "child fork", errno);
	if (pid == 0)
	{
		setting_io(info);
		exec_cmd(info, argv, envp);
	}
	if (dup2(info->fds[0], STDIN_FILENO) == -1)
		kill_program(info, "child dup2 fds[0]", errno);
	closing_fds(info->fds);
}

void	ft_heredoc(t_info *info)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (strncmp(str, info->limiter, info->limiter_len) == 0
			&& str[info->limiter_len] == '\n')
		{
			free(str);
			break ;
		}
		write(info->fds[1], str, ft_strlen(str));
		free (str);
	}
	if (dup2(info->fds[0], STDIN_FILENO) == -1)
		kill_program(info, "child dup2 fds[0]", errno);
	closing_fds(info->fds);
}

pid_t	creating_children(t_info *info, char **argv, char **envp)
{
	int		i;
	pid_t	pid;

	if (info->heredoc == false)
		i = 2;
	else
		i = 3;
	while (i < info->argc - 2)
	{
		if (pipe(info->fds) == -1)
			kill_program(info, "pipe", errno);
		if (info->current_cmd == 1 && info->heredoc == true)
		{
			ft_heredoc(info);
			if (pipe(info->fds) == -1)
				kill_program(info, "pipe heredoc", errno);
		}
		child(info, argv[i], envp);
		i++;
		info->current_cmd++;
	}
	pid = last_child(info, argv[i], envp);
	closing_fds(info->fds);
	return (pid);
}
