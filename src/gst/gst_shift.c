/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gst_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:13:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:41 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gst.h"

int	gst_shift_down(t_gst *gst)
{
	long	i;

	if (!gst)
		return (error_put(1, "gst_shift_down : NULL gst"));
	gst->siz++;
	if (gst_new_resize(gst))
		return (error_put(1, "gst_shift_down : gst_new_resize() NULL data"));
	i = gst->siz - 1;
	while (gst->dat && i < gst->siz && i >= 0)
	{
		gst->dat[i + 1] = gst->dat[i];
		i--;
	}
	return (0);
}

int	gst_shift_up(t_gst *gst)
{
	long	i;

	if (!gst)
		return (error_put(1, "gst_shift_up : NULL gst"));
	gst->siz--;
	if (gst_new_resize(gst))
		return (error_put(1, "gst_shift_up : gst_new_resize() NULL data"));
	i = 0;
	while (gst->dat && i < gst->siz && i >= 0)
	{
		gst->dat[i] = gst->dat[i + 1];
		i++;
	}
	return (0);
}
