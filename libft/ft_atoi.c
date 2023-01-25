/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:28:12 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/05 20:29:51 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	minus;

	i = 0;
	result = 0;
	minus = 1;
	while ((*(nptr + i) >= '\t' && (*(nptr + i) <= '\r')) \
						|| (*(nptr + i) == ' '))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			minus *= -1;
		i++;
	}
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{	
		result = (result * 10) + (*(nptr + i) - 48);
		i++;
	}
	return (minus * result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf("myatoi = %d\n", ft_atoi("   +10xx 34"));
	printf("atoi = %d\n", atoi("   +10xx 43"));
	printf("myatoi = %d\n", ft_atoi("	-2147483647"));
	printf("atoi = %d\n", atoi("	-2147483647"));
	printf("myatoi = %d\n", ft_atoi("	-2147483649"));
	printf("atoi = %d\n", atoi("	-2147483649"));



	return 0;
}*/
