/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:42:30 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/08 19:23:48 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*result;

	result = dest;
	if (!src && !dest)
		return (NULL);
	if (src < dest)
	{
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
	{
		while (n--)
			*(char *)dest++ = *(char *)src++;
	}
	return (result);
}
/*
memmove is useful in a situation that you want to 
delete one or more elements of an array and slide the remainder 
elements to keep them toghether instead let a gap.*/

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str2[] = "Testing function";
	char	*str1  = str2 + 4;
	int	n = 4;
	printf("%s\n", str2);
	memmove(str2, str1, n);
	printf("%s\n", str2);
	char	str4[] = "Testing function";
	char	*str3 = str4 + 4;
	printf("%s\n", str4);
	ft_memmove(str4, str3, n);
	printf("%s\n", str4);

	return (0);
}
*/
/*
#include <stdio.h>
#include <string.h>
void	remove_elem(int *arr, int index_to_remove)
{
	memmove(arr + 1, arr, sizeof(int) * index_to_remove);
	arr[0] = 0;
	
}

int	main (void)
{
	int size = 5;
	int values[] = {1, 2, 3, 4, 5};
	remove_elem(values, 1); 
	for (int i = 0; i < size; i++)
		printf("%d, ", values[i]);

}*/
