/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnst_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gnst.h"

int	gnst_rotate(t_gnst *gnst)
{
	void	*tmp;

	if (!gnst)
		return (error_put(1, "gnst_rotate : NULL gnst"));
	tmp = gnst->dat[0];
	if (gnst_pop(gnst))
		return (error_put(1, "gnst_rotate : gnst_pop()"));
	if (gnst_push_back(gnst, tmp))
		return (error_put(1, "gnst_rotate : gnst_push_back()"));
	return (0);
}

int	gnst_rev_rotate(t_gnst *gnst)
{
	void	*tmp;

	if (!gnst)
		return (error_put(1, "gnst_rev_rotate : NULL gnst"));
	tmp = gnst->dat[gnst->siz - 1];
	if (gnst_pop_back(gnst))
		return (error_put(1, "gnst_rev_rotate : gnst_pop_back()"));
	if (gnst_push(gnst, tmp))
		return (error_put(1, "gnst_rev_rotate : gnst_push()"));
	return (0);
}
