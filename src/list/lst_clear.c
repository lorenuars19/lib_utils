/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:56:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 23:21:05 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"

void	lst_clear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (del && lst && *lst)
	{
		tmp = (*lst)->next;
		lst_remove(*lst, del);
		*lst = tmp;
	}
}
