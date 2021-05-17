/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:56:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/08 18:25:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	lst_free(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (del && lst && *lst)
	{
		tmp = (*lst)->next;
		lst_delone(*lst, del);
		*lst = tmp;
	}
}
