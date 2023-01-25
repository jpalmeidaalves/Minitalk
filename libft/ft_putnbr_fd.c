/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:01:36 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/16 19:40:03 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
}
/*
#include<fcntl.h>

int	main(void)
{
	int myfile = open("test_putnbr.txt", O_CREAT | O_WRONLY | O_APPEND);
	ft_putnbr_fd( 325, myfile);
	ft_putchar_fd('\n', myfile);
	ft_putnbr_fd( 10, myfile);
	ft_putchar_fd('\n', myfile);
	ft_putnbr_fd( 777, myfile);
}*/
