/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:17:27 by joaoalme          #+#    #+#             */
/*   Updated: 2022/12/02 09:26:17 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_apply_flags(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr_r_space(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_r(va_arg(args, char *));
	else if (c == 'c')
		count += ft_putchar_r(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex0x_r(va_arg(args, unsigned int), c);
	else if (c == '%')
		count += ft_putchar_r('%');
	else if (c == 'u')
		count += ft_put_uint_r(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_count_print_ptr(va_arg(args, unsigned long long));
	return (count);
}

int	ft_apply_flags2(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr_r_plus(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_r(va_arg(args, char *));
	else if (c == 'c')
		count += ft_putchar_r(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex0x_r(va_arg(args, unsigned int), c);
	else if (c == '%')
		count += ft_putchar_r('%');
	else if (c == 'u')
		count += ft_put_uint_r(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_count_print_ptr(va_arg(args, unsigned long long));
	return (count);
}
