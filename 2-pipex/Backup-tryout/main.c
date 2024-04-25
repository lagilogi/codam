/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:59:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/25 18:55:13 by wsonepou      ########   odam.nl         */
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
	if (WIFEXITED(status) == true)
		status = WEXITSTATUS(status);
	// free_paths(&info);
	// exit(status);
	kill_program(&info, NULL, status);
	return (status);
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
