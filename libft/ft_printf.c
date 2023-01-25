/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:51:31 by joaoalme          #+#    #+#             */
/*   Updated: 2022/12/02 09:17:21 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_if_flag(const char *str, int *i, int *printed, va_list args)
{
	(*i)++;
	if (str[*i] != '#' && str[*i] != '+' && str[*i] != ' ')
		*printed += ft_read_placeholder(str[*i], args);
	else if (str[*i] == '+' || str[*i] == '#')
	{
		(*i)++;
		while (str[*i] == '+')
			(*i)++;
		*printed += ft_apply_flags2(str[*i], args);
	}
	else if (str[*i] == ' ')
	{
		while (str[*i] == ' ')
			(*i)++;
		*printed += ft_apply_flags(str[*i], args);
	}
	(*i)++;
}

int	ft_read_placeholder(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putnbr_r(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_r(va_arg(args, char *));
	else if (c == 'c')
		count += ft_putchar_r(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex_r(va_arg(args, unsigned int), c);
	else if (c == '%')
		count += ft_putchar_r('%');
	else if (c == 'u')
		count += ft_put_uint_r(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_count_print_ptr(va_arg(args, unsigned long long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_if_flag(str, &i, &printed, args);
		else
			printed += write(1, &str[i++], 1);
	}
	return (printed);
}
