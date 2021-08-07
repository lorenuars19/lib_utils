/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nst_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/22 00:33:44 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_nst.h"
#include "lib_io.h"

int	nst_rotate(t_nst *nst)
{
	long	tmp;

	if (!nst)
		return (error_put(1, "nst_swap : NULL nst"));
	tmp = nst->dat[0];
	if (nst_pop(nst))
		return (error_put(1, "nst_rev_rotate : nst_pop()"));
	if (nst_push_back(nst, tmp))
		return (error_put(1, "nst_rev_rotate : nst_push_back()"));
	return (0);
}

int	nst_rev_rotate(t_nst *nst)
{
	long	tmp;

	if (!nst)
		return (error_put(1, "nst_swap : NULL nst"));
	tmp = nst->dat[nst->siz - 1];
	if (nst_pop_back(nst))
		return (error_put(1, "nst_rotate : nst_pop_back()"));
	if (nst_push(nst, tmp))
		return (error_put(1, "nst_rotate : nst_push()"));
	return (0);
}
