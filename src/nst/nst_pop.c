/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nst_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/21 21:49:17 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_nst.h"

/*
** Pop the node on top of the nst
*/

int	nst_pop(t_nst *nst)
{
	if (nst_shift_up(*&nst))
		return (error_put(1, "nst_pop : nst_shift_up()"));
	return (0);
}

int	nst_pop_back(t_nst *nst)
{
	nst->siz--;
	return (0);
}
