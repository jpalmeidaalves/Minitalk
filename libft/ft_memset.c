/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:08:42 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/08 18:22:13 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *str, int c, size_t n)
{
	size_t					i;
	unsigned char			*str_s;

	str_s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		str_s[i] = c;
		i++;
	}
	return (str);
}
/*
Note that the 2nd argument(char c) is the value that is
copied converted to unsigned char
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = ("This is string.h library function");
	printf("%s\n", str);
	memset(str,'$',7);
	printf("%s\n", str);
	char	str2[] = ("This is string.h library function");
	printf("%s\n", str2);
	ft_memset(str2,'$',7);
	printf("%s\n", str2);

	return (0);
}*/
/*
#include <stdio.h>
#include <string.h>
  
void printArray(int arr[], int n)
{
   for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
}

int main()
{
    int n = 10;
    int arr[n];
    int arr2[n];
  
    // Fill whole array with 100.
    memset(arr, 5, n*sizeof(arr[0]));
    printf("Array after memset()\n");
    printArray(arr, n);
    printf("\n");
    ft_memset(arr2, 5, n*sizeof(arr2[0]));
    printf("Array after ft_memset()\n");
    printArray(arr2, n);
    return 0;
}*/
/*Note that the above code doesn’t set array values to 10 
as memset works character by character and an integer
contains more than one bytes (or characters).
However, if we replace 10 with -1, we get -1 values. Because
representation of -1 contains all 1s in case of both char and int.*/
