/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:39:51 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/09 20:54:32 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

static size_t	len_nb(long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len_n;
	long	nb;

	nb = (long)n;
	len_n = len_nb(nb);
	res = malloc(sizeof(char) * len_n + 1);
	if (!res)
		return (0);
	if (n == 0)
		*res = '0';
	if (nb < 0)
	{
		nb *= -1;
		*(res) = '-';
	}
	*(res + len_n--) = '\0';
	while (nb > 0)
	{
		*(res + len_n) = (nb % 10) + 48;
		nb /= 10;
		len_n--;
	}
	return (res);
}
/*
int main()
{
  printf("%s", ft_itoa(-2147483648));
}*/
