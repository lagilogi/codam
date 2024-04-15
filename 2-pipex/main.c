/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:59:12 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/04/15 16:41:13 by wsonepou      ########   odam.nl         */
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
	info->infile = open(argv[1], O_RDONLY);
	if (info->infile == -1)
		kill_program(info, errno);
	info->outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (info->outfile == -1)
		kill_program(info, errno);
	argc++;

	info->limiter = argv[2]; // BONUS
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		i;
	// pid_t	pid; // Int or pid_t?
	// int		*fds[2];

	// if (argc < 5)
	// 	return (1);
	init_info(&info, argc, argv);
	getting_paths(&info, envp);
	// if (pipe(fds) == -1)
	// 	kill_program(&info, errno);
	i = 2;
	while (i < argc - 1)
	{
		creating_child(&info, argv[i], envp);
		i++;
	}
	// pid = waitpid();
	while (wait(NULL) != -1)
		continue ;
	kill_program(&info, 0);
	return (0);

}

// FOR PIPES
// 1. create an array int *fd[2], which is then populated with 2 unused file descriptors
// 	  by the pipe() function
// 2. Must be created before a process is forked so that both parent and child process
//    have the same pipe() fds in memory, but NOTE that they have their own seperate
//    file descriptor table






// FOR HERE_DOC
// 1. Check that argv[1] is here_doc
// 2. if True save argv[2] as the 'limiter'
// 3. Set int i to 3 as argv[3] will now be the first command
// 4. Create new file to write to from here_doc (with Get_Next_line)
// 5. Check if 'limiter' has been read to stop reading from here_doc
// 6. When limiter has been read, stop here_doc child process
// 7. Now pass that information to the pipe
// 8. Use the 'unlink' function to delete the file that was written to







// int	main(int argc, char **argv, char **envp)
// {
// 	t_info	info;

// 	// 1. Checking argument amount
// 	if (argc < 5)
// 		return (1);

// 	// 2. Opening files
// 	info.fd_0 = open(argv[1], O_RDONLY); // IN or OUTPUT?
// 	info.fd_1 = open("file2.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);

// 	// 3. Parsing commands
// 	parsing_command(&info, argc, argv);
// 	checking_parsing(&info);




// 	kill_program(&info, "Ended program succesfully!", 1);
// 	return (0);
// }








// int		main(int argc, char **argv)
// {
// 	// int	id = fork(); // Forking basically creates a duplicate of a program and runs both the "main" program and the "duplicate" program at the same time
// 	// if (id == 0) // Child process always has process ID 0
// 	// 	printf("This is the child and has id %d\n", id);
// 	// else		// Parent process is never ID 0
// 	// 	printf("This is the parent with id %d\n", id);



// 	// int fd[2]; // TRYOUT 2
// 	// if (pipe(fd) == -1)
// 	// {
// 	// 	printf("Error occured with opening Pipe\n");
// 	// 	return (1);
// 	// }
// 	// int id = fork();
// 	// if (id == 0)
// 	// {
// 	// 	close(fd[0]);
// 	// 	int x;
// 	// 	printf("input a number: ");
// 	// 	scanf("%d", &x);
// 	// 	if (write(fd[1], &x, sizeof(int)) == -1)
// 	// 		return (1);
// 	// 	close(fd[1]);
// 	// }
// 	// else
// 	// {
// 	// 	close(fd[1]);
// 	// 	int y;
// 	// 	if (read(fd[0], &y, sizeof(int)) == -1)
// 	// 		return (1);
// 	// 	close(fd[0]);
// 	// 	printf("\nGot from child process %d\n\n", y);
// 	// 	wait(NULL);
// 	// }



// 	// int fd[2]; // TRYOUT 3
// 	// pipe(fd);
// 	// int pid = fork();
// 	// if (pid == -1)
// 	// 	return (1);
// 	// if (pid == 0) // Child process
// 	// {
// 	// 	close(fd[0]);
// 	// 	int x = 5;
// 	// 	if (write(fd[1], &x, sizeof(int)) == -1)
// 	// 		return (1);
// 	// 	close(fd[1]);
// 	// }
// 	// else
// 	// {
// 	// 	close(fd[1]);
// 	// 	int y;
// 	// 	if (read(fd[0], &y, sizeof(int)) == -1)
// 	// 		return (1);
// 	// 	printf("Got nmbr: %d\n", y);
// 	// 	close(fd[0]);
// 	// }



// 	// int fd[2]; // TRYOUT 4
// 	// pipe(fd);
// 	// int pid = fork();
// 	// if (pid == 0)
// 	// {
// 	// 	close(fd[0]);
// 	// 	char x[] = "Writing from child";
// 	// 	write(fd[1], &x, 19);
// 	// 	close(fd[1]);
// 	// }
// 	// else
// 	// {
// 	// 	char y[19];
// 	// 	close(fd[1]);
// 	// 	read(fd[0], &y, 19);
// 	// 	printf("In parent, writing the following message coming from child: \"%s\".\n", y);
// 	// 	close(fd[0]);
// 	// 	wait(NULL);
// 	// }



// 	int fd_infile = open("file1.txt", O_RDONLY); // TRYOUT 5
// 	// int fd_infile = open(argv[1], O_RDONLY); // TRYOUT 5
// 	int fd_outfile = open("file2.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
// 	// int fd_outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);

	// argc = 0;
	// int fd[2];
	// int fd_infile_dup = dup2(fd_infile, fd[1]);
	// int fd_outfile_dup = dup2(fd_outfile, fd[0]);
	// pipe(fd);
	// int pid = fork();
	// int og_stdin = dup(STDIN_FILENO); // 0
	// int og_stdout = dup(STDOUT_FILENO);// 1

	// dup2(fd, STDIN_FILENO); // 0
	// close(fd);
	// dup2(STDIN_FILENO, og_stdin); // 0
	

	// if (pid == 0)
	// {
	// 	close(fd[0]);
	// 	close(fd_outfile);

	// 	int buffer_size = 10;
	// 	char buffer[buffer_size];
	// 	int bytes_read = 1;

	// 	while (bytes_read != 0)
	// 	{
	// 		bytes_read = read(fd_infile, &buffer, buffer_size);
	// 		write(fd[1], &buffer, bytes_read);
	// 	}

	// 	close(fd[1]);
	// 	close(fd_infile);
	// }
	// else
	// {
	// 	close(fd[1]);
	// 	close(fd_infile);

	// 	int buffer_size = 10;
	// 	char buffer[buffer_size];
	// 	int bytes_read = 1;

	// 	while (bytes_read != 0)
	// 	{
	// 		bytes_read = read(fd[0], buffer, buffer_size);
	// 		write(fd_outfile, &buffer, bytes_read);
	// 	}

	// 	close(fd[0]);
	// 	close(fd_outfile);
	// }
	// close(0);
	// close(1);

// 	argv = NULL;
// 	return 0;
// }



// printf("here\n");
// ft_printf(char *c, ...);

// ft_printf_fd(int fd, char *c, ...);
// {
// 	write (fd)
// }

// ptr hello
// ptr world
// write(2, ptr, strlen(ptr));
// write(2, "\n", 1);

// write(2, ptr2, strlen(ptr2));

