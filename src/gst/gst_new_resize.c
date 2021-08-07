/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gst_new_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:03:14 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:36 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_gst.h"

int	sub_gst_resize(t_gst *gst)
{
	long	i;
	void	**copy;

	if (gst->siz <= 0)
		return (error_put(1, "sub_gst_resize :  (gst->siz <= 0)"));
	copy = malloc(sizeof(void *) * gst->siz * GST_SIZ_MULT);
	if (!copy)
		return (error_put(1, "sub_gst_resize : copy NULL"));
	i = 0;
	while (i < gst->siz)
	{
		copy[i] = gst->dat[i];
		i++;
	}
	free(gst->dat);
	gst->dat = copy;
	gst->max_siz = gst->max_siz * GST_SIZ_MULT;
	return (0);
}

int	gst_new_resize(t_gst *gst)
{
	if (!gst)
		return (error_put(1, "gst_new_resize : NULL gst"));
	if (gst->dat == NULL)
	{
		gst->max_siz = GST_INIT_SIZ;
		gst->siz = 0;
		gst->dat = malloc(sizeof(long) * gst->max_siz);
		if (!gst->dat)
			return (error_put(1, "gst_new_resize : gst->data NULL"));
	}
	else if (gst->siz >= gst->max_siz)
	{
		if (sub_gst_resize(gst))
		{
			gst_free(gst);
			return (1);
		}
	}
	return (0);
}
