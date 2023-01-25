/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:50:48 by joaoalme          #+#    #+#             */
/*   Updated: 2022/12/02 09:29:38 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_r(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_count_nb(int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_r(int nb)
{
	long int	l_nb;
	int			count;

	l_nb = nb;
	count = ft_count_nb(nb);
	if (nb == 0)
		count = 1;
	if (l_nb < 0)
	{
		l_nb = -l_nb;
		ft_putchar_r('-');
		count++;
	}
	if (l_nb < 10)
		ft_putchar_r(l_nb + '0');
	else
	{
		ft_putnbr_r(l_nb / 10);
		ft_putnbr_r(l_nb % 10);
	}
	return (count);
}

int	ft_putstr_r(char *str)
{
	unsigned int	count;

	count = 0;
	if (str == NULL)
	{
		ft_putstr_r("(null)");
		return (6);
	}
	while (*str)
	{
		ft_putchar_r(*str++);
		count++;
	}
	return (count);
}
