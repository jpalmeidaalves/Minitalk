/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:19:41 by joaoalme          #+#    #+#             */
/*   Updated: 2023/01/21 12:15:07 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

unsigned char	*g_full_msg = NULL;

unsigned char	*ft_append_c(unsigned char *s, char ch)
{
	int				i;
	int				len;
	unsigned char	*str;

	i = 0;
	len = 0;
	if (s)
		len = ft_strlen((char *)s);
	str = (unsigned char *)malloc(len + 2);
	if (!str)
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
	}
	str[i++] = ch;
	str[i] = '\0';
	free(s);
	return (str);
}

void	handl_func(int sig, siginfo_t *info, void *ucontext)
{
	static int				rd_bits = 0;
	static unsigned char	c = 0;
	unsigned int			mask;

	(void)ucontext;
	mask = (sig == SIGUSR1);
	c |= (mask << rd_bits++);
	if (rd_bits == 8)
	{
		g_full_msg = ft_append_c(g_full_msg, c);
		if (!g_full_msg)
			exit(EXIT_FAILURE);
		if (c == '\0')
		{
			ft_printf("%s\n", g_full_msg);
			free(g_full_msg);
			g_full_msg = NULL;
			if (kill(info->si_pid, SIGUSR1) == -1)
				err_msg("Can't communicate with client\n");
		}
		rd_bits = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act_handl1;
	struct sigaction	act_handl2;

	ft_memset(&act_handl1, 0, sizeof(act_handl1));
	ft_memset(&act_handl2, 0, sizeof(act_handl2));
	ft_printf("Server PID : %d\n", getpid());
	act_handl1.sa_flags |= SA_SIGINFO;
	act_handl1.sa_sigaction = &handl_func;
	sigemptyset(&act_handl1.sa_mask);
	sigaddset(&act_handl1.sa_mask, SIGUSR2);
	act_handl2.sa_flags |= SA_SIGINFO;
	act_handl2.sa_sigaction = &handl_func;
	sigemptyset(&act_handl2.sa_mask);
	sigaddset(&act_handl2.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &act_handl1, NULL) == -1)
		err_msg("Unable to handle SIGUSR1");
	if (sigaction(SIGUSR2, &act_handl2, NULL) == -1)
		err_msg("Unable to handle SIGUSR2");
	while (1)
		pause();
	return (0);
}
