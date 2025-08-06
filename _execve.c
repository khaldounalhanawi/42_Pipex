#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


int	main(int argc, char **argv)
{
	int			id;
	int			wstatus;
	int			status_code;
	extern char	**environ;
	char		*args[] = {"/bin/ls", "-l", NULL};

	wstatus = 0;
	status_code = 0;
	id = fork ();
	if (id == -1)
		return (-1);
	if (id == 0)
	{
		if (execve("/bin/ls", args, environ) == -1)
		{
			perror ("execve");
		}
	}
	else
	{
		wait (&wstatus);
		if (WIFEXITED (wstatus))
		{
			status_code = WEXITSTATUS (wstatus);
			if (status_code == 0)
				printf ("success\n");
			else
				printf ("failure\n");
		}
		printf ("done\n");
	}
	return (0);
}