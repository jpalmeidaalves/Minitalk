/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:50:29 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/16 19:28:08 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include<fcntl.h>

int	main(void)
{
	
	int myfile = open("test_putchar.txt", O_CREAT | O_WRONLY);
	ft_putchar_fd('A', myfile);
}*/
