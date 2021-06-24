/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnst_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:38 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gnst.h"

int	gnst_push(t_gnst *gnst, void *data)
{
	if (!gnst)
		return (error_put(1, "gnst_push : NULL gnst"));
	if (gnst_new_resize(gnst))
		return (error_put(1, "gnst_push : gnst_new_resize() NULL data"));
	if (gnst_shift_down(gnst))
		return (1);
	if (gnst && gnst->dat)
	{
		gnst->dat[0] = data;
	}
	return (0);
}

int	gnst_push_back(t_gnst *gnst, void *data)
{
	if (!gnst)
		return (error_put(1, "gnst_push_back : NULL gnst"));
	if (gnst_new_resize(gnst))
		return (error_put(1, "gnst_push_back : gnst_new_resize() NULL data"));
	if (!gnst->dat)
		return (error_put(1, "gnst_push_back : gnst->dat NULL"));
	gnst->dat[gnst->siz] = data;
	gnst->siz++;
	return (0);
}
