
#include "pipex.h"

int	main(int argc, char **argv)
{
	// int	fd_1;
	// int	fd_2;

	// if (argc < 5 || argc > 5)
	// 	return (1);
	// fd_1 = open(argv[1], O_RDONLY);
	// fd_2 = open(argv[4], O_RDONLY);

	int	id = fork(); // Forking basically creates a duplicate of a program and runs both the "main" program and the "duplicate" program at the same time
	if (id == 0) // Child process always has process ID 0
		printf("This is the child and has id %d\n", id);
	else		// Parent process is never ID 0
		printf("This is the parent with id %d\n", id);


	int	id = fork();


	return (0);
}
