/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:05:47 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/11 20:06:04 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f (lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
void    ft_func(void *content)
{
        content = &content + 10;
}

void    ft_print_list(t_list * head)
{
    t_list * current = head;
    while (current != NULL)
    {
            printf("%d\n", *(int *)current->content);
            current = current->next;
    }
}

int     main(void)
{       
        int i = 10;
        int j = 20;
        int k = 30;
        t_list *head = ft_lstnew(&i);
        t_list *second  = ft_lstnew(&j);
        t_list *third  = ft_lstnew(&k);
        ft_lstadd_back(&head, second); 
        ft_lstadd_back(&second, third);
        ft_print_list(head);
        ft_lstiter(head, &ft_func);
        ft_print_list(head);
}*/
