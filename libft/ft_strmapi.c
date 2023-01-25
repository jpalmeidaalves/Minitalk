/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:09:14 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/10 18:37:15 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	x;	

	if (!s)
		return (0);
	x = 0;
	result = (char *)malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (!result)
		return (NULL);
	while (s[x])
	{
		result[x] = f(x, s[x]);
		x++;
	}
	result[x] = '\0';
	return (result);
}
/*
#include <stdio.h>

char	ft_test(unsigned int i, char c)
{
	return (c + i);
}

int	main()
{
	char *s = "abcd";
	
	printf("%s ", ft_strmapi(s, &ft_test));	
}*/
