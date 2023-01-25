/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:35:35 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/10 18:35:58 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void    func(unsigned int i, char * str)
{
    if ((int)i < 6)
    {
        if (*str >= 'a' && *str <= 'z')
          *str = *str - 32;
    }
}
#include <stdio.h>
int	main(void)
{
	char test[] = "Hello";
	ft_striteri(test, &func);
	printf ("%s\n", test);
	return (0);
}*/
