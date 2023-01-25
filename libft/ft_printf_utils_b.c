/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:12:29 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/29 20:20:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printhex(unsigned int nb, char c)
{
	if (nb < 16 && c == 'x')
		ft_putchar_r("0123456789abcdef"[nb]);
	else if (nb < 16 && c == 'X')
		ft_putchar_r("0123456789ABCDEF"[nb]);
	else
	{
		ft_printhex(nb / 16, c);
		ft_printhex(nb % 16, c);
	}
}

int	ft_puthex0x_r(unsigned int nb, char c)
{
	unsigned int	nb_l;
	int				count;

	count = 0;
	nb_l = nb;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb_l != 0)
	{
		nb_l /= 16;
		count++;
	}
	if (c == 'x')
		count += write(1, "0x", 2);
	if (c == 'X')
		count += write(1, "0X", 2);
	ft_printhex(nb, c);
	return (count);
}

int	ft_putnbr_r_space(int nb)
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
		count += ft_putchar_r('-');
	}
	else
		count += write(1, " ", 1);
	if (l_nb < 10)
		ft_putchar_r(l_nb + '0');
	else
	{
		ft_putnbr_r(l_nb / 10);
		ft_putnbr_r(l_nb % 10);
	}
	return (count);
}

int	ft_putnbr_r_plus(int nb)
{
	long int	l_nb;
	int			count;

	l_nb = nb;
	count = ft_count_nb(nb);
	if (nb == 0)
		return (write(1, "+0", 2));
	if (l_nb < 0)
	{
		l_nb = -l_nb;
		count += ft_putchar_r('-');
	}
	else if (l_nb >= 0)
		count += write(1, "+", 1);
	if (l_nb < 10)
		ft_putchar_r(l_nb + '0');
	else
	{
		ft_putnbr_r(l_nb / 10);
		ft_putnbr_r(l_nb % 10);
	}
	return (count);
}
