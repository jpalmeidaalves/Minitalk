/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:52:27 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/11 10:52:31 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*

#include <stdio.h>

void	ft_print_list(t_list * head) {
    t_list * current = head;

    while (current != NULL) {
        printf("%d\n", *(int *)current->content);
        current = current->next;
    }
}

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
	ft_print_list(second);
	printf("%d", ft_lstsize(second));
}*/
