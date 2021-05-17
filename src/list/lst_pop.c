/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:27:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 23:25:10 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_list.h"

void	lst_pop(t_list **list, void (*del)(void*))
{
	t_list *lst;

	lst = *list;
	if (list && *list)
	{
		*list = (*list)->next;
	}
	if (del && lst && lst->content)
	{
		(*del)(lst->content);
		lst->content = NULL;
	}
	if (lst && lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}

void	lst_pop_back(t_list **list, void (*del)(void*))
{
	t_list	*before_last;
	t_list	*lst;

	lst = lst_last(*list);
	before_last = lst_before_last(*list);
	if (*list && !(*list)->next)
		*list = NULL;
	if (before_last && before_last->next)
		before_last->next = NULL;
	if (del && lst && lst->content)
	{
		(*del)(lst->content);
		lst->content = NULL;
	}
	if (lst && lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}
