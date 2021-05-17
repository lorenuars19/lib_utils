/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:27:34 by lorenuar          #+#    #+#             */
/*   Updated: 2021/03/08 00:32:39 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	lst_delone(t_list *lst, void (*del)(void*))
{
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
