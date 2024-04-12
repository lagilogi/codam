/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_process.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:23:30 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/12 18:54:42 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_command(char **cmds, char **cmd_path)
{
	if (*cmd_path != NULL)
		free(cmd_path);
	free(cmds[0]);
	if (cmds[1] != NULL)
		free(cmds[1]);
	free(cmds);
}

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
	if (cmd == NULL)
		kill_program(info, errno);
	else if (cmds[0][0] == '.' || cmds[0][0] == '/')
		execve(cmds[0], cmds, envp);
	cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
	while (cmd_path != NULL && access(cmd_path, F_OK | X_OK) == -1)
	{
		free(cmd_path);
		cmd_path = ft_pathjoin(info->paths[i], cmds[0]);
		i++;
	}
	if (cmd_path == NULL)
	{
		free_command(cmds, &cmd_path);
		kill_program(info, errno);
	}
	else
		execve(cmd_path, cmds, envp);
	kill_program(info, errno);
}

void	creating_child(t_info *info, char *argv, char **envp)
{
	const int	pid = fork();

	if (pid == -1)
		kill_program(info, errno);
	if (pid == 0)
		child_process(info, argv, envp);
}
