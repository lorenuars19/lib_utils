/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnst_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:38:47 by lorenuar          #+#    #+#             */
/*   Updated: 2021/06/24 18:07:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gnst.h"

int	gnst_swap(t_gnst *gnst)
{
	void	*tmp;

	if (!gnst)
		return (error_put(1, "gnst_swap : NULL gnst"));
	if (gnst->siz > 1)
	{
		tmp = gnst->dat[0];
		gnst->dat[0] = gnst->dat[1];
		gnst->dat[1] = tmp;
	}
	return (0);
}
