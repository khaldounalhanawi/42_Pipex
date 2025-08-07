/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:40:46 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/07 17:53:56 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		len_total;
	char	*p;
	char	*original;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	len_total = len1 + len2 + 1;
	p = malloc (len_total * sizeof(char));
	if (!p)
		return (NULL);
	original = p;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (original);
}
/*
#include <stdio.h>

int main()
{
	char s1[] = "Hey";
	char s2[] = "there!";

	printf("%s\n", ft_strjoin(s1, s2));



	return (0);
}*/
