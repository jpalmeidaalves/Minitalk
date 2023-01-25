/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:19:45 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/15 21:02:39 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0)
		return ((char *)big);
	if (lit[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == lit[j] && i + j < len)
		{
			if (big[i + j] == '\0' && lit[j] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (lit[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str1 = "helelo";
	char	*str2 = "lelo";
	printf("%s\n", ft_strnstr(str1, str2, 6));

	return (0);
}*/
/* IMPORTANT: Note that 'len' refers the de number of characters in 'big'
 to be searched. So, only if 'lit' is fully found in the first 'len'
 characters of big, a pointer to the first character of the first 
 occurrence of 'lit' is returned.*/
