/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:15:07 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/11 18:45:13 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
void	del(void *content)
{	
	free(content);
}
void	ft_print_list(t_list * head)
{
	t_list * current = head;
	while (current != NULL)
	{
        	printf("%s\n", (char *)current->content);
        	current = current->next;
	}
}

int     main(void)
{       
        char *str1 = "huauh";
        char *str2 = "jisij";
        char *str3 = "mzmzm";
        t_list  **tmp = malloc(sizeof(t_list));
        t_list *head = ft_lstnew(ft_strdup(str1));
        t_list *second  = ft_lstnew(ft_strdup(str2));     
        *tmp = second;
        t_list *third  = ft_lstnew(ft_strdup(str3));
        ft_lstadd_back(&head, second);  
        ft_lstadd_back(&head, third);
        ft_print_list(head);
        ft_lstclear(tmp, &del);
        ft_print_list(head);
}*/
