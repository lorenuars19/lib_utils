/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gst_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:32:46 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:27 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_gst.h"

/*
** Free the whole gst
*/

void	gst_free(t_gst *gst)
{
	free(gst->dat);
	gst->dat = NULL;
	gst->siz = 0;
	gst->max_siz = 0;
}
