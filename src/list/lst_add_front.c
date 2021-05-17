/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:29:24 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 22:21:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"

void	lst_add_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (new)
			new->next = *alst;
		*alst = new;
	}
}
