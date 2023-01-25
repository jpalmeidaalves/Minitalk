/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:52:37 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/11 17:52:39 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
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
        t_list *head = ft_lstnew(ft_strdup(str1));
        t_list *second  = ft_lstnew(ft_strdup(str2));     
        t_list *third  = ft_lstnew(ft_strdup(str3));
        ft_lstadd_back(&head, second);  
        ft_lstadd_back(&head, third);
        ft_print_list(head);
        ft_lstdelone(second, &del);
        ft_print_list(head);
//      printf("%s\n", (char *)head->content);
}*/
