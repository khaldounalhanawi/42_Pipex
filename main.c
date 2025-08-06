# include "pipex.h"

int	cmd_exe(char *cmd, char **envp);


int	main(int argc, char **argv, char **envp)
{
	int		file1;
	int		file2;
	int		fd[2];
	int		id;

	if (argc != 5)
		return (-1); // check if error is correct

	// pipe
	if (pipe (fd) == -1)
		return (-2); // check error code

	id = fork ();
	if (id == -1)
		return (-3);

	// open the file 1
	file1 = open (argv[1], O_RDONLY);
	if ( file1 == -1)
		return (-4);

	//child:
	if (id == 0)
	{
		// make stdin the file
		if (dup2 (file1, 0) == -1)
			return (-5); // check error value

		close (file1);
		close (fd[0]);

		// make stdout the pipe
		if (dup2 (fd[1], 1) == -1)
			return (-6); // check error value
		
		close (fd[1]);
		
		// execute the command 1
		cmd_exe (argv[2], envp);
	}

	//main:
	else
	{
		close (fd[1]);
		close (file1);
		// get from pipe
		if (dup2 (fd[0], 0) == -1)
			return (-7); // check error value

		close (fd[0]);

		file2 = open (argv[5], O_RDONLY);
		if ( file2 == -1)
			return (-8);
		
		// make stdout the file
		if (dup2 (file2, 1) == -1)
			return (-6); // check error value

		close (file2);

		// execute the command 2
		cmd_exe (argv[3], envp);

		wait (NULL);
	}
	return (0);
}

int	cmd_exe(char *cmd, char **envp)
{
	char	**arr;

	arr = ft_split (cmd);


	// "ls -l -f"
	
	// seperate the words
	// get the first one to be command 
	// argv = cmd
	// envp = envp
	// extract address from env...
}