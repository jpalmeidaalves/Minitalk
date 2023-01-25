/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:34:59 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/11 15:35:00 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (!tmp)
		*lst = new;
	else
	tmp->next = new;
}

/*
#include <stdio.h>

void	ft_print_list(t_list * head) 
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
        int l = 40;
        t_list  **start = NULL;
        t_list *head = NULL;
        head = (t_list *)malloc(sizeof(t_list));
        if (head == NULL)
                return (1);
        start = (t_list **)malloc(sizeof(t_list));
        if (start == NULL)
                return (1);
        head->content = &i;
        head->next = NULL;
        t_list *second  = ft_lstnew(&j);
        t_list *third  = ft_lstnew(&k);
        t_list *fourth = ft_lstnew(&l);
        ft_lstadd_front(&head, second);
        ft_lstadd_front(&second, third);
        *start = third;
        ft_lstadd_back(start, fourth);
        ft_print_list(*start);
        printf("%d", ft_lstsize(*start));
}*/
