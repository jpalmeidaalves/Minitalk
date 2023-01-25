/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:16:07 by joaoalme          #+#    #+#             */
/*   Updated: 2023/01/25 17:47:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	serv_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("\n+ Client: Message received +\n");
	exit(0);
}

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
	struct sigaction	s_hand;

	ft_memset(&s_hand, 0, sizeof(s_hand));
	s_hand.sa_handler = &serv_handler;
	if (sigaction(SIGUSR1, &s_hand, NULL) == -1)
		err_msg("Error: Impossible to set handler");
	if (ac != 3)
		err_msg("Usage: ./client [PID] [MESSAGE]");
	pid_serv = atoi(av[1]);
	send_str(av[2], pid_serv);
	while (1)
		pause();
	return (0);
}
