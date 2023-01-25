/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:07 by joaoalme          #+#    #+#             */
/*   Updated: 2023/01/25 17:37:42 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_chr(unsigned char c, int pid)
{
	int		i;
	char	mask;

	i = 8;
	mask = 0b00000001;
	while (i--)
	{
		if (c & mask)
		{
			if (kill(pid, SIGUSR1) == -1)
				err_msg("Failed sending SIGUSR1 to server");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				err_msg("Failed sending SIGUSR2 to server");
		}
		mask <<= 1;
		usleep(100);
	}
}

void	send_str(char *str, int pid)
{
	int	i;

	i = 0;
	while (i <= (int)ft_strlen(str))
		send_chr(str[i++], pid);
}

int	main(int ac, char **av)
{
	int					pid_serv;

	if (ac != 3)
		err_msg("Usage: ./client [PID] [MESSAGE]");
	pid_serv = atoi(av[1]);
	send_str(av[2], pid_serv);
}
