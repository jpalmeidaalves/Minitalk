/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:40:59 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/10 20:41:20 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
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
	head->next = second;
	ft_print_list(head);
}*/
