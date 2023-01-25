/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:50:14 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/08 20:01:57 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{	
		while (*src && i < (size - 1))
		{
			*dest++ = *src++;
			i++;
		}
		if (i < size)
			*dest = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
/*
#include <string.h>

size_t strlcpy(char *dst, const char *src, size_t n) {
    char *p = dst;

    if (n != 0) {
        for (; --n != 0; p++, src++) {
            if ((*p = *src) == '\0')
                return p - dst;
        }
        *p = '\0';
    }
    return (p - dst) + strlen(src);
}
#include<stdio.h>

int	main(void)
{
	char str1[] = "hello";
	char str2[] = "girlsss";
	char str3[] = "hello";
	char str4[] = "girlsss";
	ft_strlcpy(str2, str1, 6);
	strlcpy(str4, str3, 6);
	printf("ft_strlcpy: %s\n", str2);
	printf("strlcpy: %s\n", str4);
}*/
