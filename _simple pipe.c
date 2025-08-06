#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


int	main(int argc, char **argv)
{
	int	id1;
	int	fd[2];
	char	*temp;

	// if (argc != 5)
	// {
	// 	write (1,"incorrect number of arguments\n", 30);
	// 	return (-1);
	// }
	temp = malloc (sizeof (char) *5);
	if (pipe (fd) == -1)
		return (-2);
	
	id1 = fork ();
	if (id1 == -1)
		return (-1);

	if (id1 == 0)
	{
		close (fd[0]);
		write (fd[1], "koko", 4);
		close (fd[1]);
	}
	else
	{
		close (fd [1]);
		read (fd[0], temp, 5);
		close (fd [0]);
		temp [4] = '\0';
		printf ("%s", temp);
		wait (NULL);
	}
	free (temp);


}