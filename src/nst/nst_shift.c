/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nst_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:13:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:50:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_nst.h"
#include "lib_io.h"

int	nst_shift_down(t_nst *nst)
{
	long	i;

	if (!nst)
		return (error_put(1, "nst_shift : NULL nst"));
	nst->siz++;
	if (nst_new_resize(nst))
		return (error_put(1, "nst_shift : nst_new_resize() NULL data"));
	i = nst->siz - 1;
	while (nst->dat && i < nst->siz && i >= 0)
	{
		nst->dat[i + 1] = nst->dat[i];
		i--;
	}
	return (0);
}

int	nst_shift_up(t_nst *nst)
{
	long	i;

	if (!nst)
		return (error_put(1, "nst_shift : NULL nst"));
	nst->siz--;
	if (nst_new_resize(nst))
		return (error_put(1, "nst_shift : nst_new_resize() NULL data"));
	i = 0;
	while (nst->dat && i < nst->siz && i >= 0)
	{
		nst->dat[i] = nst->dat[i + 1];
		i++;
	}
	return (0);
}
