/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nst_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/25 11:54:22 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_nst.h"

int	nst_push(t_nst *nst, long data)
{
	if (!nst)
		return (error_put(1, "nst_push : NULL nst"));
	if (nst_new_resize(nst))
		return (error_put(1, "nst_push : nst_new_resize() NULL data"));
	if (nst_shift_down(nst))
		return (1);
	if (nst && nst->dat)
	{
		nst->dat[0] = data;
	}
	return (0);
}

int	nst_push_back(t_nst *nst, long data)
{
	if (!nst)
		return (error_put(1, "nst_shift : NULL nst"));
	if (nst_new_resize(nst))
		return (error_put(1, "nst_push_back : nst_new_resize() NULL data"));
	if (!nst->dat)
		return (error_put(1, "nst_push_back : nst->dat NULL"));
	nst->dat[nst->siz] = data;
	nst->siz++;
	return (0);
}
