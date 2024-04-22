/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:59:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/22 19:22:27 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static int	init_info(t_info *info, int argc, char **argv)
{
	int	i;

	info->paths = NULL;
	info->outfile = NULL;
	info->child_nr = 1;
	info->argc = argc;
	if (ft_strncmp(argv[1], "here_doc", 9) ==  0) // BONUS
	{
		info->heredoc = true;		// BONUS
		info->infile == NULL;		// BONUS
		info->cmds = argc - 4;		// BONUS
		info->limiter = argv[2];	// BONUS
		info->limiter_len = ft_strlen(info->limiter); // BONUS
		i = 3;						// BONUS
	}
	else
	{
		info->infile = open(argv[1], O_RDONLY);
		if (info->infile == -1)
			kill_program(info, errno);
		dup2(info->infile, STDERR_FILENO);
		close (info->infile);
		info->heredoc = false;
		info->infile = argv[1];
		info->cmds = argc - 3;
		info->limiter = NULL;
		i = 2;
	}
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	int		i;
	int		fds[2];
	int		*status;

	if (argc < 5)
		return (1);
	i = init_info(&info, argc, argv);
	getting_paths(&info, envp);
	while (i < argc - 1)
	{
		if (i <= argc - 2)
			if (pipe(fds) == -1)
				kill_program(&info, errno);
		creating_child(&info, argv[i], fds, envp);
		i++;
	}
	pid = last_child(&info, argv, fds, envp);
	waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
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


