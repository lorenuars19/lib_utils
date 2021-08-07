/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nst_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:48:58 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_nst.h"
#include "lib_io.h"

int	nst_swap(t_nst *nst)
{
	long	tmp;

	if (!nst)
		return (error_put(1, "nst_swap : NULL nst"));
	if (nst->siz > 1)
	{
		tmp = nst->dat[0];
		nst->dat[0] = nst->dat[1];
		nst->dat[1] = tmp;
	}
	return (0);
}
