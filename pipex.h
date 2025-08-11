/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:48:00 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/11 17:09:17 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**extract_envp(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
int		cmd_exe(char *cmd, char **envp);
char	*ft_strrchr(const char *s, int c);
void	checks(int argc, char **envp);
void	multi_fdclose(int fd1, int fd2, int fd3, int fd4);
void	error_exit(char *str);
void	perror_exit(char *str);
void	closefd_perror(int fd, char *str);

#endif
