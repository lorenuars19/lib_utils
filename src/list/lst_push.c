/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:16:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 23:21:53 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"
#include "lib_io.h"

void	*lst_push_front(t_list **alst, t_list *new)
{
	if (!new)
	{
		return (error_ptr_put("lst_push_front : null input"));
	}
	if (alst)
	{
		if (new)
			new->next = *alst;
		*alst = new;
	}
	return (new);
}

void	*lst_push_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new)
	{
		return (error_ptr_put("lst_push_back : null input"));
	}
	if (alst && *alst && new)
	{
		tmp = *alst;
		while (new && tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	else if (alst)
	{
		*alst = new;
	}
	return (new);
}
