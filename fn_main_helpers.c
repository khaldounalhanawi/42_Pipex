/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_main_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:48:19 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/11 17:10:15 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_exit(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	multi_fdclose(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 > -1)
		close(fd1);
	if (fd2 > -1)
		close(fd2);
	if (fd3 > -1)
		close(fd3);
	if (fd4 > -1)
		close(fd4);
}

void	checks(int argc, char **envp)
{
	if (argc != 5)
		error_exit("Incorrect number of arguments");
	if (!*envp)
		error_exit("No environment provided");
}

void	closefd_perror(int fd, char *str)
{
	close(fd);
	perror_exit(str);
}
