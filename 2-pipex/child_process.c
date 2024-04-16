/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:23:30 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/16 18:59:19 by wsonepou      ########   odam.nl         */
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

void	creating_child(t_info *info, char *argv, int *fds, char **envp)
{
	const pid_t	pid = fork();

	if (pid == -1)
		kill_program(info, errno);
	if (pid == 0)
	{
		close(fds[0]);
		if (info->child_nr == info->cmds)
		{
			info->outfile = open(++argv, O_CREAT | O_TRUNC | O_WRONLY, 0777); // argv klopt niet
			dup2(info->outfile, STDOUT_FILENO);
		}
		else
			dup2(fds[1], STDOUT_FILENO); // To write to the pipe with 'STDOUT'
		close(fds[1]);
		
		child_process(info, argv, envp);
	}
	else if (pid > 0) // Parent
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	info->child_nr++;
}
