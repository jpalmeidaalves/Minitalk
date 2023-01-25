/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:11:15 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/06 17:11:17 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s) + 1;
	copy = (char *)malloc(sizeof(char) * len);
	if (!copy)
		return (0);
	ft_memcpy(copy, s, len);
	return (copy);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[];
	char	*dest;

	src[] = "TEST";
	printf("%s ", dest = strdup(src));
}*/
