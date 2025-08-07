/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:49:04 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/07 17:43:43 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	full_match(const char *haystack, const char *needle, size_t len)
{
	while (*needle)
	{
		if (*needle != *haystack || !*haystack || !len)
			return (0);
		needle++;
		haystack++;
		len--;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle && full_match(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char a[] = "khaldoun";
	char b[] = "ld";
	size_t len = 6;

	printf("my:         %s\n", ft_strnstr(a, b, len));
	printf("default:    %s\n", strnstr(a, b, len));


}*/
