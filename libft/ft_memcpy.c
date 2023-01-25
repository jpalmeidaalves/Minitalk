/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:35:50 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/14 17:14:39 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*adest;
	char	*asrc;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	adest = (char *)dest;
	asrc = (char *)src;
	while (n--)
		adest[n] = asrc[n];
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "123456";
	char	str2[7];	
	memcpy(str2, str1, 7);
	printf("%s\n", str2);
	char	*str3 = "123456";
	char	str4[7];
	ft_memcpy(str4, str3, 7);
	printf("%s\n", str4);

	return (0);
}*/
