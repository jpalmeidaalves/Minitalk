/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:11:04 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/04 16:11:06 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = n;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && (len - 1) > 0)
	{
		i++;
		len--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int	n = 3;
	char	str1[] = "hello";
	char	str2[] = "hella";
	printf("%d\n", ft_strncmp(str1, str2, n));
	char	str3[] = "hello";
	char	str4[] = "hella";
	printf("%d\n ", strncmp(str3, str4, n));
	return (0);
}*/
