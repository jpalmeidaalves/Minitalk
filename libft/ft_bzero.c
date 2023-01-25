/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:42:23 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/02 15:43:25 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	long unsigned int	i;
	char				*str_s;

	str_s = str;
	i = 0;
	while (i < n)
	{
		str_s[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
        char    str[] = ("This is string.h library function");
        printf("%s\n", str);
        bzero(str, 7);
        printf("%s\n", str);
	printf("%s\n", str + 7);
        char    str2[] = ("This is string.h library function");
        printf("%s\n", str2);
        ft_bzero(str2, 7);
        printf("%s\n", str2);
	printf("%s\n", str2 + 7);
        return (0);
}*/
