/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:02:54 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/14 19:20:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len_d;
	size_t		free;

	free = size;
	d = dest;
	s = src;
	while (free-- && *d != '\0')
		d++;
	len_d = d - dest;
	free = size - len_d;
	if (free == 0)
		return (len_d + ft_strlen(s));
	while (*s != '\0')
	{
		if (free != 1)
		{
			*d++ = *s;
			free--;
		}
		s++;
	}
	*d = '\0';
	return (len_d + (s - src));
}
/*
#include <stdio.h>
#include <bsd/string.h>

size_t strlcat(char *dst, const char *src, size_t n);
int	main(void)
{
	//unsigned int	n = 11;
	//char str1[11] = "hello";
	char *str2 = "world";
	//char str3[11] = "hello";
        char *str4 = "world";

	printf("ft_strlcat returns %d - string: \n"\
	, (int)ft_strlcat((void *)0, str2, 0));
	printf("strlcat returns %d - string: \n"\
	, (int)strlcat((void *)0, str4, 0));
	return (0);
}

size_t strlcat(char *dst, const char *src, size_t n) 
{
    char *p = dst;

    while (n != 0 && *p != '\0') {
        p++;
        n--;
    }
    if (n != 0) {
        for (; --n != 0; p++, src++) {
            if ((*p = *src) == '\0')
                return p - dst;
        }
        *p = '\0';
    }
    return (p - dst) + strlen(src);
}*/
