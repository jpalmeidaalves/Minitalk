/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:51:18 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/02 21:51:21 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		c -= 32;
	return (c);
}
/*
#include<stdio.h>
int	main(void)
{
	printf("%c\n", ft_toupper('f'));
	printf("%c\n", ft_toupper('3'));
}*/
