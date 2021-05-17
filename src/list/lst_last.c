/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:11:02 by lorenuar          #+#    #+#             */
/*   Updated: 2021/05/17 23:33:56 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_list.h"

t_list	*lst_last(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*lst_before_last(t_list *lst)
{
	while (lst && lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}
