# include "pipex.h"

void perror_exit(char *str)
{
	perror (str);
	exit (EXIT_FAILURE);
}

void error_exit(char *str)
{
	write (2, str, ft_strlen (str));
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}

void multi_fdclose (int fd1, int fd2, int fd3)
{
	if (fd1 > -1)
		close (fd1);
	if (fd2 > -1)
		close (fd2);
	if (fd3 > -1)
		close (fd3);
}

void first_part(int *fd,char **argv, char **envp)
{
	int	file1;
	
	file1 = open (argv[1], O_RDONLY);
	if ( file1 == -1)
	{
		multi_fdclose (fd[0], fd[1], -1);
		perror_exit ("can't open file1");
	}
	if (dup2 (file1, 0) == -1)
	{
		multi_fdclose (file1, fd[0], fd[1]);
		perror_exit ("can't convert input to file1");
	}
	multi_fdclose (file1, fd[0], -1);
	if (dup2 (fd[1], 1) == -1)
	{
		close (fd[1]);
		perror_exit ("can't convert output to pipe");
	}
	close (fd[1]);
	if (cmd_exe (argv[2], envp) != 0)
		perror_exit ("can't execute first command");
}

void second_part(int *fd,char **argv, char **envp)
{
	int	file2;
	
	close (fd[1]);
	if (dup2 (fd[0], 0) == -1)
	{
		close (fd [0]);
		perror_exit ("can't convert input to pipe");
	}
	close (fd[0]);
	file2 = open (argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ( file2 == -1)
	{
		perror_exit ("can't write file2");
	}
	if (dup2 (file2, 1) == -1)
	{
		close (file2);
		perror_exit ("can't convert output to file2");
	}
	close (file2);
	if (cmd_exe (argv[3], envp) != 0)
		perror_exit ("can't execute second command");
}

void checks (int argc, char **envp)
{
	if (argc != 5)
		error_exit ("Incorrect number of arguments");
	if (!*envp)
		error_exit ("No environment provided");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		id;
	int		id2;

	checks (argc, envp);
	if (pipe (fd) == -1)
		perror_exit ("Couldn't create pipe");
	id = fork ();
	if (id == -1)
		perror_exit ("Couldn't fork");
	id2 = 0;
	if (id == 0)
		first_part(fd, argv, envp);
	else
	{
		id2 = fork ();
		if (id2 == 0)
			second_part (fd, argv, envp);
	}
	multi_fdclose (fd[0], fd[1], -1);
	waitpid (id, NULL, 0);
	waitpid (id2, NULL, 0);
}


/*

  // parent waits for first child
    waitpid(pid1, &status1, 0);
    if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0) {
        // first child failed -> kill second child and exit with error
        kill(pid2, SIGKILL);
        waitpid(pid2, NULL, 0); // clean up second child
        fprintf(stderr, "First command failed, exiting\n");
        exit(EXIT_FAILURE);
    }

    // wait for second child normally if first succeeded
    waitpid(pid2, &status2, 0);

*/