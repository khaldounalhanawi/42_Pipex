/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:45:08 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/08/07 14:32:36 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	num;

	num = 0;
	while (src[num])
		num++;
	if (dstsize)
	{
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (num);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char a[22] = "";
	char b[] = "xyz123456789";

	char aD[22] = "";
	char bD[] = "xyz123456789";

	size_t dstsize = 20;

	int my  = (int)ft_strlcpy(a,b,dstsize);
	int def = (int)strlcpy(aD,bD,dstsize);

	printf("my:        %s\n", a);
	printf("default:   %s\n", aD);	

	printf("%d\n", my);
	printf("%d\n", def);



}
*/
