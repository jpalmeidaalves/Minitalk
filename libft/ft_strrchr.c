/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:26:42 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/08 18:27:32 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(str);
	if (!s)
		return (NULL);
	if (*(str + len) == (char)c)
		return (str + len);
	while (len > 0)
	{
		if (*(str + len - 1) == (char)c)
			return (str + len - 1);
		len--;
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
	printf("%s\n", ft_strrchr(str, '\0'));
	printf("%s\n", strrchr(str1, '\0'));
	printf("%s\n", ft_strrchr(str, '3'));
	printf("%s\n", strrchr(str1, '3'));


	return (0);
}*/
