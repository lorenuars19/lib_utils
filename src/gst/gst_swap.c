/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gst_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gst.h"

int	gst_swap(t_gst *gst)
{
	void	*tmp;

	if (!gst)
		return (error_put(1, "gst_swap : NULL gst"));
	if (gst->siz > 1)
	{
		tmp = gst->dat[0];
		gst->dat[0] = gst->dat[1];
		gst->dat[1] = tmp;
	}
	return (0);
}
