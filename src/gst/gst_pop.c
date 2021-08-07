/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gst_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:37 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gst.h"

/*
** Pop the node on top of the gst
*/

int	gst_pop(t_gst *gst)
{
	if (gst_shift_up(*&gst))
		return (error_put(1, "gst_pop : gst_shift_up()"));
	return (0);
}

int	gst_pop_back(t_gst *gst)
{
	gst->siz--;
	return (0);
}
