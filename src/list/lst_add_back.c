/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:16:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:21:39 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"

void	lst_add_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

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
}
