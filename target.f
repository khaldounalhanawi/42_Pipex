#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


int	main(int argc, char **argv, char **envp)
{
	int		file1;
	int		fd[2];
	int		id;

	if (argc != 5)
		return (-1); // check if error is correct
	if (pipe (fd) == -1)
		return (-2); // check error code
	id = fork ();
	if (id == -1)
		return (-3);
	file1 = open (argv[1], O_RDONLY);
	if ( file1 == -1)
		return (-4);
	if (id == 0)
		first ();
	else
		second ();
	return (0);
}
