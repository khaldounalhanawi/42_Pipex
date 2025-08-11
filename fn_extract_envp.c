/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_extract_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:47:18 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/11 16:53:11 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**extract_envp(char **envp)
{
	char	*str;
	char	**arr;

	str = NULL;
	arr = NULL;
	while (*envp)
	{
		str = ft_strnstr(*envp, "PATH=", 5);
		if (str)
		{
			arr = ft_split(str + 5, ':');
			if (!arr)
				return (NULL);
			break ;
		}
		envp++;
	}
	return (arr);
}
