/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnst_new_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:03:14 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:36 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_gnst.h"

int	sub_gnst_resize(t_gnst *gnst)
{
	long	i;
	void	**copy;
	long	siz;

	if (!gnst)
		return (error_put(1, "sub_gnst_resize : gnst NULL"));
	siz = sizeof(long) * gnst->siz * GNST_SIZ_MULT;
	if (siz <= 0)
		return (error_put(1, "sub_gnst_resize : siz <= 0"));
	copy = malloc(siz);
	if (!copy)
		return (error_put(1, "sub_gnst_resize : copy NULL"));
	i = 0;
	while (gnst && gnst->dat && i < gnst->siz)
	{
		copy[i] = gnst->dat[i];
		i++;
	}
	if (gnst && gnst->dat)
	{
		free(gnst->dat);
	}
	gnst->dat = NULL;
	gnst->dat = copy;
	gnst->max_siz = gnst->max_siz * GNST_SIZ_MULT;
	return (0);
}

int	gnst_new_resize(t_gnst *gnst)
{
	if (!gnst)
		return (error_put(1, "gnst_new_resize : NULL gnst"));
	if (gnst->dat == NULL)
	{
		gnst->max_siz = GNST_INIT_SIZ;
		gnst->siz = 0;
		gnst->dat = malloc(sizeof(long) * gnst->max_siz);
		if (!gnst->dat)
			return (error_put(1, "gnst_new_resize : gnst->data NULL"));
	}
	else if (gnst->siz >= gnst->max_siz)
	{
		if (sub_gnst_resize(gnst))
		{
			gnst_free(gnst);
			return (1);
		}
	}
	return (0);
}
