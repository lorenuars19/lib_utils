/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnst_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:37 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gnst.h"

/*
** Pop the node on top of the gnst
*/

int	gnst_pop(t_gnst *gnst)
{
	if (gnst_shift_up(*&gnst))
		return (error_put(1, "gnst_pop : gnst_shift_up()"));
	return (0);
}

int	gnst_pop_back(t_gnst *gnst)
{
	gnst->siz--;
	return (0);
}
