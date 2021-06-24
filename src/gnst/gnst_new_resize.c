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

#        include <stdio.h> //TODO REMOVE BEFORE PUSH

int	sub_gnst_resize(t_gnst *gnst)
{
	long	i;
	void	**copy;

	long long		siz;

	if (!gnst)
	{
		return (error_put(1, "sub_gnst_resize : gnst NULL"));
	}

	siz = sizeof(long) * gnst->siz * gnst_SIZ_MULT;

dprintf(2, "\n\033[32;1m===== siz %lld gnst->siz %ld\033[0m\n", siz, gnst->siz);

	copy = malloc(siz);
	if (!copy)
	{
		return (error_put(1, "sub_gnst_resize : copy NULL"));
	}
	i = 0;
	while (gnst && gnst->dat && i < gnst->siz)
	{

dprintf(2, "\ni %ld Copy[i %ld] <%p> gnst->dat[i %ld] <%p>\n", i, i, (void*)copy + (i * sizeof(copy[0])), i, (void*)gnst->dat + (i * sizeof(gnst->dat[0])));

		copy[i] = gnst->dat[i];
		i++;
	}

dprintf(2, "\n\nA gnst %p, ->dat %p\n", gnst, gnst->dat);

	if (gnst && gnst->dat)
	{
		// free(gnst->dat);
	}
	gnst->dat = NULL;
	gnst->dat = copy;
dprintf(2, "B gnst %p, ->dat %p\n", gnst, gnst->dat);
	gnst->max_siz = gnst->max_siz * gnst_SIZ_MULT;
	return (0);
}

int	gnst_new_resize(t_gnst *gnst)
{
	if (!gnst)
		return (error_put(1, "gnst_new_resize : NULL gnst"));
	if (gnst->dat == NULL)
	{
		gnst->max_siz = gnst_INIT_SIZ;
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
