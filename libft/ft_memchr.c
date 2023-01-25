/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:15:07 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/04 19:18:09 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*(str + i) == (unsigned char)c)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "12345";
	char str1[] = "12345";
	printf("%s\n", (char *)ft_memchr(str, '3', 5));
	printf("%s\n", (char *)memchr(str1, '3', 5));

	return (0);
}*/
