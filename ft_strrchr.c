/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:50:24 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/05/20 15:50:47 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*start;

	ch = (char) c;
	start = s;
	while (*s)
		s++;
	if (ch == '\0')
		return ((char *)s);
	while (s != start)
	{
		if (*s == ch)
			return ((char *)s);
		s--;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}
/*

#include <stdio.h>
#include <string.h>

int main()
{
	char txt[] = "hakldkoakun";
	// char txt[] = {'k', 'h','a', '\0', 'a'};
	char c = 'k';

	printf("my :      %s\n", ft_strrchr(txt,c));
	printf("default : %s\n", strrchr(txt,c));



}*/
