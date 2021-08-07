/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gst_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:38 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gst.h"

int	gst_push(t_gst *gst, void *data)
{
	if (!gst)
		return (error_put(1, "gst_push : NULL gst"));
	if (gst_new_resize(gst))
		return (error_put(1, "gst_push : gst_new_resize() NULL data"));
	if (gst_shift_down(gst))
		return (1);
	if (gst && gst->dat)
	{
		gst->dat[0] = data;
	}
	return (0);
}

int	gst_push_back(t_gst *gst, void *data)
{
	if (!gst)
		return (error_put(1, "gst_push_back : NULL gst"));
	if (gst_new_resize(gst))
		return (error_put(1, "gst_push_back : gst_new_resize() NULL data"));
	if (!gst->dat)
		return (error_put(1, "gst_push_back : gst->dat NULL"));
	gst->dat[gst->siz] = data;
	gst->siz++;
	return (0);
}
