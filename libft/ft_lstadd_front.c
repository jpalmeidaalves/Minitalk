/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:01:31 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/10 21:08:03 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

void ft_print_list(t_list * head) {
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
	t_list *head = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (1);
	head->content = &i;
	head->next = NULL;
	t_list *second  = ft_lstnew(&j);
	ft_lstadd_front(&head, second);	
	ft_print_list(head);
}*/
