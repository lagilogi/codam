/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:59:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/23 17:23:25 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		kill_program(info, errno);
	return (NULL);
}

static void	getting_paths(t_info *info, char **envp)
{
	char	*paths;

	paths = find_paths(info, envp);
	info->paths = ft_split(paths, ':');
	if (info->paths == NULL)
		kill_program(info, errno);
}

static void	init_info(t_info *info, int argc, char **argv)
{
	info->paths = NULL;
	info->child_nr = 1;
	info->argc = argc;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		info->heredoc = true;
		info->cmds = argc - 4;
		info->limiter = argv[2];
		info->limiter_len = ft_strlen(info->limiter);
	}
	else
	{
		info->infile = open(argv[1], O_RDONLY);
		if (info->infile == -1)
			kill_program(info, errno);
		if (dup2(info->infile, STDERR_FILENO) == -1)
			kill_program(info, errno);
		close (info->infile);
		info->heredoc = false;
		info->cmds = argc - 3;
		info->limiter = NULL;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	int		status;

	if (argc < 5)
		return (1);
	init_info(&info, argc, argv);
	getting_paths(&info, envp);
	pid = creating_childs(&info, argv, envp);
	waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	if (WIFEXITED(status) == true)
		status = WEXITSTATUS(status);
	kill_program(&info, 0);
	return (0);
}

// FOR HERE_DOC
// 1. Check that argv[1] is here_doc
// 2. if True save argv[2] as the 'limiter'
// 3. Set int i to 3 as argv[3] will now be the first command
// 4. Set Get_Next_Line to read from the input with STDIN (0) file descriptor
// 5. Check if 'limiter' has been read to stop reading from here_doc
// 6. When limiter has been read, stop here_doc child process
// 7. Now pass that information to the pipe
// 8. Use the 'unlink' function to delete the file that was written to
