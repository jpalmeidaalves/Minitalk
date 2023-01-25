/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:50:56 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/10 18:52:35 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
/*
#include <fcntl.h>

int	main(void)
{
	int my_fd = open("test_putstr.txt", O_CREAT | O_WRONLY | S_IRWXU);
	ft_putstr_fd("Creating and writing a string in a file", my_fd);
}*/
