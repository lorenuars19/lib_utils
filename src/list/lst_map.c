/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:28:27 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 23:22:31 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"

t_list	*lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	tmp = NULL;
	while (lst)
	{
		tmp = lst_new(f(lst->content));
		if (!(tmp))
		{
			lst_remove(tmp, del);
			lst_clear(&new, del);
			return (NULL);
		}
		lst_push_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
