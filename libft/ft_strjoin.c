/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:25:15 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/09 17:26:36 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*tmp;
	size_t	len_s1;
	size_t	len_s2;		

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!result)
		return (0);
	tmp = result;
	while (len_s1--)
		*(result++) = *(s1++);
	while (len_s2--)
		*(result++) = *(s2++);
	*(result) = '\0';
	return (tmp);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s1 = "hello ";
	char *s2 = "world";
	printf("%s ", ft_strjoin(s1, s2));
	return (0);
}*/
