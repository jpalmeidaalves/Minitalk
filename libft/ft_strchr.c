/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:51:20 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/19 17:09:55 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[];
	char	str1[];

	str[] = "12345";
	str1[] = "12345";
	printf("%s\n", ft_strchr(str, '\0'));
	printf("%s\n", strchr(str1, '\0'));
	printf("%s\n", ft_strchr(str, '3'));
	printf("%s\n", strchr(str1, '3'));
	return (0);
}
*/
