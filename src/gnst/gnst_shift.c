/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnst_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:13:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:41 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gnst.h"

int	gnst_shift_down(t_gnst *gnst)
{
	long	i;

	if (!gnst)
		return (error_put(1, "gnst_shift_down : NULL gnst"));
	gnst->siz++;
	if (gnst_new_resize(gnst))
		return (error_put(1, "gnst_shift_down : gnst_new_resize() NULL data"));
	i = gnst->siz - 1;
	while (gnst->dat && i < gnst->siz && i >= 0)
	{
		gnst->dat[i + 1] = gnst->dat[i];
		i--;
	}
	return (0);
}

int	gnst_shift_up(t_gnst *gnst)
{
	long	i;

	if (!gnst)
		return (error_put(1, "gnst_shift_up : NULL gnst"));
	gnst->siz--;
	if (gnst_new_resize(gnst))
		return (error_put(1, "gnst_shift_up : gnst_new_resize() NULL data"));
	i = 0;
	while (gnst->dat && i < gnst->siz && i >= 0)
	{
		gnst->dat[i] = gnst->dat[i + 1];
		i++;
	}
	return (0);
}
