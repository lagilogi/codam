
#include "pipex.h"

static void	checking_parsing(t_info *info) // CHECKING PARSING
{
	int i = 0;
	int o = 0;
	t_cmds	*tmp;

	tmp = info->cmds;
	while (tmp != NULL)
	{
		while (tmp->str[i] != NULL)
		{
			printf("CMD %d-%d: %s\n", o, i, tmp->str[i]);
			i++;
		}
		tmp = tmp->next;
		o++;
		i = 0;
	}
}


int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	// 1. Checking argument amount
	if (argc < 5)
		return (1);

	// 2. Opening files
	info.fd_0 = open(argv[1], O_RDONLY); // IN or OUTPUT?
	info.fd_1 = open(argv[4], O_RDONLY); // IN or OUTPUT?

	// 3. Parsing commands
	parsing_command(&info, argc, argv);
	checking_parsing(&info);



	char *str[] = {"ls", NULL}; // TESTING EXECVE FUNCTION
	execve("/bin/ls", str, envp); // TESTING EXECVE FUNCTION



	// 4. Creating pipe

	// 5. Forking

	// 6. Executing command 1 on file 1

	// 7. Piping

	// 9. Executing command 2 on that created information

	// 10. Writing that information into file 2

	// 11. Error handling

	kill_program(&info, "Ended program succesfully!", 1);
	return (0);
}


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
// }

