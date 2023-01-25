/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:53:41 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/29 20:22:01 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(unsigned long long nb)
{
	if (nb < 16)
		ft_putchar_r("0123456789abcdef"[nb]);
	else
	{
		ft_putptr(nb / 16);
		ft_putptr(nb % 16);
	}
}

int	ft_count_print_ptr(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	ft_putptr(nb);
	while (nb != 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

int	ft_put_uint_r(unsigned int nb)
{
	unsigned int	l_nb;
	int				count;

	l_nb = nb;
	count = 0;
	if (nb == 0)
		count = 1;
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	if (l_nb < 10)
		ft_putchar_r(l_nb + '0');
	else
	{
		ft_put_uint_r(l_nb / 10);
		ft_put_uint_r(l_nb % 10);
	}
	return (count);
}

int	ft_puthex_r(unsigned int nb, char c)
{
	unsigned int	nb_l;
	int				count;

	count = 0;
	nb_l = nb;
	if (nb == 0)
		count = 1;
	while (nb_l != 0)
	{
		nb_l /= 16;
		count++;
	}
	if (nb < 16 && c == 'x')
		ft_putchar_r("0123456789abcdef"[nb]);
	else if (nb < 16 && c == 'X')
		ft_putchar_r("0123456789ABCDEF"[nb]);
	else
	{
		ft_puthex_r(nb / 16, c);
		ft_puthex_r(nb % 16, c);
	}
	return (count);
}
