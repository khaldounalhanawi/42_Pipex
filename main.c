/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:02:18 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/11 17:10:14 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_part(int *ctl, int *fd, char **argv, char **envp)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		multi_fdclose(fd[0], fd[1], ctl[0], ctl[1]);
		perror_exit("can't open file1");
	}
	if (dup2(file1, 0) == -1)
	{
		close(file1);
		multi_fdclose(fd[0], fd[1], ctl[0], ctl[1]);
		perror_exit("can't convert input to file1");
	}
	multi_fdclose(file1, fd[0], ctl[0], ctl[1]);
	if (dup2(fd[1], 1) == -1)
		closefd_perror(fd[1], "can't convert output to pipe");
	close(fd[1]);
	if (cmd_exe(argv[2], envp) != 0)
		error_exit("can't execute first command");
}

void	second_part(int *fd, char **argv, char **envp)
{
	int	file2;

	if (dup2(fd[0], 0) == -1)
	{
		close(fd[0]);
		perror_exit("can't convert input to pipe");
	}
	close(fd[0]);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		perror_exit("can't write file2");
	if (dup2(file2, 1) == -1)
	{
		close(file2);
		perror_exit("can't convert output to file2");
	}
	close(file2);
	if (cmd_exe(argv[3], envp) != 0)
		error_exit("can't execute second command");
}

int	second_fork(int *id2, int *ctl, int *fd)
{
	char	signal;

	*id2 = fork();
	if (*id2 == -1)
		perror_exit("Couldn't fork");
	if (*id2 == 0)
	{
		close(ctl[1]);
		close(fd[1]);
		if (read(ctl[0], &signal, 1) != 1 || signal != 'x')
		{
			multi_fdclose(fd[0], -1, ctl[0], -1);
			exit(EXIT_FAILURE);
		}
		close(ctl[0]);
		return (0);
	}
	return (-1);
}

void	waits(int id, int id2, int *ctl)
{
	int	status;

	waitpid(id, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		write(ctl[1], "x", 1);
	close(ctl[1]);
	waitpid(id2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	ctl[2];
	int	id;
	int	id2;

	checks(argc, envp);
	if (pipe(fd) == -1 || pipe(ctl) == -1)
		perror_exit("Couldn't create pipe");
	id2 = 0;
	id = fork();
	if (id == -1)
		perror_exit("Couldn't fork");
	if (id == 0)
		first_part(ctl, fd, argv, envp);
	else
	{
		if (second_fork(&id2, ctl, fd) == 0)
			second_part(fd, argv, envp);
	}
	multi_fdclose(fd[0], fd[1], ctl[0], -1);
	waits(id, id2, ctl);
}
