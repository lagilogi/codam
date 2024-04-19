#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


int	main(int argc, char **argv, char **envp)
{
	// Opening a file and sending it to first command and to write output of execve to pipe
	// step 1 - Opening the infile
	int infile = open("Text.txt", O_RDONLY);
	if (infile == -1)
		kill_program();

	// step 2 - Creating file descriptors for pipe and use pipe()
	int fds[2];
	if (pipe(fds) == -1)
		kill_program();


	// step 3 - Forkin' the process
	int pid = fork();
	if (pid == -1)
		kill_program();

	// step 4 - Child process --> Take the contents from the file as input, execute command and write output of command to pipe
	if (pid == 0)
	{
		dup2(infile, STDIN_FILENO);			// Duplicating infile file desciptor reference to stdin so execve read input from file instead of terminal
		close(infile);						// Close infile because it's not necessary
		dup2(fds[1], STDOUT_FILENO);		// Duplicating the write-end of the pipe to stdout, so execve outputs to the pipe
		execve("path", cmd_array[], envp);	// Running execve
		kill_child();						// If execve fails, we free everything and kill off the child
	}

	// step 5 - Parent process --> Closing file descriptors not needed
	if (pid > 0)
	{
		close(infile);
		close(fds[1]);
	}



	// Reading from the pipe and executing 2nd command, then write to the file
	// step 1 - 

}


// int fds[2]
// pipe(fds)

// fds[4, 5]


// parent
// 0(STDIN_F)			STDIN
// 1(STDOUT_F)			STDOUT
// 2(STDERR_F)			STDERR
// 3(infile)				text.txt
// 4(fds[0])				read-end pipe
// 5(fds[1])				write-end pipe

// child
// 0(STDIN_F)			text.txt
// 1(STDOUT_F)			STDOUT
// 2(STDERR_F)			STDERR
// 3(infile)				text.txt
// 4(fds[0])				read-end pipe
// 5(fds[1])				write-end pipe

// child 1
// dup2(infile, STDIN_F)
// dup2(fds[1], STDOUT_F)


// int outfile = open(text2.txt)

// child 2
// dup2(fds[0], STDIN_F)
// dup2(fds[1], STDOUT_F)


// child 3
// dup2(fds[0], STDIN_F)
// dup2(fds[1], STDOUT_F)

// dup(STDIN)