/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gst_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gst.h"

int	gst_rotate(t_gst *gst)
{
	void	*tmp;

	if (!gst)
		return (error_put(1, "gst_rotate : NULL gst"));
	tmp = gst->dat[0];
	if (gst_pop(gst))
		return (error_put(1, "gst_rotate : gst_pop()"));
	if (gst_push_back(gst, tmp))
		return (error_put(1, "gst_rotate : gst_push_back()"));
	return (0);
}

int	gst_rev_rotate(t_gst *gst)
{
	void	*tmp;

	if (!gst)
		return (error_put(1, "gst_rev_rotate : NULL gst"));
	tmp = gst->dat[gst->siz - 1];
	if (gst_pop_back(gst))
		return (error_put(1, "gst_rev_rotate : gst_pop_back()"));
	if (gst_push(gst, tmp))
		return (error_put(1, "gst_rev_rotate : gst_push()"));
	return (0);
}
