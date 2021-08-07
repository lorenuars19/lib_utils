/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nst_new_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:03:14 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/25 15:32:46 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_nst.h"

int	sub_nst_resize(t_nst *nst)
{
	long	i;
	long	*copy;

	if (nst->siz <= 0)
		return (error_put(1, "sub_nst_resize :  (nst->siz <= 0)"));
	copy = malloc(sizeof(long) * nst->siz * NST_SIZ_MULT);
	if (!copy)
		return (error_put(1, "sub_nst_resize : copy NULL"));
	i = 0;
	while (i < nst->siz)
	{
		copy[i] = nst->dat[i];
		i++;
	}
	free(nst->dat);
	nst->dat = copy;
	nst->max_siz = nst->max_siz * NST_SIZ_MULT;
	return (0);
}

int	nst_new_resize(t_nst *nst)
{
	if (!nst)
		return (error_put(1, "nst_new_resize : NULL nst"));
	if (nst->dat == NULL)
	{
		nst->max_siz = NST_INIT_SIZ;
		nst->siz = 0;
		nst->dat = malloc(sizeof(long) * nst->max_siz);
		if (!nst->dat)
			return (error_put(1, "nst_new_resize : nst->data NULL"));
	}
	else if (nst->siz >= nst->max_siz)
	{
		if (sub_nst_resize(nst))
		{
			nst_free(nst);
			return (1);
		}
	}
	return (0);
}
