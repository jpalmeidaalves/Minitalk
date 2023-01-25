/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:01:55 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/05 21:02:07 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*test;
	int		*test2;
	int		i;

	test = calloc(5, 1);
	printf("%s\n", test);
	test2 = calloc(5, 1);
	i = 0;
	while (i++ < 5)
		printf("%d\n", test2[i]);
}*/
