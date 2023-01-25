/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:56:24 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/10 19:12:34 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include<fcntl.h>

int	main(void)
{
	
	int myfile = open("test_putendl.txt", O_CREAT | O_WRONLY);
	ft_putendl_fd("Hello world", myfile);
	ft_putendl_fd("This should be in the 2nd line", myfile);
}*/
