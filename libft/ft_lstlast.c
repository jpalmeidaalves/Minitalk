/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:49 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/11 11:38:06 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	int i = 10;
	int j = 20;
	int k = 30;
	t_list *head = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (1);
	head->content = &i;
	head->next = NULL;
	t_list *second  = ft_lstnew(&j);
	t_list *third  = ft_lstnew(&k);
	ft_lstadd_front(&head, second);
	ft_lstadd_front(&second, third);
	t_list	*test = ft_lstlast(third);	
	printf("test->content: %d\n", *(int *)test->content);
}*/
