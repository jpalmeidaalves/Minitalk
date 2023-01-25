/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:14 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/14 19:23:18 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strs(const char *s, char c)
{
	size_t	nb_strs;

	nb_strs = 0;
	while (*s)
	{
		if (*s != c)
		{
			++nb_strs;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}	
	return (nb_strs);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	len;
	size_t	i;	
	size_t	nb_strs;

	i = 0;
	nb_strs = ft_count_strs(s, c);
	arr = malloc((sizeof(char *) * nb_strs) + 1);
	if (!arr || !s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			arr[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	arr[i] = 0;
	return (arr);
}
/*
#include <stdio.h>

void	ft_print_array(char **array)
{
	int i;

	if (array == NULL)
		printf("Array is NULL\n");
	else
	{
		for(i = 0; array[i] != NULL; i++)
			printf("%d - %s\n", i, array[i]);
		printf("%d - NULL\n", i);
	}
}

int	main(void)
{
	char *str = "teste funcao todo atoa";
	char c = ' ';
	ft_print_array(ft_split(str, c));
}*/
